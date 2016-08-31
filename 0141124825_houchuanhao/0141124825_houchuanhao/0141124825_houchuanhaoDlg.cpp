
// 0141124825_houchuanhaoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0141124825_houchuanhao.h"
#include "0141124825_houchuanhaoDlg.h"
#include<Mmsystem.h>
#include<string>
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
using namespace std;

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
public:
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy0141124825_houchuanhaoDlg 对话框



CMy0141124825_houchuanhaoDlg::CMy0141124825_houchuanhaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy0141124825_houchuanhaoDlg::IDD, pParent)
	, exid(_T(""))
	, id(_T(""))
	, myanswer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//---------------------
	now_iPos = "1";
	//SetTimer(1, 1000, 0);

}

void CMy0141124825_houchuanhaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_STATIC1, last_time);
	DDX_Text(pDX, IDC_EDIT1, exid);
	DDV_MaxChars(pDX, exid, 8);
	DDX_Text(pDX, IDC_EDIT2, id);

	//----------------
	loade();
	if (open == 0)
	{
		//设置激活状态
		CButton *pBtn = (CButton *)GetDlgItem(IDC_BUTTON2);
		pBtn->EnableWindow(FALSE);
		pBtn = (CButton *)GetDlgItem(IDC_BUTTON3);
		pBtn->EnableWindow(FALSE);
		pBtn = (CButton *)GetDlgItem(IDC_EDIT3);
		pBtn->EnableWindow(FALSE);
		//----------------
		CString strTemp;
		((CComboBox*)GetDlgItem(IDC_COMBO1))->ResetContent();//消除现有所有内容
		for (int i = 1; i <= total_questions; i++)
		{
			strTemp.Format("%d", i);
			((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(strTemp);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
		open = 1;
	}
	DDX_Text(pDX, IDC_EDIT3, myanswer);
}

BEGIN_MESSAGE_MAP(CMy0141124825_houchuanhaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy0141124825_houchuanhaoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0141124825_houchuanhaoDlg::OnBnClickedButton1)
//	ON_WM_TIMER()
ON_WM_TIMER()
ON_EN_CHANGE(IDC_EDIT3, &CMy0141124825_houchuanhaoDlg::OnEnChangeEdit3)
ON_CBN_SELCHANGE(IDC_COMBO1, &CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo1)
ON_BN_CLICKED(IDC_BUTTON3, &CMy0141124825_houchuanhaoDlg::OnBnClickedButton3)
ON_STN_CLICKED(IDC_STATIC4, &CMy0141124825_houchuanhaoDlg::OnStnClickedStatic4)
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
CString codeAnswer(CString str)
{
	CString str1 = str;
	int l = str1.GetLength();

	for (int i = 0; i < l; i++)
	{
		str1.SetAt(i,str1[i]+1);
	}

	return str1;
}
//------------------------------------------------------------------------------------------------------------------------
float get_correlate(CString str1, CString str2)
{
	//计算两个字符串的长度。 
	int len1 = str1.GetLength();
	int len2 = str2.GetLength();
	//建立数组，比字符长度大一个空间 
	int ** dif = new int *[len1 + 1];
	for (int i = 0; i < len1 + 1; i++)
	{
		dif[i] = new int[len2 + 1];
	}
	//赋初值，步骤B。 
	for (int a = 0; a <= len1; a++)
	{

		dif[a][0] = a;
	}
	for (int a = 0; a <= len2; a++)
	{
		dif[0][a] = a;
	}
	//计算两个字符是否一样，计算左上的值 
	int temp;
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				temp = 0;
			}
			else
			{
				temp = 1;
			}
			//取三个值中最小的 
			dif[i][j] = min(dif[i - 1][j - 1] + temp, dif[i][j - 1] + 1, dif[i - 1][j] + 1);
		}
	}
	return 1 - (float)dif[len1][len2] / max(str1.GetLength(), str2.GetLength());
}
float CMy0141124825_houchuanhaoDlg::get_score(CString str2, CString str1)
{

	CString str3 = str1;
	MessageBox(str3);
	float correlate = get_correlate(str1, str2);
	accurate = correlate;
	if (sumtime == 0)
	{
		return 0;
	}
	float speed = str2.GetLength()*60.0 / (maxtime-sumtime)*1.0;
	myspeed = speed;
	if (speed > max_speed)
	{
		speed = max_speed;
	}
	float score = correlate * 100 * percentage_accuracy + speed *percentage_speed;

	if (score > 100)
		score = 100;
	Score = score;
	CString str;
	str.Format("%f", score);
	//MessageBox(str);
	return score;
}
CString CMy0141124825_houchuanhaoDlg::readIni(CString str)
//读取配置文件
{
	char mystr[100];//"d:\\RoadDataManagerApp.ini"
	CString mypath = getPath() + "\\config.ini";
	::GetPrivateProfileString("ExamInfo", str, "没找到信息" + str, mystr, MAX_PATH, mypath);
	//AfxMessageBox(mystr);
	return mystr;
}
void CMy0141124825_houchuanhaoDlg::loade()  //加载Ini文件
{
	total_questions = atoi(readIni("total_questions"));
	if (total_questions > 3)
		total_questions = 3;
	aduio_format = readIni("audio_format");
	max_speed = atoi(readIni("max_speed"));  //atoi string转int
	percentage_accuracy = atof(readIni("percentage_accuracy"));  //atof  string转double
	percentage_speed = atof(readIni("percentage_speed"));

}
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
		PDF_set_text_pos(p, 50, a4_height - 65);
		CString cs;
		cs.Format("正确率是%f，速度是%f字/分钟，本次考试的成绩是%f分", accuracy_rate, typing_speed, score);
		s = T2A(cs.GetBuffer());
		PDF_show(p, s);

		PDF_setfont(p, font_song, 8);
		PDF_set_text_pos(p, 50, a4_height - 65);
		s = "以下是您本次考试录入的内容:";
		PDF_show(p, s);

		PDF_set_text_pos(p, 50, a4_height - 65);
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


	//MessageBox(str);
	op.lpstrElementName = str; //文件路径 
	op.wDeviceID = NULL;      //打开设备成功以后保存这个设备号备用 
	UINT rs;        //接受函数返回结果 
	//发送命令打开设备，成功返回0，否则返回错误号，第三个参数这里必须MCI_OPEN_ELEMENT  
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&op);
	mciSendCommand(NULL, MCI_SET, MCI_SET_DOOR_OPEN, NULL);
	cdlen = getinfo(op.wDeviceID, MCI_STATUS_LENGTH);//获取音频文件长度
	int length = int(cdlen) / 1000 + 1;
	sumtime = length;
	maxtime = length;
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
bool CMy0141124825_houchuanhaoDlg::judge(CString exid, CString str)
{
	if (exid.GetLength() != 8)
		return 0;
	for (int i = 0; i <= 7; i++)
	{
		if (exid[i] > '9' || exid[i] < '0')
			return 0;
	}
	if (str.GetLength() != 18)
		return 0;
	int sum;
	char x;
	CString b = str;
	if (b.GetLength() != 18)
		return 0;
	sum = (b[0] - 48) * 7 + (b[1] - 48) * 9 + (b[2] - 48) * 10 + (b[3] - 48) * 5 + (b[4] - 48) * 8 + (b[5] - 48) * 4 + (b[6] - 48) * 2 + (b[7] - 48) * 1 + (b[8] - 48) * 6 + (b[9] - 48) * 3 + (b[10] - 48) * 7 + (b[11] - 48) * 9 + (b[12] - 48) * 10 + (b[13] - 48) * 5 + (b[14] - 48) * 8 + (b[15] - 48) * 4 + (b[16] - 48) * 2;
	int p = sum % 11;
	switch (p)
	{
	case 0:x = '1'; break;
	case 1:x = '0'; break;
	case 2:x = 'X'; break;
	case 3:x = '9'; break;
	case 4:x = '8'; break;
	case 5:x = '7'; break;
	case 6:x = '6'; break;
	case 7:x = '5'; break;
	case 8:x = '4'; break;
	case 9:x = '3'; break;
	case 10:x = '2'; break;
	}
	if (x == b[17])
		return 1;
	else
		return 0;
}
CString CMy0141124825_houchuanhaoDlg::getAnswer()
{
	CString str1="为纪念中国人民抗日战争暨世界反法西斯战争胜利六十九周年经党中央国务院批准民政部昨日公布了第一批八十处国家级抗战纪念设施遗址名录以及在抗日战争中三百名著名抗日英烈和英雄群体名录云南腾冲国殇墓园山东台儿庄大战纪念馆等一批国民党军队抗日遗址和纪念设施入选名录在著名抗日英烈名录中国民党将领张自忠佟麟阁赵登禹国际友人白求恩等入选二零一四年二月中国以立法形式确定九月三日为中国人民抗日战争胜利纪念日公布国家级抗战纪念设施遗址和著名抗日英烈名录是其中的一项重要活动安排据新华社消息明天上午首都各界将举行隆重纪念活动党和国家领导人出席据有关部门负责人介绍在第一批抗日英烈和英雄群体名录的遴选过程中综合考虑了英烈的抗战事迹牺牲情节和社会影响力等包括了中国共产党领导下的八路军新四军华南游击队东北抗日联军和其他人民抗日武装国民党抗日将士民主爱国人士和援华国际友人等不同群体的代表据悉这次公布的八十处国家级抗战纪念设施遗址涵盖了反映日军侵华罪行日军投降中方受降和审判共产党领导下的敌后抗战国民党正面战场抗战其他国家支援参与中国抗战以及纪念抗战牺牲英烈等各个方面其中大多是全国重点文物保护单位全国爱国主义教育示范基地全国重点烈士纪念建筑物保护单位全国红色旅游经典景区据有关部门负责人介绍今后中国还将择机陆续公布几批抗战纪念设施遗址和抗日英烈名录";
	return str1;
	//char* pszFileName = "D:\\myfile.txt";
	CString pszFileName = getPath() + aduio_format + "\\" + now_iPos + "\\" + now_iPos + ".txt";
	//MessageBox(pszFileName);
	//MessageBox(pszFileName);
	CStdioFile myFile;
	CFileException fileException;

	if (myFile.Open(pszFileName, CFile::typeText | CFile::modeReadWrite), &fileException)

	{

		myFile.SeekToBegin();

		myFile.ReadString(str1);

		//AfxMessageBox(str1);

	}

	else

	{

		TRACE("Can't open file %s,error=%u\n", pszFileName, fileException.m_cause);

	}

	myFile.Close();
	//MessageBox(str1);
	int l = str1.GetLength();
	CString str2;
	for (int i = 0; i < l; i++)
	{
		str1.SetAt(i, str1[i] - 1);
	}
	//MessageBox("答案为" + str1);

	return str1;
}






















//---------------
void CMy0141124825_houchuanhaoDlg::OnBnClickedButton2()
{
	int  change = MessageBox(_T("提交之后考试将结束，确定提交吗？"), _T("提示"), MB_OKCANCEL);
	if (change == 1)
	{
		UpdateData();
		/*
		CButton *pBtn = (CButton *)GetDlgItem(IDC_BUTTON2);
		pBtn->EnableWindow(0);
		pBtn = (CButton *)GetDlgItem(IDC_BUTTON3);
		pBtn->EnableWindow(1);
		*/
		//Output_pdf("111", "qqq", 12, 12, 12, "12345");
		// TODO:  在此添加控件通知处理程序代码
		Stop();
		KillTimer(1);
		Score =get_score(getAnswer(), myanswer);

		CString str,v,c;
		str.Format("%f", Score);
		v.Format("%f", myspeed);
		c.Format("%f", accurate);
		MessageBox("答案已提交成功，您的成绩为"+str+"\n"+"速度为"+v+"\n准确率为"+c);
	}
}


void CMy0141124825_houchuanhaoDlg::OnBnClickedButton1()
{
	open = 1;
	UpdateData();
	if (judge(exid, id) == 0)
	{
		MessageBox("请填写正确的省份证和准考证号");
	}
	else
	{
		CButton *pBtn = (CButton *)GetDlgItem(IDC_BUTTON2);
		pBtn->EnableWindow(1);
		pBtn = (CButton *)GetDlgItem(IDC_BUTTON1);
		pBtn->EnableWindow(0);
		pBtn = (CButton *)GetDlgItem(IDC_EDIT3);
		pBtn->EnableWindow(1);
		SetTimer(1, 1000, 0);
		play();
	}
	// TODO:  在此添加控件通知处理程序代码
}




//void CMy0141124825_houchuanhaoDlg::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//	int minutes = sumtime / 60;
//	int secsond = sumtime % 60;
//	CString str, str1;
//	str1 = "考试剩余时间： \n";
//	str.Format("%d", minutes);
//	str1 = str1 + str + "分";
//	str.Format("%d", secsond);
//	str1 = str1 + str + "秒";
//	GetDlgItem(IDC_STATIC4)->SetWindowText(str1);
//	if (sumtime == 0)
//	{
//		CButton *pBtn = (CButton *)GetDlgItem(IDC_EDIT1);
//		pBtn->EnableWindow(FALSE);
//		KillTimer(nIDEvent);
//		GetDlgItem(IDC_STATIC4)->SetWindowText("时间到!");
//	}
//	CDialogEx::OnTimer(nIDEvent);
//}


void CMy0141124825_houchuanhaoDlg::OnStnClickedStatic1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMy0141124825_houchuanhaoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	sumtime--;
	int minutes = sumtime / 60;
	int secsond = sumtime % 60;
	CString str, str1;
	str1 = "考试剩余时间： \n";
	str.Format("%d", minutes);
	str1 = str1 + str + "分";
	str.Format("%d", secsond);
	str1 = str1 + str + "秒";
	GetDlgItem(IDC_STATIC4)->SetWindowText(str1);
	if (sumtime == 0)
	{
		CButton *pBtn = (CButton *)GetDlgItem(IDC_EDIT3);
		pBtn->EnableWindow(FALSE);
		KillTimer(nIDEvent);
		GetDlgItem(IDC_STATIC4)->SetWindowText("时间到!，答案已自动提交");
		CString str;
		str.Format("%f", get_score(getAnswer(), myanswer));
		MessageBox("时间到!，答案已经自动提交,您的成绩为"+str);
	}
}


void CMy0141124825_houchuanhaoDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo1()
{
	int iPos = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel() + 1;//当前选中的行
	now_iPos.Format("%d", iPos);
	// TODO:  在此添加控件通知处理程序代码
}


void CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo3()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMy0141124825_houchuanhaoDlg::OnBnClickedButton3()
{
	UpdateData();
	Output_pdf(exid, id, accurate, myspeed, Score, myanswer);
	// TODO:  在此添加控件通知处理程序代码
}


void CMy0141124825_houchuanhaoDlg::OnStnClickedStatic4()
{
	// TODO:  在此添加控件通知处理程序代码
}
