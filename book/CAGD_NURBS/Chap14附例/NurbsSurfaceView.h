// NurbsSurfaceView.h : interface of the CNurbsSurfaceView class
//
#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"
#include "glut.h"
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NURBSSURFACEVIEW_H__D2FE82B2_7543_451E_971E_8E159A96BE41__INCLUDED_)
#define AFX_NURBSSURFACEVIEW_H__D2FE82B2_7543_451E_971E_8E159A96BE41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNurbsSurfaceView : public CView
{
protected: // create from serialization only
	CNurbsSurfaceView();
	DECLARE_DYNCREATE(CNurbsSurfaceView)

// Attributes
public:
	CNurbsSurfaceDoc* GetDocument();

// Operations
public:
	HGLRC hglrc;
	float weight;
	bool ShowCtrlNet;
	float degree,xx,yy,zz;
	float Red,Green,Blue;
	
	void initsurface();
	void initlights();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNurbsSurfaceView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNurbsSurfaceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	GLfloat ctlpoints[4][4][4];
	GLUnurbsObj *theNurb;
	void myinit(void);
	void display(void);
	//{{AFX_MSG(CNurbsSurfaceView)
	afx_msg void OnShowCtrlnet();
	afx_msg void OnUpdateShowCtrlnet(CCmdUI* pCmdUI);
	afx_msg void OnModifyColor();
	afx_msg void OnUpdateModifyColor(CCmdUI* pCmdUI);
	afx_msg void OnModifyInnerweight();
	afx_msg void OnUpdateModifyInnerweight(CCmdUI* pCmdUI);
	afx_msg void OnModifyRotation();
	afx_msg void OnUpdateModifyRotation(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NurbsSurfaceView.cpp
inline CNurbsSurfaceDoc* CNurbsSurfaceView::GetDocument()
   { return (CNurbsSurfaceDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NURBSSURFACEVIEW_H__D2FE82B2_7543_451E_971E_8E159A96BE41__INCLUDED_)
