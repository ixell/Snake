#include "pch.h"
#include "framework.h"
#include "SnakeApp.h"
#include "SnakeWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeApp

BEGIN_MESSAGE_MAP(CSnakeApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CSnakeApp::CSnakeApp() {
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CSnakeApp theApp;

BOOL CSnakeApp::InitInstance() {
	// InitCommonControlsEx() требуется для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	//INITCOMMONCONTROLSEX InitCtrls;
	//InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	//InitCtrls.dwICC = ICC_WIN95_CLASSES;
	//InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	//AfxEnableControlContainer();

	SetRegistryKey(_T("-"));

	CSnakeWnd* wnd = new CSnakeWnd;
	if (!wnd->Create("Snake", CRect(100, 100, 640, 640), nullptr, 8, 8))
		return FALSE;
	m_pMainWnd = static_cast<CWnd*>(wnd);
	wnd->ShowWindow(SW_SHOW);
	wnd->EnableWindow(TRUE);

	return TRUE;
}

BOOL CSnakeApp::SaveAllModified() {
	delete (CSnakeWnd*)m_pMainWnd;
	return TRUE;
}
