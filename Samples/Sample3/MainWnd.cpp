/*
作者： b2b160
日期： 2011-03-07
功能： IM登陆窗口界面例子
*/

#include "stdafx.h"
#include ".\mainwnd.h"


CMainWnd::CMainWnd(void) : CKuiDialogImpl<CMainWnd>( "IDR_DLG_MAIN" )
, m_nCurProgress( 30 )
{
}

CMainWnd::~CMainWnd(void)
{
}

LRESULT CMainWnd::OnInitDialog( HWND hDlg, LPARAM lParam )
{
	if( m_ctlUserName.Create( GetRichWnd(), NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER ) )
		m_ctlUserName.SetDlgCtrlID( 2 );
	if( m_ctlUserPass.Create( GetRichWnd(), NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD ) )
		m_ctlUserPass.SetDlgCtrlID( 3 );
	SetTimer( 1, 80 );
	return TRUE;
}

void CMainWnd::OnDestroy()
{
	KillTimer( 1 );
    PostQuitMessage(0);
}


void CMainWnd::OnBkBtnMax()
{
	if (WS_MAXIMIZE == (GetStyle() & WS_MAXIMIZE))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE | HTCAPTION, 0);
	}
	else
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE | HTCAPTION, 0);
	}
}

void CMainWnd::OnBkBtnMin()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE | HTCAPTION, 0);
}

void CMainWnd::OnBkBtnClose()
{
	DestroyWindow();
}

void CMainWnd::OnNotify( UINT nID, LPCSTR pClassName )
{
	CString str;
	str.Format( _T("Item Notify.ID:%d, Item Type:%s"), nID, pClassName );
	SetItemText( 2, str );
}

void CMainWnd::OnAdd()
{
	m_nCurProgress += 10;
	if( m_nCurProgress>100 )
		m_nCurProgress = 0;
	SetItemIntAttribute( 8, "value", m_nCurProgress );

}

void CMainWnd::OnDec()
{
	m_nCurProgress -= 10;
	if( m_nCurProgress<0 )
		m_nCurProgress = 100;
	SetItemIntAttribute( 8, "value", m_nCurProgress );
}

void CMainWnd::OnTimer(UINT_PTR nIDEvent)
{
    static int nFrame = 0;
    SetItemIntAttribute( 11, "sub", nFrame++);
    if (nFrame > 5)
        nFrame = 0;
}