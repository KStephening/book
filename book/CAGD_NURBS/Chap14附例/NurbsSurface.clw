; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNurbsSurfaceView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NurbsSurface.h"
LastPage=0

ClassCount=8
Class1=CNurbsSurfaceApp
Class2=CNurbsSurfaceDoc
Class3=CNurbsSurfaceView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_MODIFY_COLOR
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDD_MODIFY_ROTATON
Resource4=IDR_MAINFRAME
Class6=InputInnerWeight
Class7=ModifyColor
Class8=ModifyRotation
Resource5=IDD_MODIFY_INNERWEIGHT

[CLS:CNurbsSurfaceApp]
Type=0
HeaderFile=NurbsSurface.h
ImplementationFile=NurbsSurface.cpp
Filter=N

[CLS:CNurbsSurfaceDoc]
Type=0
HeaderFile=NurbsSurfaceDoc.h
ImplementationFile=NurbsSurfaceDoc.cpp
Filter=N

[CLS:CNurbsSurfaceView]
Type=0
HeaderFile=NurbsSurfaceView.h
ImplementationFile=NurbsSurfaceView.cpp
Filter=C
LastObject=ID_MODIFY_ROTATION
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SHOW_CTRLNET




[CLS:CAboutDlg]
Type=0
HeaderFile=NurbsSurface.cpp
ImplementationFile=NurbsSurface.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_SHOW_CTRLNET
Command17=ID_MODIFY_INNERWEIGHT
Command18=ID_MODIFY_ROTATION
Command19=ID_MODIFY_COLOR
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_MODIFY_ROTATON]
Type=1
Class=ModifyRotation
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_XVALUE,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_YVALUE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ZVALUE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ANGLE,edit,1350631552

[DLG:IDD_MODIFY_COLOR]
Type=1
Class=ModifyColor
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_RED,edit,1350631552
Control6=IDC_GREEN,edit,1350631552
Control7=IDC_BLUE,edit,1350631552

[DLG:IDD_MODIFY_INNERWEIGHT]
Type=1
Class=InputInnerWeight
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_WEIGHT,edit,1350631552

[CLS:InputInnerWeight]
Type=0
HeaderFile=InputInnerWeight.h
ImplementationFile=InputInnerWeight.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:ModifyColor]
Type=0
HeaderFile=ModifyColor.h
ImplementationFile=ModifyColor.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:ModifyRotation]
Type=0
HeaderFile=ModifyRotation.h
ImplementationFile=ModifyRotation.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

