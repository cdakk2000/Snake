#include "Board.h"
	Board::Board(const Vec2 &_Size)
		: Size(_Size), Head(Vec2(3, 3), 5), Food(nullptr)
	{
		//Inicjalizacja dynamicznej tablicy (mapy) z "symbolami" ('O','>','+', itd.)
		Map = new char*[Size.x + 1]; //Tworzymy o jeden rozmiar wieksza mape zeby zrobic miejsce na "entery"
		for (int i = 0; i<Size.x + 1; ++i) Map[i] = new char[Size.y];

		//Ostatnia kolumna jest z "enterami"
		for (int i = 0; i<Size.y; ++i) Map[Size.x][i] = '\n';

	}
	void Board:: Reset(int SnakeSize, int SnakeSpeed)
	{
		Elements.clear();
		if (Food) { delete Food; Food = nullptr; }

		Change = true;
		Finish = false;
		//Ustawia predkosc zalezna od tego co wybral uzytkownik (w menu jest kontrola bledow przy wyborze nieprawidlowego rozmiaru)
		if (SnakeSpeed == 0) Speed = 400;
		else if (SnakeSpeed == 1) Speed = 300;
		else if (SnakeSpeed == 2) Speed = 200;
		else if (SnakeSpeed == 3) Speed = 100;
		
		Itr = 0;
		Step = Speed;
		SpeedTime = 0;

		Head = SnakeHead(Vec2(3, 3), SnakeSize);

		for (int i = 0; i<Head.GetSize(); ++i) Elements.push_back(SnakeBody(Head.GetPos()));
		CreateFoodOnMap();
	}

	Board:: ~Board()
	{
		for (int i = 0; i<Size.x + 1; ++i) delete[] Map[i];
		delete[] Map;
	}
	void Board::Run(int SnakeSize, int SnakeSpeed)
	{
		Reset(SnakeSize, SnakeSpeed);
		while (!Finish)
		{
			Input();
			Update();
			if (Change)
			{
				Display();
				Change = false;
			}
		}
	}
	void Board:: Input()
	{
		Head.Input();
	}
	void Board::CreateFoodOnMap()
	{
		bool Flag = false; //FoodIsOnGoodPos = true
		if (Food) delete Food;
		int Rand = rand() % 100;
		if (Rand>20) Food = new TotalyNormalFood();
		else Food = new UltimateFood();
		while (!Flag)
		{
			Flag = true;
			Food->SetRandPos(Size);
			if (Head.GetPos() == Food->GetPos()) { Flag = false; continue; }//Jeœli owoc pojawi siê na g³owie to pêtla siê kontynuuje 
			for (int i = 0; i<Elements.size(); ++i)
				if (Elements[i].GetPos() == Food->GetPos()) { Flag = false; break; }
		}
	}
	void Board:: AddSegment()
	{
		Head.IncreaseSize(); //Bo w glowie "miesci" sie rozmiar weza
		Elements.insert(Elements.begin() + (Itr + 1) % Head.GetSize(), SnakeBody(Head.GetPos())); //Dodanie elementu poprzez "insert"
	}
	bool Board:: CheckCollision()
	{
		//Czy kolizja z granica mapy
		if (Head.IsCollision()) return true;
		//Czy kolizja z innym elementem ciala
		for (int i = 0; i<Elements.size(); ++i)
			if (Head.GetPos() == Elements[i].GetPos()) return true;
		if (Food->GetPos() == Head.GetPos())
		{
			for (int i = 0; i<Food->GetPower(); ++i) AddSegment();
			if (dynamic_cast<UltimateFood*>(Food)) SpeedTime += 5;
			CreateFoodOnMap();
		}
		return false;
	}
	void Board:: Update()
	{
		if (SpeedTime>0) Step = Speed / 2; else Step = Speed;
		if (std::clock() - Time > Step)
		{
			if (SpeedTime>0) --SpeedTime;
			Time = std::clock();
			Change = true;

			++Itr; // Size=5 -> Itr = 0 1 2 3 4 0 1 2 3 4 0 1...
			Itr %= Head.GetSize();
			

			if (!Finish)
			{
				Elements[Itr] = SnakeBody(Head.GetPos());
				Head.Update(Size); //Ruch glowy
				Finish = CheckCollision(); //Sprawdzanie kolizji glowy z innymi rzeczami
										   //if(Food.GetPos()==Head.GetPos()) EatFood(); //Jezeli glowa jest na pozycji owoca -> jedz owoc
			}
		}
	}
	void Board:: Display()
	{
		for (int i = 0; i<Size.x; ++i)
			for (int j = 0; j<Size.y; ++j) Map[i][j] = '.';

		
		for (int i = 0; i<Elements.size(); ++i) Elements[i].Draw(Map, Size);

		Head.Draw(Map, Size);
		Food->Draw(Map, Size);

		system("cls");

		std::string StringMap;

		for (int i = 0; i<Size.y; ++i)
			for (int j = 0; j<Size.x + 1; ++j) StringMap += Map[j][i];

		std::cout << StringMap;
		
	}

