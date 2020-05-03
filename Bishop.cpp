#include "Bishop.h"


std::vector<pos> Bishop::ways(piece*** desk, pos position)
{
	std::vector<pos> Ways;
	/*int i, j;
	//up+right
	i = position.number-1;
	j = position.letter+1;
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
	*/
	return Ways;
}