#include "pch.h"
#include "CThorn.h"
#include "CCharactor.h"

CThorn::CThorn(int x, int y) {
	thornIMG.Load(L"Image\\ThornIMG.png");

	width = thornIMG.GetWidth();
	height = thornIMG.GetHeight();
	this->x = x;
	this->y = y;

	//충돌 범위
	bumpRect.SetRect(x + 7, y + 13, x + 8, y + height);
}

void CThorn::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	thornIMG.Draw(dc, rect);
}

void CThorn::Bumped(CCharactor* cha) {
	CRect chaRect;
	chaRect.SetRect(cha->x, cha->y, cha->x + cha->width, cha->y + cha->height);
	CRect interRect;
	if (interRect.IntersectRect(bumpRect, chaRect)) {
		cha->Die();
		return;
	}
}