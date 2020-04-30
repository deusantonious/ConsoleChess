#include "rock.h"


std::vector<pos> rock::ways(piece*** desk)
{
	std::vector<pos> Ways;
	int i, j;
	//up
	j = position.letter;
	for (i = position.number - 1; i >= 0; i--) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j+1, i+1));
			break;
		}
		Ways.push_back(pos(j+1, i+1));
	}
	//down
	j = position.letter;
	for (i = position.number + 1; i <= 7; i++) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j+1, i+1));
			break;
		}
		Ways.push_back(pos(j+1, i+1));
	}
	//left
	i = position.number;
	for (j = position.letter - 1; j >= 0; j--) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j+1, i+1));
			break;
		}
		Ways.push_back(pos(j+1, i+1));
	}
	//right
	i = position.number;
	for (j = position.letter + 1; j <= 7; j++) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
	}
	return Ways;
}

void rock::Display()
{
	if (color == 'W') std::cout << "WR";
	else std::cout << "BR";
}

bool rock::move(piece*** desk, pos destination)
{
	if (IsValid(desk, destination)) {
		DidMoveFirst = DidMove;
		DidMove = true;
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
	}
	else throw std::exception("Your turn is invalid!\n");
	lastPosition = position;
	position = destination;
}

void rock::undoMove()
{
	DidMove = DidMoveFirst;
	position = lastPosition;
}

bool rock::GetDidMove()
{
	return DidMove;
}
