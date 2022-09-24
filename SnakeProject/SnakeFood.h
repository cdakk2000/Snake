#pragma once
#include "Object.h"
class SnakeFood : public Object
{
protected:
	int Power;	//O ile zwieksza weza
public:
	SnakeFood(int _Power);	
	void Set(int x, int y);	//Ustawia pozycje
	void SetRandPos(const Vec2 &Size);	//Ustawia losowa pozycje {(x,y) : x€[0,Size.x), y€[0,Size.y)}
	virtual ~SnakeFood();	//Destruktor
	int GetPower() const;	//Zwraca warosc Power
	
};