#pragma once
#include "Object.h"
class SnakeHead : public Object
{
	int Dir; //0:Gora, 1:Prawo, 2:Dol, 3:Lewo
	bool Collision;	//Czy glowa siedzi w scianie, kolizja ze sciana
	int Size;	//Glowa przechowuje rozmiar weza
public:
	SnakeHead(const Vec2 &_Pos, int _Size);	//Konstruktor
	void Input();	//Ustawia kierunek glowy weza zaleznie od nacisnietego przycisku [W][S][A][D]
	void Update(const Vec2 &Size);	//Glowna aktualizacja glowy
	void IncreaseSize();	//Inkrementuje wartosc zmiennej Size
	void Move(const Vec2 &Size);	//Ruch weza (zmienia pozycje weza zaleznie od ustawionego kierunku (Dir))
	char GetSymbol() const;	
	bool IsCollision() const;	//Zwraca wartosc zmiennej Collision
	int GetSize() const;	//Zwraca wartosc zmiennej Size
};