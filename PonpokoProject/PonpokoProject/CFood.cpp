#include "pch.h"
#include "CFood.h"
#include "CCharactor.h"

CFood::CFood(int x, int y) {
	foodIMG.Load(L"Image\\Food.png");

	width = foodIMG.GetWidth();
	height = foodIMG.GetHeight();

	this->x = x;
	this->y = y;
}

void CFood::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	foodIMG.Draw(dc, rect);
}

void CFood::Bumped(CCharactor* cha, int& score, int& clearCount) {
	CRect chaRect;
	chaRect.SetRect(cha->x, cha->y, cha->x + cha->width, cha->y + cha->height);
	CRect interRect;
	if (interRect.IntersectRect(rect, chaRect)) {
		score += 100;
		x = 600;
		y = 100 + clearCount * 50;
		clearCount++;
		return;
	}
}
