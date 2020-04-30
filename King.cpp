#include "King.h"

std::vector<pos> King::ways(piece*** desk)
{
	std::vector<pos> Ways;
	//castling
	if (!DidMove) {
		//left rock
		if (desk[position.number][0] != nullptr && typeid(*desk[position.number][0]) == typeid(rock)) {
			if (dynamic_cast<rock*>(desk[position.number][0])->GetDidMove() == false) {
				int buff = 0;
				for (int i = 3; i > 0; i--)
					if (desk[position.number][i] == nullptr)
						buff++;
				if (buff == 3)
					Ways.push_back(pos(1, position.number+1));
			}
		}
		//right rock
		if (desk[position.number][7] != nullptr && typeid(*desk[position.number][7]) == typeid(rock)) {
			if (dynamic_cast<rock*>(desk[position.number][7])->GetDidMove() == false) {
				if (desk[position.number][5] == nullptr && desk[position.number][6] == nullptr)
					Ways.push_back(pos(8, position.number + 1));
			}
		}
	}
	//down
	if (position.number != 7) {
		//down
		if (desk[position.number + 1][position.letter] == nullptr || desk[position.number + 1][position.letter]->GetColor() != color)
			Ways.push_back(pos(position.letter + 1, position.number + 2));
		//right
		if (position.letter != 7)
			if (desk[position.number + 1][position.letter + 1] == nullptr || desk[position.number + 1][position.letter + 1]->GetColor() != color)
				Ways.push_back(pos(position.letter + 2, position.number + 2));
		//left
		if (position.letter != 0)
			if (desk[position.number + 1][position.letter + 1] == nullptr || desk[position.number + 1][position.letter + 1]->GetColor() != color)
				Ways.push_back(pos(position.letter + 2, position.number + 2));
	}
	//up
	if (position.number != 0) {
		//down
		if (desk[position.number - 1][position.letter] == nullptr || desk[position.number - 1][position.letter]->GetColor() != color)
			Ways.push_back(pos(position.letter + 1, position.number));
		//right
		if (position.letter != 7)
			if (desk[position.number - 1][position.letter + 1] == nullptr || desk[position.number - 1][position.letter + 1]->GetColor() != color)
				Ways.push_back(pos(position.letter + 2, position.number));
		//left
		if (position.letter != 0)
			if (desk[position.number - 1][position.letter - 1] == nullptr || desk[position.number - 1][position.letter + 1]->GetColor() != color)
				Ways.push_back(pos(position.letter, position.number));
	}
	//full left
	if (position.letter != 0)
		if (desk[position.number][position.letter - 1] == nullptr || desk[position.number][position.letter - 1]->GetColor() != color)
			Ways.push_back(pos(position.letter, position.number + 1));
	//full right
	if (position.letter != 7)
		if (desk[position.number][position.letter + 1] == nullptr || desk[position.number][position.letter + 1]->GetColor() != color)
			Ways.push_back(pos(position.letter + 2, position.number + 1));
	return Ways;
}

void King::Display()
{
	if (color == 'W') std::cout << "WK";
	else std::cout << "BK";
}

bool King::move(piece*** desk, pos destination)
{
	if (IsValid(desk, destination)) {
		DidMoveFirst = DidMove;
		DidMove = true;
		if (desk[destination.number][destination.letter] != nullptr && typeid(*desk[destination.number][destination.letter]) == typeid(rock)) {
			if (destination.letter == 0) {
				desk[destination.number][destination.letter]->move(desk, pos(4, position.number + 1));
				desk[position.number][position.letter - 2] = this;
			}
			else {
				desk[destination.number][destination.letter]->move(desk, pos(6, position.number + 1));
				desk[position.number][position.letter + 2] = this;

			}
			lastPosition = destination;
			desk[destination.number][destination.letter] = nullptr;
			desk[position.number][position.letter] = nullptr;
			position.letter += 2;
			return true;
			lastWasCastling = true;
		}
		lastWasCastling = false;
		lastPosition = position;
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
		position = destination;
	}
	else throw std::exception("Your turn is invalid!\n");
}

void King::undoMove()
{
	DidMove = DidMoveFirst;
	if (lastWasCastling) {

	}
	else {
		position = lastPosition;
	}
}

bool King::checkTest(piece*** desk)
{
	std::vector <pos> buff;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (desk[i][j] != nullptr && desk[i][j]->GetColor() != color) {
				buff = desk[i][j]->ways(desk);
				for (pos i : buff) {
					if (position == i)
						return true;
					//to do mate check
				}
			}

	}
	return false;
}
