#include "SnakeHead.h"
	SnakeHead::SnakeHead(const Vec2 &_Pos, int _Size)
		: Object(_Pos), Size(_Size)
	{
		Dir = 1;
		Collision = false;
	}
	void SnakeHead::Input()
	{
		if (GetAsyncKeyState(0x57)) Dir = 0; // W: 0x57
		if (GetAsyncKeyState(0x53)) Dir = 2; // S: 0x53
		if (GetAsyncKeyState(0x41)) Dir = 3; // A: 0x41
		if (GetAsyncKeyState(0x44)) Dir = 1; // D: 0x44
	}
	void SnakeHead:: Update(const Vec2 &Size)
	{ 
		Move(Size);
	}
	void SnakeHead:: IncreaseSize() 
	{
		++Size; 
	}
	void SnakeHead:: Move(const Vec2 &Size)
	{
		Vec2 Temp = Pos;
		if (Dir == 0) --Temp.y;
		else if (Dir == 2) ++Temp.y;
		else if (Dir == 1) ++Temp.x;
		else if (Dir == 3) --Temp.x;
		if (Temp.x<0 || Temp.x >= Size.x || Temp.y<0 || Temp.y >= Size.y)
		{
			Collision = true;
			return;
		}
		Pos = Temp;
	}
	char SnakeHead::GetSymbol() const
	{
		if (Dir == 0) return '^';
		else if (Dir == 1) return '>';
		else if (Dir == 2) return 'v';
		else if (Dir == 3) return '<';
		return '-';
	}
	bool SnakeHead:: IsCollision() const
	{ 
		return Collision; 
	}
	int SnakeHead:: GetSize() const 
	{ 
		return Size; 
	}
