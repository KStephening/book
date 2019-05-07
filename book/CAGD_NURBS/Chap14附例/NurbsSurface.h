// NurbsSurface.h : main header file for the NURBSSURFACE application
//

#if !defined(AFX_NURBSSURFACE_H__0663A645_0827_4F0C_8FCD_DFEFAC162902__INCLUDED_)
#define AFX_NURBSSURFACE_H__0663A645_0827_4F0C_8FCD_DFEFAC162902__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceApp:
// See NurbsSurface.cpp for the implementation of this class
//

class CNurbsSurfaceApp : public CWinApp
{
public:
	CNurbsSurfaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNurbsSurfaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNurbsSurfaceApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NURBSSURFACE_H__0663A645_0827_4F0C_8FCD_DFEFAC162902__INCLUDED_)
