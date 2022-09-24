#pragma once
#include <string>
#include "Vec2.h"
#include "SnakeHead.h"
#include "SnakeBody.h"
#include "SnakeFood.h"
#include "TotalyNormalFood.h"
#include "UltimateFood.h"
class Board
{
	Vec2 Size;	//Rozmiar mapy
	char **Map;	//Mapa (tablica charów)
	int Time;	//Sluzy do symulacji "tickow" ruchu weza (pobieramy czas co Tick)
	int Itr;	//Indeks elementu weza, ktory bedzie zastepiony w nastepnym wstawieniu nowego elementu (w momencie zebrania punktu)
	bool Finish;	//Czy rozgrywka jest zakonczona (Game over)
	bool Change;	//Czy mapa zostala zaktualizowana (cos sie zmienilo) | Jezeli nastapi tick Change=true | Jezeli true => aktualizuj Map + ustaw na false
	int Step;	//Okresla co ile nastepuje Tick (w warunku std::clock()-Time>Step) gdzie: Time=czas ostatnio wykonanego ticku | zmienia sie zaleznie od warunku SpeedTime>0
	int SpeedTime;	//Ilosc tickow pozostalych do konca ruchu przyspieszonego 
	int Speed;	//Startowa predkosc weza (jezeli zostanie zebrany ultimate food ta wartosc NIE ulega zmianie)

	std::vector<SnakeBody> Elements;	//Segmenty weza (bez glowy)
	SnakeHead Head;	//G³owa weza
	SnakeFood *Food;	//Jedzenie (wskaznik bo uzywamy polimorfizmu/tworzymy SnakeFood przy pomocy new, ktore zwraca adres, a nie obiekt)

public:
	Board(const Vec2 &_Size);	//Konstruktor planszy
	void Reset(int SnakeSize, int SnakeSpeed);	//Resetuje status mapy (mozna wywolac w celu zresetowania gry, NIE ustala rozmiaru planszy!)
	~Board();	//Destruktor planszy (m.in. zwalnia pamiec zajmowana przez owocek)
	void Run(int SnakeSize, int SnakeSpeed);	//Uruchamia glowna petle gry (bardziej planszy bo bez menu, dlatego klasa nazywa sie board a nie game)
	void Input();	//Pobiera i aktualizuje wejscie z klawiatury
	void CreateFoodOnMap();	//Tworzy nowy owoc na mapie (i zwalnia pamiec starego [usuwa go]), z kontrola pozycji by nie stworzyl sie na wezu
	void AddSegment();	//Dodaje nowy segment weza
	bool CheckCollision();	//Sprawdza czy glowa koliduje z: cialem, owockiem, granica mapy 
	void Update();	//Logika calej planszy (wywoluje wszystke metody zwiazane z aktualizacja/logika [te wyzej])
	void Display();	//Render calej planszy (rysuje plansze na ekranie z wezem)
};
