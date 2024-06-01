#include "stdafx.h"
#include "ScaleShift.h"


CScaleShift::CScaleShift()
{
}


CScaleShift::~CScaleShift()
{
}

void CScaleShift::Scale(double newSc)
{
	m_Scale = newSc;
}

void CScaleShift::Shift(CPoint & ptNew)
{
	m_ptC = ptNew;
}

CPoint CScaleShift::ToGraph(double x, double y)
{
	CPoint pt;
	pt.x = m_Scale * 0.5* x + m_ptC.x;
	pt.y = m_Scale * 0.5 * y + m_ptC.y;
	return pt;
}
