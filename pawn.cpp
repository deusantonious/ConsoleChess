#include "pawn.h"
//i need void that create all pos thet i can to do and ill find in IsValid;

// all ways to move void
std::vector<pos> pawn::ways(piece*** desk)
{
	std::vector<pos> Ways;
	int MaxStep;
	if (color == 'W') {
		if (!DidMove) MaxStep = -2;
		else MaxStep = -1;
	}
	else {
		if (!DidMove) MaxStep = 2;
		else MaxStep = 1;
	}
	int i = 0;
	do {
		if (MaxStep > 0) i++;
		else i--;
		if (position.number + i < 0 || position.number + i > 7) break;
		if (desk[position.number + i][position.letter] != nullptr) break;
		Ways.push_back(pos(position.letter + 1, position.number + i + 1));
	} while (i != MaxStep);

	if (MaxStep > 0) MaxStep = 1;
	else MaxStep = -1;

	if (position.letter != 0 &&
		desk[position.number+MaxStep][position.letter - 1] != nullptr
		&& desk[position.number+MaxStep][position.letter - 1]->GetColor() != color)
		Ways.push_back(pos(position.letter, position.number + 1 + MaxStep));

	if (position.letter != 7 &&
		desk[position.number + MaxStep][position.letter + 1] != nullptr
		&& desk[position.number + MaxStep][position.letter + 1]->GetColor() != color)
		Ways.push_back(pos(position.letter + 2, position.number + 1 + MaxStep));
	return Ways;
}

void pawn::Display()
{
	if (color == 'W') std::cout << "WP";
	else std::cout << "BP";
}

bool pawn::move(piece*** desk, pos destination)
{
	if (IsValid(desk, destination)) {
		DidMove = true;
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
		position = destination;
	}
	else throw std::exception("Your turn is invalid!\n");
}
