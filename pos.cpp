#include "pos.h"
pos::pos(int letter, int number)
{
	if (letter >= 8 || letter <= 0)
		throw std::exception("letter number must be from 1 to 8");
	if (number >= 8 || number <= 0)
		throw std::exception("numer number must be from 1 to 8");
	this->letter = letter - 1;
	this->number = number - 1;
}

pos::pos(char letter, int number)
{
	letter = (char)std::toupper(letter);
	if (letter > 'H' || letter < 'A')
		throw std::exception("letter must be from A to H");
	if (number > 8 || number <= 0)
		throw std::exception("number must be from 1 to 8");
	//int buff = (int)letter;
	this->letter = (int)letter-65;
	this->number = number-1;
}
