#include "pch.h"
#include "CDoubleB.h"

void CDoubleB::MakeMemBitmap() {
	CClientDC dc(this); //실제 dc
	CBitmap* pOldBmp;  //oldbmp 
	CDC MemDC; //메모리DC 
	m_Bitmap.DeleteObject(); //기존꺼 지워줌 
	m_Bitmap.CreateCompatibleBitmap(&dc, 500, 200); //새로 만들어줌 
	MemDC.CreateCompatibleDC(&dc); //memDC도 새로 만들어줌 
	pOldBmp = MemDC.SelectObject(&m_Bitmap); //memDC의 비트맵 선택 
	MemDC.MoveTo(0,0); 
	MemDC.LineTo(500,200); //memDC에 그린다.(비트맵 위에 그려진다) 
	MemDC.SelectObject(pOldBmp); //oldbmp 선택 
	MemDC.DeleteDC(); //memDC를 지운다. 
}
void CDoubleB::OnPaint() {
	CPaintDC dc(this); // device context for painting 
	CDC MemDC; 
	CBitmap* pOldBmp; 
	MemDC.CreateCompatibleDC(&dc); 
	pOldBmp = MemDC.SelectObject(&m_Bitmap); 
	dc.BitBlt(0,0,500,200, &MemDC, 0,0,SRCCOPY); 
	MemDC.SelectObject(pOldBmp); 
	MemDC.DeleteDC(); }
