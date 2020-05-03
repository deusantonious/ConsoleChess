#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "piece.h"
#include "pos.h"
class Bishop :
	public piece
{
public:
	Bishop(char color) : piece(color) { name = 'B'; }
	std::vector<pos> ways(piece*** desk, pos position);
};

