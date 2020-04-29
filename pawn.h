#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "pos.h"
class pawn :
	public piece
{
public:
	pawn(char color, pos position) : piece(color,position) { DidMove = false; };
	bool  IsValid(piece*** desk, pos destination) override;
	std::vector<pos> ways(piece*** desk);
	void Display() override;
	bool move(piece*** desk, pos destination) override;
private:
	bool DidMove;
};

