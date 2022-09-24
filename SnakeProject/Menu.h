#pragma once
#include <iostream>
class Menu
{
	public:
	int State;	//Dokonany wybor w menu
	int SnakeSpeed;	//Ustawiamy predkosc weza
	int SnakeSize;	//ustawiamy rozmiar weza
	Menu();	
	void Run();	
};