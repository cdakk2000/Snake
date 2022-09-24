#include "Vec2.h"

	
	Vec2::Vec2() :x(0), y(0) { ; }
	Vec2::Vec2(int _x, int _y) :x(_x), y(_y) { ; }
	Vec2::Vec2(const Vec2 &Obj) :x(Obj.x), y(Obj.y) { ; }
	void Vec2:: Set(int _x, int _y) { x = _x; y = _y; }
	bool Vec2:: operator==(const Vec2 &Obj) const 
	{ 
		return (x == Obj.x && y == Obj.y); 
	}
