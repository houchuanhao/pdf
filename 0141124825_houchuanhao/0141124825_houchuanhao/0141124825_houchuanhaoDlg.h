
// 0141124825_houchuanhaoDlg.h : 头文件
//

#pragma once


// CMy0141124825_houchuanhaoDlg 对话框
class CMy0141124825_houchuanhaoDlg : public CDialogEx
{
// 构造
public:
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
	void Output_pdf(CString id_number, CString exam_number, double accuracy_rate, double typing_speed, double score, CString content);
	CString getPath(); //获取路径
    CString readIni(CString iniPath, CString path); //读取配置文件
	void play(CString musicPath); //播放音乐
	void stop(); //停止播放音乐
	CString decode(CString answer); //给答案解码
	double getScore(); //获取成绩
	//------------------------------------------------------
	afx_msg void OnBnClickedButton2();
};
