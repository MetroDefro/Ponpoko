#include "pch.h"
#include "CDoubleB.h"

void CDoubleB::MakeMemBitmap() {
	CClientDC dc(this); //���� dc
	CBitmap* pOldBmp;  //oldbmp 
	CDC MemDC; //�޸�DC 
	m_Bitmap.DeleteObject(); //������ ������ 
	m_Bitmap.CreateCompatibleBitmap(&dc, 500, 200); //���� ������� 
	MemDC.CreateCompatibleDC(&dc); //memDC�� ���� ������� 
	pOldBmp = MemDC.SelectObject(&m_Bitmap); //memDC�� ��Ʈ�� ���� 
	MemDC.MoveTo(0,0); 
	MemDC.LineTo(500,200); //memDC�� �׸���.(��Ʈ�� ���� �׷�����) 
	MemDC.SelectObject(pOldBmp); //oldbmp ���� 
	MemDC.DeleteDC(); //memDC�� �����. 
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
