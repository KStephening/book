#if !defined(AFX_INPUTINNERWEIGHT_H__D4729250_F13C_437E_9B1A_ABD328F96649__INCLUDED_)
#define AFX_INPUTINNERWEIGHT_H__D4729250_F13C_437E_9B1A_ABD328F96649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputInnerWeight.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputInnerWeight dialog

class InputInnerWeight : public CDialog
{
// Construction
public:
	InputInnerWeight(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputInnerWeight)
	enum { IDD = IDD_MODIFY_INNERWEIGHT };
	float	m_weight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputInnerWeight)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputInnerWeight)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTINNERWEIGHT_H__D4729250_F13C_437E_9B1A_ABD328F96649__INCLUDED_)
