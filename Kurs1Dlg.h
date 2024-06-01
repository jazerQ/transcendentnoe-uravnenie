// Kurs1Dlg.h : файл заголовка
//

#pragma once

#include "MyGraph.h"
#include "Calc.h"
#include "IfaceKurs.h"
#include "afxwin.h"
#include "afxcmn.h"

struct Scale_Shift_s
{
	double ScaleX;
	double ScaleY;
	int ShiftX, ShiftY;
	struct Scale_Shift_s() {
		ScaleX = 1; ScaleY = 1; ShiftX = ShiftY = 100;
	}

};



// диалоговое окно CKurs1Dlg
class CKurs1Dlg : public CDialogEx 
	, IfaceKurs
{
// Создание
public:
	CKurs1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURS1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMyGraph m_paint;
	CCalc m_Calc;
	std::vector<CPoint> m_vecPt;
	
	void Risovat(double A, double B, double C, double D,double beg, double end, double e);
	afx_msg void OnBnClickedWindowTileVert();
	virtual int GetVecPt(std::vector<CPoint> &vec) const override;
	afx_msg void OnEnChangeEditA();
protected:
	CEdit m_EdA;
	CEdit m_EdB;
	CEdit m_EdC;
	CEdit m_EdD;
	CEdit m_EdSpeed;
	CEdit m_float;
	CEdit Beg;
	CEdit End;
	double m_EdToch;
	CSpinButtonCtrl m_spin;
	double m_A;
	double m_B;
	double m_C;
	double m_D;
	double m_e;
	double m_Begin;
	double m_End;
	int speed = 0;
	Scale_Shift_s m_ScShift;
	bool m_bInited;
protected:
	void ScaleShift();
public:
	afx_msg void OnEnChangeEditB();
	afx_msg void OnBnClickedButScup();
	afx_msg void OnBnClickedButScdn();
	//afx_msg void OnBnClickedBtnScUp();
	
	afx_msg void OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CStatic* pStatic;
	CSliderCtrl m_SliderScale;
	CStatic str;
	afx_msg void OnTRBNThumbPosChangingSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck1();
	CButton m_ckTik;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_cmbPicBg;
	afx_msg void OnCbnSelchangeCombPicbg();
	afx_msg void OnBnClickedSave();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnGrey();
	afx_msg void OnEnChangeEditC();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEdit4();

	afx_msg void OnEnChangeEditBegin();
	afx_msg void OnEnChangeEditEnd();
};
