#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "pos.h"
class Knight :
	public piece
{
public:
	Knight(char color) : piece(color) { name = 'N'; }
	std::vector<pos> ways(piece*** desk, pos position);

};

