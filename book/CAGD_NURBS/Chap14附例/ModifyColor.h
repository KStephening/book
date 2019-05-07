#if !defined(AFX_MODIFYCOLOR_H__C9F14062_49DD_4A77_9CC5_D2C615FA426A__INCLUDED_)
#define AFX_MODIFYCOLOR_H__C9F14062_49DD_4A77_9CC5_D2C615FA426A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModifyColor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ModifyColor dialog

class ModifyColor : public CDialog
{
// Construction
public:
	ModifyColor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ModifyColor)
	enum { IDD = IDD_MODIFY_COLOR };
	float	m_Blue;
	float	m_Green;
	float	m_Red;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ModifyColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ModifyColor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYCOLOR_H__C9F14062_49DD_4A77_9CC5_D2C615FA426A__INCLUDED_)
