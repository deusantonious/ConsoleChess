#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "rock.h"

class rock :
	public piece
{
public:
	rock(char color) : piece(color) { DidMove = false; name = 'R'; }
	std::vector<pos> ways(piece*** desk, pos position);
	bool move(piece*** desk, pos position, pos destination) override;
	bool GetDidMove();
private:
	bool DidMove;
};

