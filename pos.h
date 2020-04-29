#pragma once
#include <exception>
#include <string>
class pos
{
public:
	int letter;
	int number;
	pos();
	pos(int letter, int number);
	pos(char letter, int number);
	pos(char letter, char number);
	bool operator ==(const pos& a);
};
