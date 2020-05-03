#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "pos.h"
class pawn :
	public piece
{
public:
	pawn(char color) : piece(color) { DidMove = false; name = 'P'; };
	std::vector<pos> ways(piece*** desk, pos position);
	bool move(piece*** desk, pos position, pos destination) override;
private:
	bool DidMove;
};

