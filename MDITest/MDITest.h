
// MDITest.h : MDITest ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMDITestApp:
// �� Ŭ������ ������ ���ؼ��� MDITest.cpp�� �����Ͻʽÿ�.
//

class CMDITestApp : public CWinApp
{
public:
	CMDITestApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDITestApp theApp;
