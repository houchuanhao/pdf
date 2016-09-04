
// 0141124825_houchuanhaoDlg.h : 头文件
//

#pragma once

#include<Mmsystem.h>

#include<direct.h>
#include "afxwin.h"
// CMy0141124825_houchuanhaoDlg 对话框
class CMy0141124825_houchuanhaoDlg : public CDialogEx
{
// 构造
public:
	//--------------------
	int sumtime = 900;
	//****************
	CMy0141124825_houchuanhaoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY0141124825_HOUCHUANHAO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int maxtime;
	float accurate;
	float myspeed;
	float Score;
	CString getPath();
	CString readIni(CString str);
	float get_score(CString str1, CString str2);
	CString getAnswer();
	bool open = 0;
	void loade();
	CString now_iPos; //下拉框当前选中的行的值
	CString song;
	int total_minutes = 15;
	int total_questions = 5;
	CString aduio_format = _T("mp3");
	int max_speed = 100;
	double percentage_accuracy = 0.7000;
	double percentage_speed = 0.3000;
	MCI_OPEN_PARMS op;
	void play();
	void Stop();
	HWND m_hWnd;
	DWORD DeviceId;
	MCI_OPEN_PARMS mciopenparms;
	DWORD getinfo(UINT wDeviceID, DWORD item);
	void Load(HWND hWnd, CString strFilepath);
	bool judge(CString exid,CString id); //判断准考证号和身份证号是否正确

	//*******************************************************
	void Output_pdf(CString id_number, CString exam_number, double accuracy_rate, double typing_speed, double score, CString content);
	//CString getPath(); //获取路径
    CString readIni(CString iniPath, CString path); //读取配置文件
	void play(CString musicPath); //播放音乐
	void stop(); //停止播放音乐
	CString decode(CString answer); //给答案解码
	double getScore(); //获取成绩
	//------------------------------------------------------
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStatic1();
	CStatic last_time;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit3();
	CString exid;
	CString id;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo3();
//	CString myanswer;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnStnClickedStatic4();
	CString myanswer;
};
