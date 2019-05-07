// InputInnerWeight.cpp : implementation file
//

#include "stdafx.h"
#include "NurbsSurface.h"
#include "InputInnerWeight.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputInnerWeight dialog


InputInnerWeight::InputInnerWeight(CWnd* pParent /*=NULL*/)
	: CDialog(InputInnerWeight::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputInnerWeight)
	m_weight = 0.0f;
	//}}AFX_DATA_INIT
}


void InputInnerWeight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputInnerWeight)
	DDX_Text(pDX, IDC_WEIGHT, m_weight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InputInnerWeight, CDialog)
	//{{AFX_MSG_MAP(InputInnerWeight)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputInnerWeight message handlers
