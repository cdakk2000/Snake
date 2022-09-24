#include "Object.h"

	Object:: Object(const Vec2 &_Pos) :Pos(_Pos) { ; }
	void Object:: Draw(char **Map, const Vec2 &Size)
	{
		if (Pos.x<0 || Pos.y<0 || Pos.x >= Size.x || Pos.y >= Size.y) return;
		Map[Pos.x][Pos.y] = GetSymbol();
	}
	Object:: ~Object() { ; }
	const Vec2& Object:: GetPos() const 
	{
		return Pos; 
	}

