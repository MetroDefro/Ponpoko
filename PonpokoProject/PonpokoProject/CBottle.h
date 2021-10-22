#pragma once
class CCharactor;
class CSnake;

class CBottle
{
public:
	int y;
	int x;

	int width;
	int height;

	bool drawIMG;

	CImage bottleIMG;

	CRect rect;

	CSnake* snake;

	CBottle(int x, int y);

	void Draw(CDC& dc);
	void Bumped(CCharactor* cha, int& score);
};

