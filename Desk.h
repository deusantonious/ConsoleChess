#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
#include <exception>
#include "pos.h"
#include "piece.h"
#include "pawn.h"
#include "rock.h"
#include "Knight.h"
class Desk
{
private:
	piece ***desk;

	//char CheckStatus();
	//char CheckMateStatus();
	//return codes for GetTurnType
	//'0' - move
	//'1' - eat
	//'2' - castling
	//'3' - pawn replacement
	//char GetTurnType(char color, pos first, pos second);
public: 
	Desk();
	~Desk();
	bool PreValidation(char player, pos first);
	char makeTurn(char player, pos first, pos second);
	//bool ValidateTurnWhite(pos first, pos second);
	void view();
	//bool WhiteMakesTurn(pos first, pos second);

};

