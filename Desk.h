#pragma once
#include <iomanip>
#include <iostream>
#include "pos.h"
#include <math.h>
class Desk
{
private:
	int desk[8][8]{
		{-1,-3,-4,-5,-6,-4,-3,-1},
		{-8,-8,-8,-8,-8,-8,-8,-8},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{8,8,8,8,8,8,8,8},
		{1,3,4,5,6,4,3,1}
	};
	
	char CheckStatus();
	char CheckMateStatus();
	//return codes for GetTurnType
	//'0' - moove
	//'1' - eat
	//'2' - castling
	//'3' - pawn replacement
	char GetTurnType(char color, pos first, pos second);
public: 
	bool ValidateTurnWhite(pos first, pos second);
	void view();
	bool WhiteMakesTurn(pos first, pos second);

};

