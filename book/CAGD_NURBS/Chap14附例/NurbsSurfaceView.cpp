// NurbsSurfaceView.cpp : implementation of the CNurbsSurfaceView class
//

#include "stdafx.h"
#include "NurbsSurface.h"

#include "NurbsSurfaceDoc.h"
#include "NurbsSurfaceView.h"

#include "InputInnerWeight.h"
#include "ModifyRotation.h"
#include "ModifyColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView

IMPLEMENT_DYNCREATE(CNurbsSurfaceView, CView)

BEGIN_MESSAGE_MAP(CNurbsSurfaceView, CView)
	//{{AFX_MSG_MAP(CNurbsSurfaceView)
	ON_COMMAND(ID_SHOW_CTRLNET, OnShowCtrlnet)
	ON_UPDATE_COMMAND_UI(ID_SHOW_CTRLNET, OnUpdateShowCtrlnet)
	ON_COMMAND(ID_MODIFY_COLOR, OnModifyColor)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_COLOR, OnUpdateModifyColor)
	ON_COMMAND(ID_MODIFY_INNERWEIGHT, OnModifyInnerweight)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_INNERWEIGHT, OnUpdateModifyInnerweight)
	ON_COMMAND(ID_MODIFY_ROTATION, OnModifyRotation)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_ROTATION, OnUpdateModifyRotation)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView construction/destruction

CNurbsSurfaceView::CNurbsSurfaceView()
{
	// TODO: add construction code here
//	weight=0.0;
	ShowCtrlNet=false;
	weight=1.;
	degree=0.;
	xx=0.;
	yy=0.;
	zz=0.;
	Red=1.;
	Green=0.;
	Blue=0.;
}

CNurbsSurfaceView::~CNurbsSurfaceView()
{
}

BOOL CNurbsSurfaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView drawing

void CNurbsSurfaceView::OnDraw(CDC* pDC)
{
	CNurbsSurfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),1,                             
			PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER, 
			PFD_TYPE_RGBA,24,0,0,0,0,0,0,0,0,0,0,               
			0,0,0,32,0,0,PFD_MAIN_PLANE,0,0,0,0                                                
	};
	CClientDC clientdc(this);
	int pf=ChoosePixelFormat(clientdc.m_hDC,&pfd);
	BOOL rt=SetPixelFormat(clientdc.m_hDC,pf,&pfd);
	hglrc=wglCreateContext(clientdc.m_hDC);

	wglMakeCurrent(pDC->m_hDC,hglrc);

	glEnable(GL_BLEND);   //   打开混合 
    glDisable(GL_DEPTH_TEST);   //   关闭深度测试 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);   //   基于源象素alpha通道值的半透明混合函数
//	glColor4f(1.0,0.0,0.0,0.0);  //第四个参数为透明度值，0.0-完全透明，1-完全不透明。

	display();
	wglMakeCurrent(pDC->m_hDC,NULL);
	SwapBuffers(pDC->m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView printing

BOOL CNurbsSurfaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNurbsSurfaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNurbsSurfaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView diagnostics

#ifdef _DEBUG
void CNurbsSurfaceView::AssertValid() const
{
	CView::AssertValid();
}

void CNurbsSurfaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNurbsSurfaceDoc* CNurbsSurfaceView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNurbsSurfaceDoc)));
	return (CNurbsSurfaceDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceView message handlers
void CNurbsSurfaceView::display()
{
	GLfloat knots[8]={0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0};
	
	CRect clientRect;
	float ww,hh,scale;
    GetClientRect(clientRect);	
    ww=clientRect.right-clientRect.left;//屏幕宽度	
    hh=clientRect.bottom-clientRect.top;//屏幕高度
	scale=ww/hh;

	myinit();
	glPushMatrix();
		glRotatef(degree,xx,yy,zz);
		glScalef(0.2f/scale,0.2f,0.2f);

		gluBeginSurface(theNurb);
//			glColor4f(0.0,0.8,0.0,0.5);   //有光照不起作用，无光照才起作用
			glShadeModel(GL_SMOOTH); 
			gluNurbsSurface(theNurb,8,knots,8,knots,4*4,4,
							&ctlpoints[0][0][0],4,4,GL_MAP2_VERTEX_4);
		gluEndSurface(theNurb);
		int ii,jj;
		for(ii=1;ii<3;ii++)
		{
				for(jj=1;jj<3;jj++)
				{
					ctlpoints[ii][jj][0]=ctlpoints[ii][jj][0]/weight;
					ctlpoints[ii][jj][1]=ctlpoints[ii][jj][1]/weight;
					ctlpoints[ii][jj][2]=ctlpoints[ii][jj][2]/weight;
				}
		}
		if(ShowCtrlNet==true)
		{
			glBegin(GL_LINES);
			glColor4f(1.0,0.0,0.0,1.0);    //有光照不起作用，无光照才起作用
			glShadeModel(GL_FLAT); 
			for(ii=0;ii<4;ii++)
				for(jj=0;jj<3;jj++)
				{
					glVertex3fv(&ctlpoints[ii][jj][0]);
					glVertex3fv(&ctlpoints[ii][jj+1][0]);
				}
			for(jj=0;jj<4;jj++)
				for(ii=0;ii<3;ii++)			
				{
					glVertex3fv(&ctlpoints[ii][jj][0]);
					glVertex3fv(&ctlpoints[ii+1][jj][0]);
				}
			glEnd();
		}
	glPopMatrix();
	glFlush();	
}

void CNurbsSurfaceView::myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glMap2f(GL_MAP2_VERTEX_4,0,1,3,4,0,1,12,4,&ctlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_4);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	theNurb=gluNewNurbsRenderer();
	initsurface();
	initlights();
}

void CNurbsSurfaceView::initsurface()
{
	int u,v;
	for(v=0;v<4;v++)
	{
		for(u=0;u<4;u++)
		{
			ctlpoints[u][v][0]=2.0*((GLfloat)u-1.5);
			ctlpoints[u][v][1]=2.0*((GLfloat)v-1.5);
			if((u==1||u==2)&&(v==1||v==2))
			{
				ctlpoints[u][v][2]=weight*3.0;
				ctlpoints[u][v][0]=weight*ctlpoints[u][v][0];
				ctlpoints[u][v][1]=weight*ctlpoints[u][v][1];
				ctlpoints[u][v][3]=weight;
			}
			else
			{
				ctlpoints[u][v][2]=-3.0;
				ctlpoints[u][v][3]=1.;
			}
		}
	}
}

void CNurbsSurfaceView::initlights()
{		
	GLfloat mat_diffuse[]={0.7f,0.7f,0.7f,1.0f};
//	GLfloat mat_diffuse[]={Red,Green,Blue,1.0f};
//	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={100.0f};
	
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
//	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	
	GLfloat AmbientLight[4]={Red,Green,Blue,1};
	glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);

	GLfloat LightPosition[4]={1.,1.,1.,-1};  //LightPosition[3]=-1的时候，表示光源位于距离场景无限远的地方，无论前面设置的X,Y,Z是什么值。
	glLightfv(GL_LIGHT0,GL_POSITION,LightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void CNurbsSurfaceView::OnShowCtrlnet() 
{
	// TODO: Add your command handler code here
	CNurbsSurfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(ShowCtrlNet==false) ShowCtrlNet=true;
	else ShowCtrlNet=false;
	pDoc->UpdateAllViews(NULL);
}

void CNurbsSurfaceView::OnUpdateShowCtrlnet(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(TRUE);
}

void CNurbsSurfaceView::OnModifyColor() 
{
	// TODO: Add your command handler code here
	CNurbsSurfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	ModifyColor dlg;
	dlg.m_Red=Red;
	dlg.m_Green=Green;
	dlg.m_Blue=Blue;
	if(dlg.DoModal()==IDOK)
	{
		Red=dlg.m_Red;
		Green=dlg.m_Green;
		Blue=dlg.m_Blue;
	}
	else return;
	pDoc->UpdateAllViews(NULL);
}

void CNurbsSurfaceView::OnUpdateModifyColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(TRUE);
}

void CNurbsSurfaceView::OnModifyInnerweight() 
{
	// TODO: Add your command handler code here
	CNurbsSurfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	InputInnerWeight dlg;
	dlg.m_weight=weight;
	if(dlg.DoModal()==IDOK)
	{
		weight=dlg.m_weight;
	}
	else return;
	pDoc->UpdateAllViews(NULL);
}

void CNurbsSurfaceView::OnUpdateModifyInnerweight(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(TRUE);
}

void CNurbsSurfaceView::OnModifyRotation() 
{
	// TODO: Add your command handler code here
	CNurbsSurfaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	ModifyRotation dlg;
	dlg.m_degree=degree;
	dlg.m_xValue=xx;
	dlg.m_yValue=yy;
	dlg.m_zValue=zz;
	if(dlg.DoModal()==IDOK)
	{
		degree=dlg.m_degree;
		xx=dlg.m_xValue;
		yy=dlg.m_yValue;
		zz=dlg.m_zValue;
	}
	else return;
	pDoc->UpdateAllViews(NULL);
}

void CNurbsSurfaceView::OnUpdateModifyRotation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(TRUE);
}
