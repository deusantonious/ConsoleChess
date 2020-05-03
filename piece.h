#pragma once
#include <vector>
#include <iostream>
#include"pos.h"
class piece
{
public:
	piece(char _color) : color(_color){}
	bool IsValid(piece*** desk, pos position, pos destination);
	virtual bool move(piece*** desk, pos position, pos destination);
	virtual std::vector<pos> ways(piece*** desk, pos position) = 0;
	void Display();
	char GetColor() { return color; };
	char name;
protected:
	char color;

};


