#pragma once
#include "piece.h"
#include "pos.h"
#include <iostream>
#include <vector>
class Queen : public piece
{
public:
	Queen& operator = (const Queen a);
	Queen(const Queen& a) : piece(a.color, a.position) {
		std::cout << "hi";
	}
	Queen(char color, pos position) : piece(color, position) {}
	std::vector<pos> ways(piece*** desk);
	void Display() override;
};

