
// APP02Dlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "APP02.h"
#include "APP02Dlg.h"
#include "afxdialogex.h"

#include <ctime>
#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CAPP02Dlg



CAPP02Dlg::CAPP02Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAPP02Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPP02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAPP02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnProcessIt, &CAPP02Dlg::OnBnClickedbtnprocessit)
END_MESSAGE_MAP()


// Controladores de mensaje de CAPP02Dlg

BOOL CAPP02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int day = ltm->tm_mday;
	int month = ltm->tm_mon + 1;
	int year = 1900 + ltm->tm_year;
	int startDay = 1;
	int endDay = 14;

	//test for greater than first two weeks 14 days
	if (day > 14)
	{
		startDay = 15;
		endDay = startDay + 14;
	}

	//set biWeeklyPayDatasm
	CTime payStart(year, month, startDay, 0, 0, 0);
	CString s = payStart.Format("%Y/%m/%d");
	CTime payEnd(year, month, endDay, 0, 0, 0);
	CString e = payEnd.Format("%Y/%m/%d");
	CString payRange = s + " - " + e;
	SetDlgItemText(txtPayPeriod, payRange);

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CAPP02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CAPP02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CAPP02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAPP02Dlg::OnBnClickedbtnprocessit()
{
	CString temp;

	//Employee ID
	GetDlgItemText(txtEmployeeId, temp);
	double dEmployeeId = _ttof(temp);

	//Hourly Wage
	GetDlgItemText(txtHourlyWage, temp);
	double dHourlyWage = _ttof(temp);

	//First Week
	GetDlgItemText(txtFirstWeekMonday, temp);
	double dFirstMonday = _ttof(temp);

	GetDlgItemText(txtFirstWeekTusday, temp);
	double dFirstTusday = _ttof(temp);

	GetDlgItemText(txtFirstWeekWednesday, temp);
	double dFirstWednesday = _ttof(temp);

	GetDlgItemText(txtFirstWeekThursday, temp);
	double dFirstThursday = _ttof(temp);

	GetDlgItemText(txtFirstWeekFriday, temp);
	double dFirstFriday = _ttof(temp);

	GetDlgItemText(txtFirstWeekSaturday, temp);
	double dFirstSaturday = _ttof(temp);

	GetDlgItemText(txtFirstWeekSunday, temp);
	double dFirstSunday = _ttof(temp);

	//Secont Week
	GetDlgItemText(txtSecondWeekMonday, temp);
	double dSecondMonday = _ttof(temp);

	GetDlgItemText(txtSecondWeekTusday, temp);
	double dSecondTusday = _ttof(temp);

	GetDlgItemText(txtSecondWeekWednesday, temp);
	double dSecondWednesday = _ttof(temp);

	GetDlgItemText(txtSecondWeekThursday, temp);
	double dSecondThursday = _ttof(temp);

	GetDlgItemText(txtSecondWeekFriday, temp);
	double dSecondFriday = _ttof(temp);

	GetDlgItemText(txtSecondWeekSaturday, temp);
	double dSecondSaturday = _ttof(temp);

	GetDlgItemText(txtSecondWeekSunday, temp);
	double dSecondSunday = _ttof(temp);

	// === Hours Calculations
	double week1Hours = 0;
	double week2Hours = 0;
	week1Hours = dFirstMonday + dFirstTusday + dFirstWednesday + dFirstThursday + dFirstFriday + dFirstSaturday + dFirstSunday;
	week2Hours = dSecondMonday + dSecondTusday + dSecondWednesday + dSecondThursday + dSecondFriday + dSecondSaturday + dSecondSunday;
	double regularHoursWeek1 = 0;
	double regularHoursWeek2 = 0;
	double totalHours = 0;
	double overtimeHoursWeek1 = 0;
	double overtimeHoursWeek2 = 0;
	double totalOvertime = 0;
	// === Amount Calculations: dHourlyWage
	double regularAmountPay = 0;
	double overtimeAmountPay = 0;
	double totalEarnings = 0;

	//get hours
	if (week1Hours > 40)
	{
		regularHoursWeek1 = 40;
		overtimeHoursWeek1 = week1Hours - 40;
	}
	else
	{
		regularHoursWeek1 = week1Hours;
	}
	if (week2Hours > 40)
	{
		regularHoursWeek2 = 40;
		overtimeHoursWeek2 = week2Hours - 40;
	}
	else
	{
		regularHoursWeek2 = week2Hours;
	}

	totalHours = regularHoursWeek1 + regularHoursWeek2;
	totalOvertime = overtimeHoursWeek1 + overtimeHoursWeek2;

	//get amounts
	regularAmountPay = dHourlyWage * totalHours;
	overtimeAmountPay = (dHourlyWage * 1.5) * totalOvertime;
	totalEarnings = regularAmountPay + overtimeAmountPay;

	//set regular hours
	string strTotalHours = to_string(totalHours);
	CString totalRegularHours(strTotalHours.c_str());
	SetDlgItemText(txtRegularHours, totalRegularHours);

	//set overtime hours
	string strTotalOvertimeHours = to_string(totalOvertime);
	CString totalOvertimeHours(strTotalOvertimeHours.c_str());
	SetDlgItemText(txtOvertimeHours, totalOvertimeHours);

	//set regular pay amount
	string strRegularAmount = to_string(regularAmountPay);
	CString totalRegularAmount(strRegularAmount.c_str());
	SetDlgItemText(txtRegularAmount, totalRegularAmount);

	//set overtime pay amount
	string strOvertimeAmount = to_string(overtimeAmountPay);
	CString totalOvertimeAmount(strOvertimeAmount.c_str());
	SetDlgItemText(txtOvertimeAmount, totalOvertimeAmount);

	//set total earning
	string strTotalEarnings = to_string(totalEarnings);
	CString csTotalEarning(strTotalEarnings.c_str());
	SetDlgItemText(txtTotalEarning, csTotalEarning);
}
