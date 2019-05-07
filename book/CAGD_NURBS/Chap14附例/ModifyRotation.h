#if !defined(AFX_MODIFYROTATION_H__5E10D2A4_C66C_491C_8F9D_13DD7D67255A__INCLUDED_)
#define AFX_MODIFYROTATION_H__5E10D2A4_C66C_491C_8F9D_13DD7D67255A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModifyRotation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ModifyRotation dialog

class ModifyRotation : public CDialog
{
// Construction
public:
	ModifyRotation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ModifyRotation)
	enum { IDD = IDD_MODIFY_ROTATON };
	float	m_degree;
	float	m_xValue;
	float	m_yValue;
	float	m_zValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ModifyRotation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ModifyRotation)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYROTATION_H__5E10D2A4_C66C_491C_8F9D_13DD7D67255A__INCLUDED_)
