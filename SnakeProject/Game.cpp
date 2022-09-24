#include "Game.h"
#include "Vec2.h"

Game::Game()
	: MyBoard(Vec2(20,20))
{

}

	void Game:: Run()
	{
		system("cls");
		while (true)
		{
			MyMenu.State = 0;	//Jezeli wczesniej wybralismy np. start to zeby po przegranej natychmiast nie zaczal nowej gry ustawiamy, ze w menu nie zostal dokonany zaden wybor
			MyMenu.Run();
			if (MyMenu.State == 3) break;
			MyBoard.Run(MyMenu.SnakeSize, MyMenu.SnakeSpeed);
			system("cls");
		}
	}
