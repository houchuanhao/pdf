
// 0141124825_houchuanhaoDlg.h : ͷ�ļ�
//

#pragma once

#include<Mmsystem.h>

#include<direct.h>
#include "afxwin.h"
// CMy0141124825_houchuanhaoDlg �Ի���
class CMy0141124825_houchuanhaoDlg : public CDialogEx
{
// ����
public:
	//--------------------
	int sumtime = 900;
	//****************
	CMy0141124825_houchuanhaoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY0141124825_HOUCHUANHAO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	CString now_iPos; //������ǰѡ�е��е�ֵ
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
	bool judge(CString exid,CString id); //�ж�׼��֤�ź����֤���Ƿ���ȷ

	//*******************************************************
	void Output_pdf(CString id_number, CString exam_number, double accuracy_rate, double typing_speed, double score, CString content);
	//CString getPath(); //��ȡ·��
    CString readIni(CString iniPath, CString path); //��ȡ�����ļ�
	void play(CString musicPath); //��������
	void stop(); //ֹͣ��������
	CString decode(CString answer); //���𰸽���
	double getScore(); //��ȡ�ɼ�
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
