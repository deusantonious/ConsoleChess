#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
class king;
class rock :
	public piece
{
public:
	rock(char color, pos position) : piece(color, position) { DidMove = false; };
	std::vector<pos> ways(piece*** desk);
	void Display() override;
	bool move(piece*** desk, pos destination) override;
private:
	bool RockDidMove();
	bool DidMove;
};

