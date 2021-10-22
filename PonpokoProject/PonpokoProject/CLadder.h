#pragma once
class CCharactor;

class CLadder
{
public:
	int y;
	int x;

	int width;
	int height;

	CImage ladderIMG;

	CRect rect;

	CLadder(int x, int y);

	void Draw(CDC& dc);
	bool Bumped(CCharactor* cha);
};

