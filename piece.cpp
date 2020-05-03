#include "piece.h"

bool piece::IsValid(piece*** desk, pos position, pos destination)
{

	std::vector <pos> Aviable = this->ways(desk, position);
	for (pos i : Aviable)
		if (i == destination)
			return true;
	return false;

}

bool piece::move(piece*** desk, pos position, pos destination)
{

	if (IsValid(desk, position, destination)) {
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
	}
	else throw std::exception("Your turn is invalid!\n");
	return true;
}

void piece::Display()
{
	std::cout << color << name;
}
