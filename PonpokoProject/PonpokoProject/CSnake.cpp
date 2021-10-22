#include "pch.h"
#include "CSnake.h"
#include "CCharactor.h"

CSnake::CSnake(int x, int y) {
	snakeRIMG.Load(L"Image\\SnakeR.png");
	snakeLIMG.Load(L"Image\\SnakeL.png");

	width = snakeRIMG.GetWidth() / 2;
	height = snakeRIMG.GetHeight();
	count = 0;
	this->x = x;
	this->y = y;

	delay = 20;

	direction = true;

	alive = false;
}
void CSnake::Move() {
	if (!alive)
		return;
	if (delay > 0)
		return;
	if (++count == 2)
		count = 0;
	if (direction)
		x -= 2;
	else
		x += 2;
	if (x >= 550)
		direction = true;
	else if (x <= 100)
		direction = false;
}
void CSnake::Draw(CDC& dc) {
	if (!alive)
		return;
	rect.SetRect(x, y, x + width, y + height);
	if (delay > 0) {
		if(delay%2 == 0)
			snakeLIMG.Draw(dc, x, y, width, height, count * width, 0, width, height);
		return;
	}
	if (direction)
		snakeLIMG.Draw(dc, x, y, width, height, count * width, 0, width, height);
	else
		snakeRIMG.Draw(dc, x, y, width, height, count * width, 0, width, height);
}
void CSnake::Delay() {
	if (!alive)
		return;
	if (delay == 0)
		return;
	delay--;
}
void CSnake::Bumped(CCharactor* cha) {
	if (!alive)
		return;
	if (delay > 0)
		return;
	CRect chaRect;
	chaRect.SetRect(cha->x, cha->y, cha->x + cha->width, cha->y + cha->height);
	CRect interRect;
	if (interRect.IntersectRect(rect, chaRect)) {
		cha->Die();
		return;
	}
}
