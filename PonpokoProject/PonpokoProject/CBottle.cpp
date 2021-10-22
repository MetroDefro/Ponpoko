#include "pch.h"
#include "CBottle.h"
#include "CCharactor.h"
#include "CSnake.h"
#include <stdlib.h>

CBottle::CBottle(int x, int y) {
	bottleIMG.Load(L"Image\\Bottle.png");

	width = bottleIMG.GetWidth();
	height = bottleIMG.GetHeight();

	drawIMG = true;

	snake = new CSnake(x, y + 4);

	this->x = x;
	this->y = y;
	srand(2);
}

void CBottle::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	if(drawIMG)
		bottleIMG.Draw(dc, rect);
	snake->Draw(dc);
}

void CBottle::Bumped(CCharactor* cha, int& score) {
	snake->Bumped(cha);
	snake->Move();
	snake->Delay();
	if (!drawIMG)
		return;
	CRect chaRect;
	chaRect.SetRect(cha->x, cha->y, cha->x + cha->width, cha->y + cha->height);
	CRect interRect;
	if (interRect.IntersectRect(rect, chaRect)) {
		score += 100;
		if(rand()%2 == 0)
			snake->alive = true;
		else
			drawIMG = false;
		return;
	}
}