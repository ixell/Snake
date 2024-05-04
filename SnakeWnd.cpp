#include "pch.h"
#include "framework.h"
#include "SnakeApp.h"
#include "SnakeWnd.h"

#include "SnakeWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UPDATE_TIMER 0

CSnakeWnd::CSnakeWnd()
	: CWnd(), m_hIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME)),
	  snake(2, 2, Snake::right, 10), apple(0, 0) {
	snake.set_limits(20, 20);
	apple.set_limits(20, 20);
}

void CSnakeWnd::DoDataExchange(CDataExchange* pDX) {
	CWnd::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSnakeWnd, CWnd)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


void CSnakeWnd::OnDestroy() {
	KillTimer(UPDATE_TIMER);
	UnregisterClass("SnakeWnd", AfxGetApp()->m_hInstance);
	CWnd::OnDestroy();
	AfxGetApp()->SaveAllModified();
}

void CSnakeWnd::OnClose() {
	CWnd::OnClose();
}

void CSnakeWnd::OnTimer(UINT_PTR timer) {
	switch (timer) {
	case UPDATE_TIMER:
		Update();
		RedrawWindow();
		break;
	}
}

BOOL CSnakeWnd::OnCreate() {
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}

void CSnakeWnd::OnPaint() {
	CPaintDC dc(this);
	if (IsIconic()) {
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else {
		CRect rect;
		GetClientRect(&rect);
		int w = rect.Width() / snake.get_limit_x();
		int h = rect.Height() / snake.get_limit_y();
		for (SnakeBlock* block = snake.getHead();
				block != nullptr; block = block->getFollowing()) {
			rect.left	= block->get_x() * w;
			rect.top	= block->get_y() * h;
			rect.right	= rect.left + w;
			rect.bottom	= rect.top + h;
			dc.FillSolidRect(static_cast<LPCRECT>(&rect), 0x80ff80/*green*/);
		}
		rect.left	= apple.get_x() * w;
		rect.top	= apple.get_y() * h;
		rect.right	= rect.left + w;
		rect.bottom = rect.top + h;
		dc.FillSolidRect(static_cast<LPCRECT>(&rect), 0x4040ff/*red*/);
	}
}

HCURSOR CSnakeWnd::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}

void CSnakeWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	switch (nChar) {
	case VK_UP:
	case 'W':
		snake.change_direction(Snake::up);
		return;
	case VK_LEFT:
	case 'A':
		snake.change_direction(Snake::left);
		return;
	case VK_DOWN:
	case 'S':
		snake.change_direction(Snake::down);
		return;
	case VK_RIGHT:
	case 'D':
		snake.change_direction(Snake::right);
		return;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSnakeWnd::Update() {
	snake.update();
	snake.try_eat(apple);
}

BOOL CSnakeWnd::Create(LPCTSTR title, CRect rect, CWnd* pParent, uint16_t fps, uint16_t tps) {
	WNDCLASSA wc;
	memset(&wc, 0, sizeof(WNDCLASSA));

	wc.style = 0;
	wc.lpfnWndProc = ::DefWindowProc;
	wc.hInstance = AfxGetInstanceHandle();
	wc.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	wc.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "SnakeWnd";

	if (!RegisterClass(&wc)) {
		DWORD dwError = GetLastError();
		if (dwError != ERROR_CLASS_ALREADY_EXISTS) {
			TRACE("Class Registration Failed\n");
			return FALSE;
		}
	}

	AdjustWindowRect(
		&rect,
		WS_OVERLAPPEDWINDOW,
		FALSE
	);

	if (!
		CWnd::CreateEx (
			0,
			"SnakeWnd",
			title,
			WS_OVERLAPPEDWINDOW,
			rect,
			pParent,
			0
		)
	) {
		TRACE("Class Creation Failed\n");
		return FALSE;
	}

	SetTimer(UPDATE_TIMER, (1000U / tps), (TIMERPROC)NULL);

	//SetCursor(AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_ARROW)));
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	return TRUE;
}
