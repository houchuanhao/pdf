
// 0141124825_houchuanhao.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0141124825_houchuanhaoApp: 
// �йش����ʵ�֣������ 0141124825_houchuanhao.cpp
//

class CMy0141124825_houchuanhaoApp : public CWinApp
{
public:
	CMy0141124825_houchuanhaoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0141124825_houchuanhaoApp theApp;