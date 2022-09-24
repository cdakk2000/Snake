
#include <ctime>
#include "Game.h"
int main()
{
	srand(std::time(0));
	Game MyGame;
	MyGame.Run();
}
