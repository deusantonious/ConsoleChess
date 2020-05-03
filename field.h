#pragma once
#include <iostream>
class field
{
public:
	field() { color = '0'; }
	field(char _color) :color(_color) {}
	virtual void Display();
	char GetColor() { return color; };
	char color; // 'W' - white 'B' - black '0; - emptyCell
};