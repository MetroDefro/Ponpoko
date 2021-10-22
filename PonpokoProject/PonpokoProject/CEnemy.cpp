#include "pch.h"
#include "CEnemy.h"
#include "CCharactor.h"

CEnemy::CEnemy(int x, int y) {
	enemyRIMG.Load(L"Image\\EnemyR.png");
	enemyLIMG.Load(L"Image\\EnemyL.png");

	width = enemyRIMG.GetWidth() / 2;
	height = enemyRIMG.GetHeight();
	count = 0;
	this->x = x;
	this->y = y;

	direction = true;
}
void CEnemy::Move() {
	if (++count == 2)
		count = 0;
	if (direction)
		x -= 3;
	else
		x += 3;
	if (x >= 550)
		direction = true;
	else if (x <= 100)
		direction = false;
}
void CEnemy::Draw(CDC& dc) {
	rect.SetRect(x, y, x + width, y + height);
	if(direction)
		enemyLIMG.Draw(dc, x, y, width, height, count * width, 0, width, height);
	else
		enemyRIMG.Draw(dc, x, y, width, height, count * width, 0, width, height);
}

void CEnemy::Bumped(CCharactor* cha) {
	CRect chaRect;
	chaRect.SetRect(cha->x, cha->y, cha->x + cha->width, cha->y + cha->height);
	CRect interRect;
	if (interRect.IntersectRect(rect, chaRect)) {
		cha->Die();
		return;
	}
}
