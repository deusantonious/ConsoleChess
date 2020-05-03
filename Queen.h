#pragma once
#include "piece.h"
#include "pos.h"
#include <iostream>
#include <vector>
class Queen : public piece
{
public:
	Queen(char color) : piece(color) { name = 'Q'; }
	std::vector<pos> ways(piece*** desk, pos position);
};

