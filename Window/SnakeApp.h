
// Snake.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"

class CSnakeApp : public CWinApp {
public:
	CSnakeApp();
public:
	virtual BOOL InitInstance() override;
	virtual BOOL SaveAllModified() override;

	DECLARE_MESSAGE_MAP();
};

extern CSnakeApp theApp;
