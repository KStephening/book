// NurbsSurfaceDoc.h : interface of the CNurbsSurfaceDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NURBSSURFACEDOC_H__39E7F840_E8D3_4E6C_84D8_0A8BD87AF6DF__INCLUDED_)
#define AFX_NURBSSURFACEDOC_H__39E7F840_E8D3_4E6C_84D8_0A8BD87AF6DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNurbsSurfaceDoc : public CDocument
{
protected: // create from serialization only
	CNurbsSurfaceDoc();
	DECLARE_DYNCREATE(CNurbsSurfaceDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNurbsSurfaceDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNurbsSurfaceDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNurbsSurfaceDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NURBSSURFACEDOC_H__39E7F840_E8D3_4E6C_84D8_0A8BD87AF6DF__INCLUDED_)
