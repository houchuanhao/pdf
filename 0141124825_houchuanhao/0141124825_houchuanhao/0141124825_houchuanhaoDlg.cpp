
// 0141124825_houchuanhaoDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMy0141124825_houchuanhaoDlg �Ի���



CMy0141124825_houchuanhaoDlg::CMy0141124825_houchuanhaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy0141124825_houchuanhaoDlg::IDD, pParent)
	, exid(_T(""))
	, id(_T(""))
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
	CString strTemp;
	((CComboBox*)GetDlgItem(IDC_COMBO1))->ResetContent();//����������������
	for (int i = 1; i <= total_questions; i++)
	{
		strTemp.Format("%d", i);
		((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(strTemp);
	}
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
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
ON_CBN_SELCHANGE(IDC_COMBO3, &CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// CMy0141124825_houchuanhaoDlg ��Ϣ�������

BOOL CMy0141124825_houchuanhaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy0141124825_houchuanhaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

	remove("�ɼ���.pdf");

	PDF *p;
	//PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//ȥ��ˮӡ����ע���д�롣

	if ((p = PDF_new()) == (PDF *)0){
		printf("Couldn't create PDFlib object (out of memory)!/n");
		return;
	}

	PDF_TRY(p) {
		/* This means we must check return values of load_font() etc. */
		//PDF_set_parameter(p, "errorpolicy", "return");
		USES_CONVERSION;
		PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//ȥ��ˮӡ����ע���д�롣

		CString str(exam_number);
		CString str2 = "_�ɼ���.pdf";

		CString str1 = str + str2;
		const char *FileName = str1;
		if (PDF_begin_document(p, FileName, 0, "") == -1) {
			printf("Error: %s/n", PDF_get_errmsg(p));
			return;
		}

		/* This line is required to avoid problems on Japanese systems */
		PDF_set_parameter(p, "hypertextencoding", "host");
		//PDF_set_parameter(p, "license", "X600605-009100-4E7661-329E0C");//ȥ��ˮӡ����ע���д�롣

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
		s = "���֤�ţ�" + s;
		PDF_show(p, s);

		PDF_set_text_pos(p, 50, a4_height - 65);
		s = T2A((exam_number.GetBuffer()));
		s = "׼��֤�ţ�" + s;
		PDF_show(p, s);

		PDF_setfont(p, font_song, 8);
		PDF_set_text_pos(p, 50, a4_height - 85);
		CString cs;
		cs.Format("�����ֵ���ȷ����%f���ٶ���%f��/���ӣ����ο��Եĳɼ���%f��", accuracy_rate, typing_speed, score);
		s = T2A(cs.GetBuffer());
		PDF_show(p, s);

		PDF_setfont(p, font_song, 8);
		PDF_set_text_pos(p, 50, a4_height - 100);
		s = "�����������ο���¼�������:";
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: Add your control notification handler code here
	DWORD cdlen;//��Ƶ�ļ�����
	op.dwCallback = NULL;
	op.lpstrAlias = NULL;
	op.lpstrDeviceType = _T("MPEGAudio");  //�豸���ͣ�������ļ������������� 
	//op.lpstrElementName = "C:\\WINDOWS\\Media\\Alarm02.wav"; //�ļ�·�� 
	CString str = getPath() + aduio_format + "\\" + now_iPos + "\\" + now_iPos + "." + aduio_format;


	MessageBox(str);
	op.lpstrElementName = str; //�ļ�·�� 
	op.wDeviceID = NULL;      //���豸�ɹ��Ժ󱣴�����豸�ű��� 
	UINT rs;        //���ܺ������ؽ�� 
	//����������豸���ɹ�����0�����򷵻ش���ţ������������������MCI_OPEN_ELEMENT  
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&op);
	mciSendCommand(NULL, MCI_SET, MCI_SET_DOOR_OPEN, NULL);
	cdlen = getinfo(op.wDeviceID, MCI_STATUS_LENGTH);//��ȡ��Ƶ�ļ�����
	int length = int(cdlen) / 1000 + 1;
	sumtime = length;
	int a = int(cdlen);
	if (rs == 0)        //�豸�򿪳ɹ��Ͳ����ļ� 
	{
		MCI_PLAY_PARMS pp;
		pp.dwCallback = NULL;
		pp.dwFrom = 0;      //��ʼ���ŵ�λ�� 
		mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&pp);
		//�����ļ������������������ΪMCI_WAIT����򴰿ڻᱻ������Ϊ�˱����������������ΪMCI_NOTIFY 
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
	GetModuleFileName(NULL, strModule, 256); //�õ���ǰģ��·��

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

























//---------------
void CMy0141124825_houchuanhaoDlg::OnBnClickedButton2()
{
	Output_pdf("111", "qqq", 12, 12, 12, "12345");
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Stop();
	KillTimer(1);
}


void CMy0141124825_houchuanhaoDlg::OnBnClickedButton1()
{
	UpdateData();
	if (judge(exid, id) == 0)
	{
		MessageBox("����д��ȷ��ʡ��֤��׼��֤��");
	}
	else
	{
		SetTimer(1, 1000, 0);
		play();
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




//void CMy0141124825_houchuanhaoDlg::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	int minutes = sumtime / 60;
//	int secsond = sumtime % 60;
//	CString str, str1;
//	str1 = "����ʣ��ʱ�䣺 \n";
//	str.Format("%d", minutes);
//	str1 = str1 + str + "��";
//	str.Format("%d", secsond);
//	str1 = str1 + str + "��";
//	GetDlgItem(IDC_STATIC4)->SetWindowText(str1);
//	if (sumtime == 0)
//	{
//		CButton *pBtn = (CButton *)GetDlgItem(IDC_EDIT1);
//		pBtn->EnableWindow(FALSE);
//		KillTimer(nIDEvent);
//		GetDlgItem(IDC_STATIC4)->SetWindowText("ʱ�䵽!");
//	}
//	CDialogEx::OnTimer(nIDEvent);
//}


void CMy0141124825_houchuanhaoDlg::OnStnClickedStatic1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0141124825_houchuanhaoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);
	sumtime--;
	int minutes = sumtime / 60;
	int secsond = sumtime % 60;
	CString str, str1;
	str1 = "����ʣ��ʱ�䣺 \n";
	str.Format("%d", minutes);
	str1 = str1 + str + "��";
	str.Format("%d", secsond);
	str1 = str1 + str + "��";
	GetDlgItem(IDC_STATIC4)->SetWindowText(str1);
	if (sumtime == 0)
	{
		CButton *pBtn = (CButton *)GetDlgItem(IDC_EDIT1);
		pBtn->EnableWindow(FALSE);
		KillTimer(nIDEvent);
		GetDlgItem(IDC_STATIC4)->SetWindowText("ʱ�䵽!");
	}
}


void CMy0141124825_houchuanhaoDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0141124825_houchuanhaoDlg::OnCbnSelchangeCombo3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
