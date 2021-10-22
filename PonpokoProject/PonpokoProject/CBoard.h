#pragma once
class CCharactor;

class CBoard
{
public:
	int y;
	int x;

	int width;
	int height;
	int size;


	CImage boardIMG;

	CRect* rect;

	CBoard(int x, int y, int size);

	void Draw(CDC& dc);
	bool Bumped(CCharactor* cha);
};

