
// 0141124825_houchuanhaoDlg.h : ͷ�ļ�
//

#pragma once


// CMy0141124825_houchuanhaoDlg �Ի���
class CMy0141124825_houchuanhaoDlg : public CDialogEx
{
// ����
public:
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
	void Output_pdf(CString id_number, CString exam_number, double accuracy_rate, double typing_speed, double score, CString content);
	CString getPath(); //��ȡ·��
    CString readIni(CString iniPath, CString path); //��ȡ�����ļ�
	void play(CString musicPath); //��������
	void stop(); //ֹͣ��������
	CString decode(CString answer); //���𰸽���
	double getScore(); //��ȡ�ɼ�
	//------------------------------------------------------
	afx_msg void OnBnClickedButton2();
};
