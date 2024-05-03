#pragma once
#include "pch.h"
#include "resource.h"
#include "Snake.h"

class CSnakeWnd : public CWnd
{
public:
	CSnakeWnd();

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	HICON m_hIcon;
public:
	afx_msg BOOL Create(LPCTSTR title, CRect rect, CWnd* pParent, uint16_t fps, uint16_t tps);
protected:
	afx_msg void OnTimer(UINT_PTR timer);
	afx_msg BOOL OnCreate();
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
private:
	Snake snake;

	void Update();
};
