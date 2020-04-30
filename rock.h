#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "rock.h"

class rock :
	public piece
{
public:
	rock(const rock& a) : piece(a.color, a.position) { DidMove = a.DidMove; }
	rock(char color, pos position) : piece(color, position) { DidMove = false; }
	std::vector<pos> ways(piece*** desk);
	void Display() override;
	bool move(piece*** desk, pos destination) override;
	void undoMove() override;
	bool GetDidMove();
private:
	bool DidMove;
	bool DidMoveFirst;
};

