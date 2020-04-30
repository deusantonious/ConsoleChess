#include "Queen.h"

Queen& Queen::operator=(const Queen a)
{
	;
	return *this;
	// TODO: insert return statement here
}

std::vector<pos> Queen::ways(piece*** desk)
{
	std::vector <pos> Ways;
	int i, j;
	//up+right
	i = position.number - 1;
	j = position.letter + 1;
	while (i >= 0 && j <= 7) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
		i--; j++;
	}
	//up+left
	i = position.number - 1;
	j = position.letter - 1;
	while (i >= 0 && j >= 0) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
		i--; j--;
	}
	//down + right
	i = position.number + 1;
	j = position.letter + 1;
	while (i <= 7 && j <= 7) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
		i++; j++;
	}
	//down + left
	i = position.number + 1;
	j = position.letter - 1;
	while (i <= 7 && j >= 0) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
		i++; j--;
	}
	//up
	j = position.letter;
	for (i = position.number - 1; i >= 0; i--) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
	}
	//down
	j = position.letter;
	for (i = position.number + 1; i <= 7; i++) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
	}
	//left
	i = position.number;
	for (j = position.letter - 1; j >= 0; j--) {
		if (desk[i][j] != nullptr) {
			if (desk[i][j]->GetColor() != color)
				Ways.push_back(pos(j + 1, i + 1));
			break;
		}
		Ways.push_back(pos(j + 1, i + 1));
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

void Queen::Display()
{
	if (color == 'W') std::cout << "WQ";
	else std::cout << "BQ";
}
