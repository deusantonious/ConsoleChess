#include "Knight.h"

std::vector<pos> Knight::ways(piece*** desk)
{
	std::vector<pos> Ways;
	int letter = position.letter;
	int number = position.number;
	if (letter - 1 >= 0 && number - 2 >= 0)
		if (desk[number - 2][letter - 1] == nullptr || desk[number - 2][letter - 1]->GetColor() != color)
			Ways.push_back(pos(letter, number - 1));
	//
	if (letter + 1 <= 7 && number - 2 >= 0)
		if (desk[number - 2][letter + 1] == nullptr || desk[number - 2][letter + 1]->GetColor() != color)
			Ways.push_back(pos(letter + 2, number - 1));
	//
	if (letter - 2 >= 0 && number - 1 >= 0)
		if (desk[number - 1][letter - 2] == nullptr || desk[number - 1][letter - 2]->GetColor() != color)
			Ways.push_back(pos(letter - 1, number));
	//
	if (letter + 2 <= 7 && number - 1 >= 0)
		if (desk[number - 1][letter + 2] == nullptr || desk[number - 1][letter + 2]->GetColor() != color)
			Ways.push_back(pos(letter + 3, number));
	//
	if (letter - 2 >= 0 && number + 1 <= 7)
		if (desk[number + 1][letter - 2] == nullptr || desk[number + 1][letter - 2]->GetColor() != color)
			Ways.push_back(pos(letter - 1, number + 2));
	//
	if (letter + 2 <= 7 && number + 1 <= 7)
		if (desk[number + 1][letter + 2] == nullptr || desk[number + 1][letter + 3]->GetColor() != color)
			Ways.push_back(pos(letter + 3, number + 2));
	//
	if (letter - 1 >= 0 && number + 2 <= 7)
		if (desk[number + 2][letter - 1] == nullptr || desk[number + 2][letter - 1]->GetColor() != color)
			Ways.push_back(pos(letter, number + 3));
	//
	if (letter + 1 <= 7 && number + 2 <= 7)
		if (desk[number + 2][letter + 1] == nullptr || desk[number + 2][letter + 1]->GetColor() != color)
			Ways.push_back(pos(letter + 2, number + 3));
	//
	return Ways;
}

void Knight::Display()
{
	if (color == 'W') std::cout << "WN";
	else std::cout << "BN";
}
