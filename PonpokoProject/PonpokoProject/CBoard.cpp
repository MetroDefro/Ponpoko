#include "pch.h"
#include "CBoard.h"
#include "CCharactor.h"

CBoard::CBoard(int x, int y, int size) {
	boardIMG.Load(L"Image\\BoardIMG.png");

	rect = new CRect[size];
	this->size = size;
	this->x = x;
	this->y = y;

	width = boardIMG.GetWidth();
	height = boardIMG.GetHeight();

}

void CBoard::Draw(CDC& dc) {
	for (int i = 0; i < size; i++) {
		rect[i].SetRect(x + (i * width), y, x + (i * width) + width, y + height);
		boardIMG.Draw(dc, rect[i]);
	}
}

bool CBoard::Bumped(CCharactor* cha) {
	CRect chaRect;
	chaRect.SetRect(cha->x + 12, cha->y + 30, cha->x + cha->width - 12, cha->y + cha->height);
	CRect interRect;
	for (int i = 0; i < size; i++) {
		if (interRect.IntersectRect(rect[i], chaRect)) {
			cha->y = rect[i].TopLeft().y - cha->width;
			cha->inBoard = true;
			cha->climbing = false;
			return true;
		}
	}
	return false;
}
