#pragma once
#include <iostream>
#include <vector>
#include "pos.h"
#include "piece.h"
#include "rock.h"
class King : public piece
{
public:
	King(char color) : piece(color) { DidMove = false; name = 'K'; };
	std::vector<pos> ways(piece*** desk, pos position);
	bool move(piece*** desk, pos position, pos destination) override;
	bool checkTest(piece*** desk, pos position);
private:
	bool lastWasCastling;
	bool DidMoveFirst;
	bool DidMove;
};

