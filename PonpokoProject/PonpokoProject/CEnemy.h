#pragma once
class CCharactor;

class CEnemy
{
public:
	int y;
	int x;

	int width;
	int height;

	int count;

	bool direction;

	CImage enemyRIMG;
	CImage enemyLIMG;

	CRect rect;

	CEnemy(int x, int y);

	void Move();
	void Draw(CDC& dc);
	void Bumped(CCharactor* cha);
};

