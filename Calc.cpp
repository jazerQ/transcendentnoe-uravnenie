#include "stdafx.h"
#include "Calc.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>
double CCalc::func1(double x) {
	return (m_A * pow(x, m_B)) + m_C - pow(M_E, (x / m_D));
}
double CCalc::func2(double x) {
	return (m_A * m_B * pow(x, m_B - 1)) - (pow(M_E, (x / m_D)) / m_D);
}
double CCalc::func22(double x) {
	return (m_A * pow(m_B, 2) * pow(x, m_B - 2) - m_A * m_B * pow(x, m_B - 2) - (pow(M_E, (x / m_D)) / pow(m_D, 2)));
}
double CCalc::func3(double x) {
	return x - (func1(x) / func2(x));

}
double CCalc::func4(double x1, double x2) {
	return abs(x2 - x1);
}

CCalc::CCalc()
{
}


CCalc::~CCalc()
{
}
double formatValue(double value, int precision) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << value;
	std::string formatted = oss.str();
	return std::stod(formatted); // Возвращаем отформатированное значение
}

double CCalc::findKor() {
	double x0 = (beg + end) / 2;
	double pribl = func3(x0);
	double point = func3(pribl);
	while (abs(pribl - point) > e) {
		pribl = point;
		point = func3(pribl);
		iter++;
	}
	double sup = abs(log10(e));
	return formatValue(point, sup);
	
}

CPoint CCalc::GetPoint(float x)
{
	double y;
	y = func1(x);
	return ToGraph(x,-y);
}

size_t CCalc::GetVseTochki(std::vector<CPoint>& vecPt)
{
	int numPoints = 18;
	vecPt.clear();
	for (float x = -numPoints-20; x < numPoints-1 ; x+=0.01)
	{
		CPoint pt = GetPoint(x);
		vecPt.push_back(pt);
	}
	return vecPt.size();
}

