#pragma once
#include <iostream>
#include <vector>
#include "piece.h"
#include "pos.h"
class Bishop :
	public piece
{
public:
	Bishop(const Bishop& a) : piece(a.color, a.position) {};
	Bishop(char color, pos position) : piece(color, position) {}
	std::vector<pos> ways(piece*** desk);
	void Display() override;
};

