// ModifyColor.cpp : implementation file
//

#include "stdafx.h"
#include "NurbsSurface.h"
#include "ModifyColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModifyColor dialog


ModifyColor::ModifyColor(CWnd* pParent /*=NULL*/)
	: CDialog(ModifyColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(ModifyColor)
	m_Blue = 0.0f;
	m_Green = 0.0f;
	m_Red = 0.0f;
	//}}AFX_DATA_INIT
}


void ModifyColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModifyColor)
	DDX_Text(pDX, IDC_BLUE, m_Blue);
	DDV_MinMaxFloat(pDX, m_Blue, 0.f, 1.f);
	DDX_Text(pDX, IDC_GREEN, m_Green);
	DDV_MinMaxFloat(pDX, m_Green, 0.f, 1.f);
	DDX_Text(pDX, IDC_RED, m_Red);
	DDV_MinMaxFloat(pDX, m_Red, 0.f, 1.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModifyColor, CDialog)
	//{{AFX_MSG_MAP(ModifyColor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModifyColor message handlers
