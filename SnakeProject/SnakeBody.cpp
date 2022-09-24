#include "SnakeBody.h"

	SnakeBody::SnakeBody(const Vec2 &_Pos) :Object(_Pos) { ; }
	char SnakeBody::GetSymbol() const
	{
		return 'O';
	}
