// ModifyRotation.cpp : implementation file
//

#include "stdafx.h"
#include "NurbsSurface.h"
#include "ModifyRotation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModifyRotation dialog


ModifyRotation::ModifyRotation(CWnd* pParent /*=NULL*/)
	: CDialog(ModifyRotation::IDD, pParent)
{
	//{{AFX_DATA_INIT(ModifyRotation)
	m_degree = 0.0f;
	m_xValue = 0.0f;
	m_yValue = 0.0f;
	m_zValue = 0.0f;
	//}}AFX_DATA_INIT
}


void ModifyRotation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModifyRotation)
	DDX_Text(pDX, IDC_ANGLE, m_degree);
	DDV_MinMaxFloat(pDX, m_degree, -360.f, 360.f);
	DDX_Text(pDX, IDC_XVALUE, m_xValue);
	DDX_Text(pDX, IDC_YVALUE, m_yValue);
	DDX_Text(pDX, IDC_ZVALUE, m_zValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModifyRotation, CDialog)
	//{{AFX_MSG_MAP(ModifyRotation)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModifyRotation message handlers
