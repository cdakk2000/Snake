#include "SnakeFood.h"

	SnakeFood::SnakeFood(int _Power) : Object(Vec2(0, 0)), Power(_Power) { ; }
	void SnakeFood:: Set(int x, int y)
	{ 
		Pos.Set(x, y); 
	}
	void SnakeFood:: SetRandPos(const Vec2 &Size) 
	{ 
		Pos.Set(rand() % Size.x, rand() % Size.y); 
	}
	SnakeFood:: ~SnakeFood() { ; }
	int SnakeFood::GetPower() const 
	{ 
		return Power; 
	}
