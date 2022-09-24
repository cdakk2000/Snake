#include "UltimateFood.h"

	UltimateFood::UltimateFood() : SnakeFood(3) { ; }
	char UltimateFood:: GetSymbol() const 
	{ 
		return static_cast<char>(254); 
	}
