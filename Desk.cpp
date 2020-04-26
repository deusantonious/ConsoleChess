#include "Desk.h"

void Desk::view()
{
	std::cout << std::setw(18) << "Black\n";
	for (int i = 0; i < 8; i++) {
		std::cout << i + 1 << " |";
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] == 0) std::cout << "  |";
			else {
				if (desk[i][j] > 0) std::cout << 'W';
				else std::cout << 'B';

				int buff = abs(desk[i][j]);
				switch (buff)
				{
				case(1): {
					std::cout << "R";
					break;
				}
				case(2): {
					std::cout << "R";
					break;
				}
				case(3): {
					std::cout << "N";
					break;
				}
				case(4): {
					std::cout << "B";
					break;
				}
				case(5): {
					std::cout << "Q";
					break;
				}
				case(6): {
					std::cout << "K";
					break;
				}
				case(7): {
					std::cout << "K";
					break;
				}
				case(8): {
					std::cout << "P";
					break;
				}
				case(9): {
					std::cout << "P";
					break;
				}
				}

				std::cout << "|";
			}
		}
		std::cout << "\n";
	}
	std::cout << "   A  B  C  D  E  F  G  H\n";
	std::cout << std::setw(18) << "White\n";
}

bool Desk::WhiteMakesTurn(pos first, pos second)
{
	if (ValidateTurnWhite(first, second)) {
		switch (GetTurnType('w',first,second))
		{
		case('0'):{
			if (desk[first.number][first.letter] == 1 ||
				desk[first.number][first.letter] == 6 ||
				desk[first.number][first.letter] == 8)	desk[first.number][first.letter]++;
			desk[second.number][second.letter] = desk[first.number][first.letter];
			desk[first.number][first.letter] = 0;
			break;
		}
		default:
			break;
		}
	}
		return true;
		
	return false;
}

char Desk::GetTurnType(char color, pos first, pos second)
{
	//pawn replacement
	if (desk[first.letter][first.number] == 9 && first.number == 1)
		return 3;
	if (desk[first.letter][first.number] == -9 && first.number == 6)
		return 3;
	//moove
	if (desk[second.number][second.letter] == 0)
		return '0';
	//castling
	if (abs(desk[first.number][first.letter]) == 1 && abs(desk[second.number][second.letter]) == 6)
		return '2';
	//eat
	return '1';
}

bool Desk::ValidateTurnWhite(pos first, pos second)
{
	switch (desk[first.number][first.letter]) {
	case(8): {
		if (first.letter == second.letter) {
			if (first.number - second.number == 1 || first.number - second.number == 2) {
				if (first.number - second.number == 1 && desk[first.number - 1][first.letter] != 0)
					return false;
				if (first.number - second.number == 2 && desk[first.number - 1][first.letter] != 0 || desk[first.number - 2][first.letter] != 0)
					return false;
				return true;
			}
			else {
				if (first.number - second.number == 1) {
					if (first.letter > 0 && second.letter < 8) {
						if (abs(first.letter - second.letter) == 1 && desk[first.number][first.letter] != 0)
							return true;
					}
				}
				else
					return false;
			}
			break;
		}
	case(9): {
		if (first.letter == second.letter) {
			if (first.number - second.number == 1 && first.number >= 0) {
				if (desk[first.number - 1][first.letter] != 0)
					return false;
				return true;
			}
			else {
				if (first.number - second.number == 1) {
					if (first.letter > 0 && second.letter < 8) {
						if (abs(first.letter - second.letter) == 1 && desk[first.number][first.letter] != 0)
							return true;
						else
							return false;
					}
				}
				else
					return false;
			}
			break;
			break;
		}

	}
		   return false;
	}
	}
}
char Desk::CheckStatus()
{

	return 0;
}

