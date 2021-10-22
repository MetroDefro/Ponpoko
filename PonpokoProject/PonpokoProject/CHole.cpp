#include "pch.h"
#include "CHole.h"
#include "CCharactor.h"

CHole::CHole(int x, int y) {
	holeIMG.Load(L"Image\\Hole.png");
	width = 16;
	height = 8;

	this->x = x;
	this->y = y;
}

void CHole::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	holeIMG.Draw(dc, rect);
}

void CHole::Bumped(CCharactor* cha) {
	CRect chaRect;
	chaRect.SetRect(cha->x + 10, cha->y, cha->x + cha->width - 10, cha->y + cha->height);
	CRect bumpRect;
	bumpRect.SetRect(x + 7, y , x + width - 7, y + height);
	CRect interRect;
	if (interRect.IntersectRect(bumpRect, chaRect)) {
		cha->Die();
		return;
	}
}