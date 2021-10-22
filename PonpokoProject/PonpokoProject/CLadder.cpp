#include "pch.h"
#include "CLadder.h"
#include "CCharactor.h"
#include <list>

CLadder::CLadder(int x, int y) {
	ladderIMG.Load(L"Image\\LadderIMG.png");

	width = ladderIMG.GetWidth();
	height = ladderIMG.GetHeight();
	//추후 x, y 랜덤 생성
	this->x = x;
	this->y = y;
	//충돌 범위

}

void CLadder::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	ladderIMG.Draw(dc, rect);
}

bool CLadder::Bumped(CCharactor* cha) {
	CRect chaRect;
	chaRect.SetRect(cha->x + 12, cha->y, cha->x + cha->width - 12, cha->y + 23);
	CRect headRect;
	headRect.SetRect(cha->x + 12, cha->y, cha->x + cha->width - 12, cha->y + 21);
	CRect footRect;
	footRect.SetRect(cha->x + 12, cha->y + 30, cha->x + cha->width - 12, cha->y + cha->height);
	CRect interRect;
	CRect bumpRect;


	bumpRect.SetRect(x, y, x + width, y + height - 28);
	if (interRect.IntersectRect(bumpRect, chaRect)) {
		cha->isLadder = true;
		if (!interRect.IntersectRect(headRect, bumpRect) && interRect.IntersectRect(footRect, bumpRect)) {
			cha->top = true;
			cha->climbing = false;
		}
		else
			cha->top = false;
		return true;
	} else
		return false;
}
