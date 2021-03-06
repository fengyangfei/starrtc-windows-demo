// CSeviceParamDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CSeviceParamDialog.h"
#include "afxdialogex.h"
#include "CLogin.h"

// CSeviceParamDialog 对话框

IMPLEMENT_DYNAMIC(CSeviceParamDialog, CDialogEx)

CSeviceParamDialog::CSeviceParamDialog(CUserManager* pUserManager, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SET_SERVER_PARAM, pParent)
{
	m_pUserManager = pUserManager;
}

CSeviceParamDialog::~CSeviceParamDialog()
{
}

void CSeviceParamDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SETTING_USERID, m_UserIdEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_APPID, m_AgentIdEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_LOGIN_SERVICE, m_LoginServiceEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_MESSAGE_SERVICE, m_MessageServiceEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_CHAT_SERVICE, m_ChatServiceEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_UPLOAD__SERVICE, m_UploadServiceEdit);
	DDX_Control(pDX, IDC_EDIT_SETTING_DOWNLOAD_SERVICE, m_DownloadServiceEidt);
	DDX_Control(pDX, IDC_EDIT_SETTING_VOIP_SERVICE, m_VOIPServiceEdit);
}


BEGIN_MESSAGE_MAP(CSeviceParamDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_SYSTERM_SETTING, &CSeviceParamDialog::OnBnClickedButtonSaveSystermSetting)
END_MESSAGE_MAP()


// CSeviceParamDialog 消息处理程序


void CSeviceParamDialog::OnBnClickedButtonSaveSystermSetting()
{
	if (m_pUserManager != NULL)
	{
		CString str = "";
		m_UserIdEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strUserId = str;
		str = "";

		m_AgentIdEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strAgentId = str;
		str = "";

		m_LoginServiceEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strLoginServiceIP = str;
		str = "";

		m_MessageServiceEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strMessageServiceIP = str;
		str = "";

		m_UserIdEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strChatServiceIP = str;
		str = "";

		m_UploadServiceEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strUploadServiceIP = str;
		str = "";

		m_DownloadServiceEidt.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strDownloadServiceIP = str;
		str = "";

		m_VOIPServiceEdit.GetWindowText(str);
		m_pUserManager->m_ServiceParam.m_strVOIPServiceIP = str;
		str = "";
		CLogin login(m_pUserManager);
		login.writeConfig();
	}
}


BOOL CSeviceParamDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (m_pUserManager != NULL)
	{
		m_UserIdEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUserId.c_str());
		m_AgentIdEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strAgentId.c_str());
		m_LoginServiceEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strLoginServiceIP.c_str());
		m_MessageServiceEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strMessageServiceIP.c_str());
		m_ChatServiceEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strChatServiceIP.c_str());
		m_UploadServiceEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strUploadServiceIP.c_str());
		m_DownloadServiceEidt.SetWindowText(m_pUserManager->m_ServiceParam.m_strDownloadServiceIP.c_str());
		m_VOIPServiceEdit.SetWindowText(m_pUserManager->m_ServiceParam.m_strVOIPServiceIP.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
