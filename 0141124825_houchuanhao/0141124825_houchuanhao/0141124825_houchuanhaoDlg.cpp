
// 0141124825_houchuanhaoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0141124825_houchuanhao.h"
#include "0141124825_houchuanhaoDlg.h"
#include<Mmsystem.h>

#include<direct.h>

#pragma   comment(lib, "winmm.lib")

#include<stdio.h>
#include<string>
#include<cstring>
//#include "afxdialogex.h"
#include "pdflib.h"

#pragma   comment(lib, "winmm.lib")

#pragma  comment(lib, "pdflib.lib") 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy0141124825_houchuanhaoDlg 对话框



CMy0141124825_houchuanhaoDlg::CMy0141124825_houchuanhaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy0141124825_houchuanhaoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	now_iPos = "1";
}

void CMy0141124825_houchuanhaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy0141124825_houchuanhaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy0141124825_houchuanhaoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0141124825_houchuanhaoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy0141124825_houchuanhaoDlg 消息处理程序

BOOL CMy0141124825_houchuanhaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy0141124825_houchuanhaoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy0141124825_houchuanhaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy0141124825_houchuanhaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//------------------------------------------------------------------------------------------------------------------------
DWORD CMy0141124825_houchuanhaoDlg::getinfo(UINT wDeviceID, DWORD item)
{
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback = (DWORD)GetSafeHwnd();
	mcistatusparms.dwItem = item;
	mcistatusparms.dwReturn = 0;
	mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;
}
void CMy0141124825_houchuanhaoDlg::Output_pdf(CString id_number, CString exam_number, double accuracy_rate, double typing_speed, double score, CString content)
{

	remove("成绩单.pdf");

	PDF *p;
	//PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//去除水印。将注册号写入。

	if ((p = PDF_new()) == (PDF *)0){
		printf("Couldn't create PDFlib object (out of memory)!/n");
		return;
	}

	PDF_TRY(p) {
		/* This means we must check return values of load_font() etc. */
		//PDF_set_parameter(p, "errorpolicy", "return");
		USES_CONVERSION;
		PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//去除水印。将注册号写入。

		CString str(exam_number);
		CString str2 = "_成绩单.pdf";

		CString str1 = str + str2;
		const char *FileName = str1;
		if (PDF_begin_document(p, FileName, 0, "") == -1) {
			printf("Error: %s/n", PDF_get_errmsg(p));
			return;
		}

		/* This line is required to avoid problems on Japanese systems */
		PDF_set_parameter(p, "hypertextencoding", "host");
		//PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//去除水印。将注册号写入。

		//PDF_set_parameter(p, "fakebold", "true");



		PDF_set_info(p, "Creator", "041122374.cpp");
		PDF_set_info(p, "Author", "Zyzzz");
		PDF_set_info(p, "Title", "Hello, world !");

		PDF_begin_page_ext(p, a4_width, a4_height, "");

		int font_song = PDF_findfont(p, "STSong-Light", "GB-EUC-H", 0);
		PDF_setfont(p, font_song, 12);
		PDF_set_text_pos(p, 50, a4_height - 50);



		//USES_CONVERSION;
		CString s = T2A((id_number.GetBuffer()));
		s = "身份证号：" + s;
		PDF_show(p, s);

		PDF_set_text_pos(p, 50, a4_height - 65);
		s = T2A((exam_number.GetBuffer()));
		s = "准考证号：" + s;
		PDF_show(p, s);

		PDF_setfont(p, font_song, 8);
		PDF_set_text_pos(p, 50, a4_height - 85);
		CString cs;
		cs.Format("您打字的正确率是%f，速度是%f字/分钟，本次考试的成绩是%f分", accuracy_rate, typing_speed, score);
		s = T2A(cs.GetBuffer());
		PDF_show(p, s);

		PDF_setfont(p, font_song, 8);
		PDF_set_text_pos(p, 50, a4_height - 100);
		s = "以下是您本次考试录入的内容:";
		PDF_show(p, s);

		PDF_set_text_pos(p, 50, a4_height - 130);
		s = T2A(content.GetBuffer());
		PDF_show(p, s);
		//PDF_setcolor(p, "fill", "cmyk", 1, 0,0,0);
		//PDF_rect(p, 250,250, 250, 250);
		//PDF_fill(p);

		PDF_end_page_ext(p, "");
		PDF_end_document(p, "");
	}

	PDF_CATCH(p) {
		printf("PDFlib exception occurred in sample:/n");
		printf("[%d] %s: %s/n",
			PDF_get_errnum(p), PDF_get_apiname(p), PDF_get_errmsg(p));
		CString cs;
		cs.Format("[%d] %s: %s/n",
			PDF_get_errnum(p), PDF_get_apiname(p), PDF_get_errmsg(p));
		PDF_delete(p);

		return;
	}
	PDF_delete(p);
	return;
}
void CMy0141124825_houchuanhaoDlg::play()  //
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here
	DWORD cdlen;//音频文件长度
	op.dwCallback = NULL;
	op.lpstrAlias = NULL;
	op.lpstrDeviceType = _T("MPEGAudio");  //设备类型，大多数文件可以这样设置 
	//op.lpstrElementName = "C:\\WINDOWS\\Media\\Alarm02.wav"; //文件路径 
	CString str = getPath() + aduio_format + "\\" + now_iPos + "\\" + now_iPos + "." + aduio_format;


	MessageBox(str);
	op.lpstrElementName = str; //文件路径 
	op.wDeviceID = NULL;      //打开设备成功以后保存这个设备号备用 
	UINT rs;        //接受函数返回结果 
	//发送命令打开设备，成功返回0，否则返回错误号，第三个参数这里必须MCI_OPEN_ELEMENT  
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&op);
	mciSendCommand(NULL, MCI_SET, MCI_SET_DOOR_OPEN, NULL);
	cdlen = getinfo(op.wDeviceID, MCI_STATUS_LENGTH);//获取音频文件长度
	int length = int(cdlen) / 1000 + 1;
	sumtime = length;
	int a = int(cdlen);
	if (rs == 0)        //设备打开成功就播放文件 
	{
		MCI_PLAY_PARMS pp;
		pp.dwCallback = NULL;
		pp.dwFrom = 0;      //开始播放的位置 
		mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&pp);
		//播放文件，如果第三个参数设为MCI_WAIT则程序窗口会被阻塞，为了避免这种情况可以设为MCI_NOTIFY 
	}
}
void CMy0141124825_houchuanhaoDlg::Stop()
{
	MCI_GENERIC_PARMS gp;
	gp.dwCallback = NULL;
	mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD)&gp);
}
CString CMy0141124825_houchuanhaoDlg::getPath()
{
	char strModule[256];
	GetModuleFileName(NULL, strModule, 256); //得到当前模块路径

	CString str = CString(strModule);
	int l = str.GetLength();


	for (int i = l - 1; i > 0; i--)
	{

		if (str[i] != 92)
		{
			str = str.Left(i);
		}
		else{
			break;
		}
	}

	return str;
}


























//---------------
void CMy0141124825_houchuanhaoDlg::OnBnClickedButton2()
{
	Output_pdf("111", "qqq", 12, 12, 12, "12345");
	// TODO:  在此添加控件通知处理程序代码
	Stop();
}


void CMy0141124825_houchuanhaoDlg::OnBnClickedButton1()
{
	play();
	// TODO:  在此添加控件通知处理程序代码
}
