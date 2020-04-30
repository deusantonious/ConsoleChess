#include "Desk.h"
Desk::Desk()
{
	try {
		desk = new piece ** [8];
	}
	catch (std::exception & ex) {
		throw ex;
	}

	for (int i = 0; i < 8; i++) {
		desk[i] = new piece*[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			desk[i][j] = nullptr;
		}
	}
	//creating black pawns
	for (int i = 0; i < 8; i++) {
		desk[1][i] = new pawn('B',pos(i+1,2));
	}
	//creating white pawns
	for (int i = 0; i < 8; i++) {
		desk[6][i] = new pawn('W', pos(i + 1,7));
	}
	//creating black rocks
	desk[0][0] = new rock('B', pos(1, 1));
	desk[0][7] = new rock('B', pos(8, 1));
	//creating white rocks
	desk[7][0] = new rock('W', pos(1, 8));
	desk[7][7] = new rock('W', pos(8, 8));
	//creating black knigts
	desk[0][1] = new Knight('B', pos(2, 1));
	desk[0][6] = new Knight('B', pos(7, 1));
	//creating white knigts
	desk[7][1] = new Knight('W', pos(2, 8));
	desk[7][6] = new Knight('W', pos(7, 8));
}

Desk::~Desk()
{
	for (int i = 0; i < 8; i++) {
		delete[] desk[i];
	}
	delete desk;
}

bool Desk::PreValidation(char player, pos first)
{
	if (desk[first.number][first.letter] == nullptr) throw std::exception("Selected position is empty!\n");
	if (player != desk[first.number][first.letter]->GetColor()) throw std::exception("Selected position must contein your piece!\n");
	// if check
	return true;
}

char Desk::makeTurn(char player, pos first, pos second)
{
	desk[first.number][first.letter]->move(desk, second);
	return '0';
	//check mate
	//return '1';
}

void Desk::view()
{
	std::cout << std::setw(18) << "Black\n";
	for (int i = 0; i < 8; i++) {
		std::cout << i + 1 << " |";
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] == nullptr)
				std::cout << "  |";
			else {
				desk[i][j]->Display();
				std::cout << "|";
			}
			
		}
		std::cout << "\n";
	}
	std::cout << "   A  B  C  D  E  F  G  H\n";
	std::cout << std::setw(18) << "White\n";
}