#pragma once
#include <iostream>
#include <vector>
class Vec2
{
public:
	int x, y; 
	Vec2();	//Konstruktor domyslny (zeruje x i y)
	Vec2(int _x, int _y);	//Drugi konstruktor
	Vec2(const Vec2 &Obj);	//Konstruktor kopiujacy
	void Set(int _x, int _y);	//ustawia x i y
	bool operator==(const Vec2 &Obj) const;	//Przeciazenie operatora przyrownania (zwraca true gdy x==Inny.x && y==Inny.y)
};