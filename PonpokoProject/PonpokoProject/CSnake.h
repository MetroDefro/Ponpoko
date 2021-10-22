#pragma once
class CCharactor;

class CSnake
{
public:
	int y;
	int x;

	int width;
	int height;

	int delay;

	int count;

	bool direction;

	bool alive;

	CImage snakeRIMG;
	CImage snakeLIMG;

	CRect rect;

	CSnake(int x, int y);

	void Move();
	void Draw(CDC& dc);
	void Bumped(CCharactor* cha);
	void Delay();
};

