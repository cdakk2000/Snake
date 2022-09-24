#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <ctime>

#include "Vec2.h"
class Object {
protected:
	Vec2 Pos;	//Pozyja
public:
	Object(const Vec2 &_Pos);	//Konstruktor obiektu
	void Draw(char **Map, const Vec2 &Size);	//Rysuje obiekt na mapie (o rozmiarze size)
	virtual char GetSymbol() const = 0;	//Zwraca znaczek reprezentujacy obiekt na mapie
	virtual ~Object();	//Destruktor wirtualny (Object jest klasa bazowa => wymaga destruktora wirtualnego)
	const Vec2& GetPos() const;	//Zwraca pozycje obiektu 
};

