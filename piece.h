#pragma once
#include <vector>
#include"pos.h"
class piece
{
public:
	piece(char _color , pos _position) : color(_color), position(_position){}
	virtual bool IsValid(piece*** desk, pos destination) = 0;
	virtual bool move(piece*** desk, pos destination) = 0;
	virtual void Display() = 0;
	virtual std::vector<pos> ways(piece*** desk) = 0;
	char GetColor() { return color; };
protected:
	char color; // 'W' - white 'B' - black
	pos position;
};

