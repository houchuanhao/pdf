
// 0141124825_houchuanhaoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0141124825_houchuanhao.h"
#include "0141124825_houchuanhaoDlg.h"
//#include "afxdialogex.h"
#include "pdflib.h"
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


// CMy0141124825_houchuanhaoDlg �Ի���



CMy0141124825_houchuanhaoDlg::CMy0141124825_houchuanhaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy0141124825_houchuanhaoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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





























//---------------
void CMy0141124825_houchuanhaoDlg::OnBnClickedButton2()
{
	Output_pdf("111", "qqq", 12, 12, 12, "12345");
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
