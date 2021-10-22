#pragma once
class CCharactor;

class CThorn
{
public:
	int y;
	int x;

	int width;
	int height;

	CImage thornIMG;

	CRect rect;
	CRect bumpRect;

	CThorn(int x, int y);

	void Draw(CDC& dc);
	void Bumped(CCharactor* cha);
};

