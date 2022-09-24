#pragma once
#include "UltimateFood.h"
#include "SnakeFood.h"
class UltimateFood : public SnakeFood
{
public:
	UltimateFood();	
	char GetSymbol() const;	
};
