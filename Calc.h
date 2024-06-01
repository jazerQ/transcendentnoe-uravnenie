#pragma once
#include "ScaleShift.h"
#include <vector>

class CCalc :
	public CScaleShift
{
public:
	CCalc();
	~CCalc();
protected:
	double m_A;
	double m_B;
	double m_C;
	double m_D;
	double beg;
	double end;
	double e;
public:
	CPoint GetPoint(float i);
	void SetPar(double A, double B, double C, double D, double m_beg, double m_end, double m_e) {
		m_A = A; 
		m_B = B; 
		m_C = C;
		m_D = D;
		beg = m_beg;
		end = m_end;
		e = m_e;
	};
	size_t GetVseTochki(std::vector<CPoint>& vecPt);
	double func1(double x);
	double func2(double x);
	double func22(double x);
	double func3(double x);
	double func4(double x1, double x2);
	double findKor();
	int iter = 0;
};

