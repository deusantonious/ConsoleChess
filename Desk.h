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
#include "piece.h"
class Desk
{
private:
	piece*** desk;
	bool CheckForWhite;
	bool CheckForBlack;
	void CheckWhite();
	void CheckBlack();
public: 
	Desk();
	Desk(Desk& a);
	~Desk();
	bool PreValidation(char player, pos first);
	char makeTurn(char player, pos first, pos second);
	void makeTestTurn(char player, pos first, pos second);
	void view();
};

