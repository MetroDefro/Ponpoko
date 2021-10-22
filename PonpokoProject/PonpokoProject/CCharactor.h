#pragma once
class CCharactor
{
public:
	int x;
	int y;

	int width;
	int height;

	bool Right;
	bool Left;
	bool Up;
	bool Down;

	bool Gravity;
	float JumpPower;
	float JumpHeight;
	float landingHeight;
	
	bool top;
	bool inBoard;
	bool isLadder;
	bool climbing;

	int count;
	bool jump;

	bool direction;

	bool isDie;

	CImage walkImageR;
	CImage walkImageL;
	CImage jumpingImageR;
	CImage jumpingImageL;
	CImage landingImageR;
	CImage landingImageL;
	CImage climbImage;

	CImage dieImage;

	CCharactor();

	void Move();
	void Jump();
	void Jumping();
	void Fall();
	void Die();
	void Climb();
	void Draw(CDC& dc);
};

