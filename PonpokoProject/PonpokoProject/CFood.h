#pragma once
class CCharactor;

class CFood
{
public:
	int y;
	int x;

	int width;
	int height;

	CImage foodIMG;

	CRect rect;

	CFood(int x, int y);

	void Draw(CDC& dc);
	void Bumped(CCharactor* cha, int& score, int& foodY);
};

