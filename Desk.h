#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
#include <exception>
#include "pos.h"
#include "piece.h"
#include "pawn.h"
#include "rock.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
class Desk
{
private:
	piece ***desk;
	bool CheckForWhite;
	bool CheckForBlack;
	void FillCheckStatus();
public: 
	Desk();
	Desk(const Desk& New);
	Desk operator =(const Desk& second);
	~Desk();
	bool PreValidation(char player, pos first);
	char makeTurn(char player, pos first, pos second);
	void view();
};

