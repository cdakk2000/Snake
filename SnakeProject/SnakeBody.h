#pragma once
#include "Object.h"
#include "Vec2.h"
class SnakeBody : public Object
{
public:
	SnakeBody(const Vec2 &_Pos); 
	char GetSymbol() const;	
};