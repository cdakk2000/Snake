#pragma once
#include "Menu.h"
#include "Board.h"
class Game
{
	Menu MyMenu;	
	Board MyBoard;	
public:
	Game();	
	void Run();	
};