#include "piece.h"

bool piece::IsValid(piece*** desk, pos destination)
{

	std::vector <pos> Aviable = this->ways(desk);
	for (pos i : Aviable)
		if (i == destination) return true;
	return false;

}

bool piece::move(piece*** desk, pos destination)
{

	if (IsValid(desk, destination)) {
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
		position = destination;
	}
	else throw std::exception("Your turn is invalid!\n");

}
