#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "pos.h"
class pawn :
	public piece
{
public:
	pawn(const pawn& a) : piece(a.color, a.position) { DidMove = a.DidMove; };
	pawn(char color, pos position) : piece(color,position) { DidMove = false; };
	std::vector<pos> ways(piece*** desk);
	void Display() override;
	bool move(piece*** desk, pos destination) override;
	void undoMove() override;
private:
	bool DidMoveFirst;
	bool DidMove;
};

