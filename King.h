#pragma once
#include <iostream>
#include <vector>
#include "pos.h"
#include "piece.h"
#include "rock.h"
class King : public piece
{
public:
	King(const King& a) : piece(a.color, a.position) { DidMove = a.DidMove; };
	King(char color, pos position) : piece(color, position) { DidMove = false; };
	std::vector<pos> ways(piece*** desk);
	void Display() override;
	bool move(piece*** desk, pos destination) override;
	void undoMove();
	bool checkTest(piece*** desk);
private:
	bool lastWasCastling;
	bool DidMoveFirst;
	bool DidMove;
};

