// CSettingDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CSettingDialog.h"
#include "afxdialogex.h"
#include "CSeviceParamDialog.h"
#include "CropType.h"
#include "CLogin.h"
// CSettingDialog 对话框

IMPLEMENT_DYNAMIC(CSettingDialog, CDialogEx)

CSettingDialog::CSettingDialog(CUserManager* pUserManager, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING, pParent)
{
	m_pUserManager = pUserManager;
}

CSettingDialog::~CSettingDialog()
{
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_RESOLUTION_RATIO, m_ResolutionRatio);
}


BEGIN_MESSAGE_MAP(CSettingDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SET_SERVER_PARAM, &CSettingDialog::OnBnClickedButtonSetServerParam)
	ON_CBN_SELCHANGE(IDC_COMBO_RESOLUTION_RATIO, &CSettingDialog::OnCbnSelchangeComboResolutionRatio)
	ON_BN_CLICKED(IDC_BUTTON_SETTING_OK, &CSettingDialog::OnBnClickedButtonSettingOk)
END_MESSAGE_MAP()


// CSettingDialog 消息处理程序


void CSettingDialog::OnBnClickedButtonSetServerParam()
{
	CSeviceParamDialog dlg(m_pUserManager);
	dlg.DoModal();
}


BOOL CSettingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_176BW_320BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_176BW_320BH_88SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_240BW_320BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_240BW_320BH_120SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_480BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_480BH_120SW_120SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_480BH_240SW_240SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_360BW_640BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_360BW_640BH_90SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_360BW_640BH_180SW_320SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_640BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_640BH_120SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_480BW_640BH_240SW_320SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_640BW_640BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_640BW_640BH_160SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_640BW_640BH_320SW_320SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_720BW_1280BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_720BW_1280BH_90SW_160SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_720BW_1280BH_180SW_320SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_720BW_1280BH_360SW_640SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_1080BW_1920BH_SMALL_NONE).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_1080BW_1920BH_135SW_240SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_1080BW_1920BH_270SW_480SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_1080BW_1920BH_540SW_960SH).c_str());
	m_ResolutionRatio.AddString(CropTypeInfo::getCropTypeDescribe(VIDEO_CROP_CONFIG_BIG_NOCROP_SMALL_NONE).c_str());

	m_ResolutionRatio.SetCurSel(m_pUserManager->m_ServiceParam.m_CropType);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSettingDialog::OnCbnSelchangeComboResolutionRatio()
{
	
}


void CSettingDialog::OnBnClickedButtonSettingOk()
{
	int nIndex = m_ResolutionRatio.GetCurSel();
	m_pUserManager->m_ServiceParam.m_CropType = nIndex;
	CLogin login(m_pUserManager);
	login.writeConfig();
}
