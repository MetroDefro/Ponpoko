#include "pch.h"
#include "CCharactor.h"

CCharactor::CCharactor() {
	walkImageR.Load(L"Image\\CharWalkR.png");
	walkImageL.Load(L"Image\\CharWalkL.png");
	jumpingImageR.Load(L"Image\\JumpingR.png");
	jumpingImageL.Load(L"Image\\JumpingL.png");
	landingImageR.Load(L"Image\\landingR.png");
	landingImageL.Load(L"Image\\landingL.png");
	climbImage.Load(L"Image\\ClimbIMG.png");
	dieImage.Load(L"Image\\DeadIMG.png");
	Right = false;
	Left = false;
	jump = false;
	inBoard = false;
	isDie = false;
	climbing = false;

	JumpPower = 6;
	Gravity = 2;
	count = 0;
	width = walkImageR.GetWidth() / 7;
	height = walkImageR.GetHeight();
	x = 540;
	y = 392;

	Up = false;
	Down = false;
	isLadder = false;

	direction = true;

}

void CCharactor::Move() {
	if (isDie)
		return;
	if (climbing)
		return;
	if (!Right && !Left)
		return;
	if (jump)
		return;
	if (Right) {
		if (++count == 6)
			count = 0;
		direction = true;
		if(x > 100)
			x -= 5;
	}
	else if (Left) {
		if (++count == 6)
			count = 0;
		direction = false;
		if(x < 550)
			x += 5;
	}
}

void CCharactor::Fall() {
	if (jump)
		return;
	if (isLadder)
		return;
	if (inBoard)
		return;
	y += 5;
}

void CCharactor::Jumping() {
	if (isDie)
		return;
	if (climbing)
		return;
	if (jump) {
		if (direction) {
			if (x > 100) {
				if (Right || Left)
					x -= 8;
				else
					x -= 4;
			}
		}
		else
			if (x < 550) {
				if (Right || Left)
					x += 8;
				else
					x += 4;
			}
		y -= JumpHeight;
		JumpHeight -= Gravity;
		if (JumpHeight <= 0) {
			y += landingHeight;
			landingHeight += Gravity;
			if(landingHeight >= JumpPower)
				jump = false;
		}
	}
}

void CCharactor::Jump() {
	if (isDie)
		return;
	if (jump)
		return;
	jump = true;
	JumpHeight = JumpPower;
	landingHeight = 0;
}

void CCharactor::Die(){
	isDie = true;
}

void CCharactor::Climb() {
	if (isDie)
		return;
	if (jump)
		return;
	if (isLadder) {
		if (Up) {
			if (top&&inBoard)
				return;
			if (!inBoard&&!climbing)
				return;
			if (++count >= 3)
				count = 0;
			climbing = true;
			y -= 5;
		}
		else if (Down) {
			if (++count >= 3)
				count = 0;
			climbing = true;
			y += 5;
		}
	}
}

void CCharactor::Draw(CDC& dc) {
	if (isDie) {
		dieImage.Draw(dc, x, y, width, height, 0, 0, width, height);
		return;
	}
	
	if (climbing) {
		climbImage.Draw(dc, x, y, width, height, count * width, 0, width, height);
		return;
	}

	if (direction) {
		if (jump) {
			if (JumpHeight <= 0)
				landingImageL.Draw(dc, x, y, width, height, 0, 0, width, height);
			else
				jumpingImageL.Draw(dc, x, y, width, height, 0, 0, width, height);
		}
		else
			if(Right || Left)
				walkImageL.Draw(dc, x, y, width, height, count * width, 0, width, height);
			else
				walkImageL.Draw(dc, x, y, width, height, width, 0, width, height);
	}
	else {
		if (jump) {
			if (JumpHeight <= 0)
				landingImageR.Draw(dc, x, y, width, height, 0, 0, width, height);
			else
				jumpingImageR.Draw(dc, x, y, width, height, 0, 0, width, height);
		}
		else
			if (Right || Left)
				walkImageR.Draw(dc, x, y, width, height, count * width, 0, width, height);
			else
				walkImageR.Draw(dc, x, y, width, height, width, 0, width, height);
	}
}