#pragma once
#include <vector>
#include"pos.h"
class piece
{
public:
	piece(char _color , pos _position) : color(_color), position(_position){}
	bool IsValid(piece*** desk, pos destination);
	virtual bool move(piece*** desk, pos destination);
	virtual void Display() = 0;
	virtual std::vector<pos> ways(piece*** desk) = 0;
	char GetColor() { return color; };
protected:
	char color; // 'W' - white 'B' - black
	pos position;
};

