// NurbsSurfaceDoc.cpp : implementation of the CNurbsSurfaceDoc class
//

#include "stdafx.h"
#include "NurbsSurface.h"

#include "NurbsSurfaceDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceDoc

IMPLEMENT_DYNCREATE(CNurbsSurfaceDoc, CDocument)

BEGIN_MESSAGE_MAP(CNurbsSurfaceDoc, CDocument)
	//{{AFX_MSG_MAP(CNurbsSurfaceDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceDoc construction/destruction

CNurbsSurfaceDoc::CNurbsSurfaceDoc()
{
	// TODO: add one-time construction code here

}

CNurbsSurfaceDoc::~CNurbsSurfaceDoc()
{
}

BOOL CNurbsSurfaceDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceDoc serialization

void CNurbsSurfaceDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceDoc diagnostics

#ifdef _DEBUG
void CNurbsSurfaceDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNurbsSurfaceDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNurbsSurfaceDoc commands
