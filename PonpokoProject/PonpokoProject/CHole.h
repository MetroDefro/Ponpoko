#pragma once
class CCharactor;

class CHole
{
public:
	int y;
	int x;

	int width;
	int height;

	CRect rect;
	CImage holeIMG;

	CHole(int x, int y);

	void Draw(CDC& dc);
	void Bumped(CCharactor* cha);
};

