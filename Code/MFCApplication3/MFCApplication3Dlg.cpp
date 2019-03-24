
// MFCApplication3Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "IDManTypeInfo.h"
#include "IDManTypeInfo_i.c"
#include <atlbase.h>
#import "IDManTypeInfo.tlb"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication3Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication3Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication3Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication3Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_CHECK3, &CMFCApplication3Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_CHECK4, &CMFCApplication3Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_CHECK5, &CMFCApplication3Dlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	::SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
	SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
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
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	//下载地址
	GetDlgItemText(IDC_EDIT1, str);
	if (str.IsEmpty())
	{
		MessageBox(_T("你逗我呢？没地址下个毛线！！！"), _T("错误"), MB_ICONERROR);
	}
	else
	{
		CComBSTR bstrHref = str.AllocSysString();
		//UA
		GetDlgItemText(IDC_EDIT2, str);
		CComBSTR pbstrUA = NULL;
		if (!((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck() || str.IsEmpty())
		{
			;
		}
		else
		{
			pbstrUA = str.AllocSysString();
		}
		//Referer
		GetDlgItemText(IDC_EDIT3, str);
		CComBSTR referer = NULL;
		if (!((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck() || str.IsEmpty())
		{
			;
		}
		else
		{
			referer = str.AllocSysString();
		}
		//cookie
		GetDlgItemText(IDC_EDIT4, str);
		CComBSTR cookie = NULL;
		if (!((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck() || str.IsEmpty())
		{
			;
		}
		else
		{
			cookie = str.AllocSysString();
		}
		//保存路径
		GetDlgItemText(IDC_MFCEDITBROWSE1, str);
		CComBSTR bstrLocalPath = NULL;
		if (!((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck() || str.IsEmpty())
		{
			;
		}
		else
		{
			bstrLocalPath = str.AllocSysString();
		}
		//文件名
		GetDlgItemText(IDC_EDIT5, str);
		CComBSTR bstrLocalFileName = NULL;
		if (!((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck() || str.IsEmpty())
		{
			;
		}
		else
		{
			bstrLocalFileName = str.AllocSysString();
		}
		CoInitialize(NULL);
		ICIDMLinkTransmitter2* pIDM;
		HRESULT hr = CoCreateInstance(CLSID_CIDMLinkTransmitter, NULL, CLSCTX_LOCAL_SERVER, IID_ICIDMLinkTransmitter2, (void**)&pIDM);
		if (S_OK == hr)
		{
			VARIANT var1, var2;
			VariantInit(&var1);
			VariantInit(&var2);
			if (pbstrUA)
			{
				var1.vt = VT_BSTR;
				var1.bstrVal = pbstrUA;
			}
			else
			{
				var1.vt = VT_EMPTY;
			}
			var2.vt = VT_EMPTY;
			hr = pIDM->SendLinkToIDM2(bstrHref, referer, cookie, NULL, NULL, NULL, bstrLocalPath, bstrLocalFileName, 0, var1, var2);
			pIDM->Release();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_EDIT1, fromClipboard);
			CloseClipboard();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	}
	else
	{
		CString str;
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())
		{
			GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		}
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	}
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		;
	}
	else
	{
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_EDIT2, fromClipboard);
			CloseClipboard();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck())
	{
		GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	}
	else
	{
		CString str;
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())
		{
			GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		}
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	}
}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck())
	{
		;
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_EDIT3, fromClipboard);
			CloseClipboard();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	}
	else
	{
		CString str;
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())
		{
			GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		}
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	}
}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		;
	}
	else
	{
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_EDIT4, fromClipboard);
			CloseClipboard();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck())
	{
		GetDlgItem(IDC_MFCEDITBROWSE1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
	}
	else
	{
		CString str;
		GetDlgItemText(IDC_MFCEDITBROWSE1, str);
		if (str.IsEmpty())
		{
			GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		}
		GetDlgItem(IDC_MFCEDITBROWSE1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
	}
}


void CMFCApplication3Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck())
	{
		;
	}
	else
	{
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_MFCEDITBROWSE1)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedCheck5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck())
	{
		GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);
	}
	else
	{
		CString str;
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())
		{
			GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
		}
		GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	}
}


void CMFCApplication3Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck())
	{
		;
	}
	else
	{
		GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T(""));
}


void CMFCApplication3Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_EDIT5, fromClipboard);
			CloseClipboard();
		}
	}
}


void CMFCApplication3Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			char* hData;
			hClip = GetClipboardData(CF_TEXT);
			hData = (char*)GlobalLock(hClip);
			char* buffer = (char*)GlobalLock(hData);
			CString fromClipboard = (CString)buffer;
			GlobalUnlock(hData);
			SetDlgItemText(IDC_MFCEDITBROWSE1, fromClipboard);
			CloseClipboard();
		}
	}
}
