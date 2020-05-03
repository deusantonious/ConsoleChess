#include "rock.h"


std::vector<pos> rock::ways(piece*** desk, pos positon)
{
	std::vector<pos> Ways;
	/*int i, j;
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
	}*/
	return Ways;
}
bool rock::move(piece*** desk, pos position, pos destination)
{
	if (IsValid(desk, position, destination)) {
		DidMove = true;
		desk[destination.number][destination.letter] = this;
		desk[position.number][position.letter] = nullptr;
	}
	else throw std::exception("Your turn is invalid!\n");
	return true;
}
bool rock::GetDidMove()
{
	return DidMove;
}
