#include "Menu.h"
	Menu::Menu()
	{
		State = 0;
		SnakeSpeed = 1;
		SnakeSize = 5;
		
	} 
	void Menu:: Run()
	{
		while (true)
		{
			if (State == 0)
			{
				std::cout << "-------------\n";
				std::cout << "[1]: Rozpocznij gre\n";
				std::cout << "[2]: Opcje\n";
				std::cout << "[3]: Wyjscie z gry\n";
				std::cout << "-------------\n";
				std::cout << "\n Poczatkowy rozmiar weza: " << SnakeSize << "\n Poczatkowa szybkosc weza: " << SnakeSpeed << '\n';
				std::cout << "-------------\n";
				char Option;
				std::cin >> Option;
				if (Option == '1') //Rozpocznij gre
				{
					State = 2;
					system("cls");
				}
				else if (Option == '2') //Opcje
				{
					State = 1;
					system("cls");
				}
				else if (Option == '3') //Wyjscie
				{
					State = 3;
					system("cls");
				}
			}
			else if (State == 1)
			{
				std::cout << "-------------\n";
				std::cout << "Podaj poczatkowy rozmiar weza (n>2): ";
				
				while (true)
				{
					std::cin >> SnakeSize;
					if (SnakeSize>2) break;
					else
					{
						std::cout << "-------------\n";
						std::cout << "Podales zly rozmiar weza. Sprobuj ponownie\n";
					}
				}
				std::cout << "-------------\n";
				std::cout << "Podaj poczatkowa predkosc [od 0 do 3]: ";
				while (true)
				{
				std::cin >> SnakeSpeed;
				if (SnakeSpeed <= 3 && SnakeSpeed >= 0) break;
				else
				{
					std::cout << "-------------\n";
					std::cout << "Podales nieprawidlowa predkosc weza. Sprobuj ponownie\n";
				}
				}
				
				State = 0;
				system("cls");
			}
			else if (State == 2 || State == 3) break;
		}
	}
