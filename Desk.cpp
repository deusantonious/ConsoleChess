#include "Desk.h"
void Desk::FillCheckStatus()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] != nullptr && typeid(*desk[i][j]) == typeid(King))
				if (desk[i][j]->GetColor() == 'W') CheckForWhite = dynamic_cast<King*>(desk[i][j])->checkTest(desk);
				else	CheckForBlack = dynamic_cast<King*>(desk[i][j])->checkTest(desk);
		}
	}
}
Desk::Desk()
{
	CheckForBlack = false;
	CheckForWhite = false;
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
	desk[7][4] = new King('W', pos('E', 8));
	//creating black King
	desk[0][4] = new King('B', pos('E', 1));
	//creating white Queen
	desk[7][3] = new Queen('W', pos('D', 8));
	//creating black Queen
	desk[0][3] = new Queen('B', pos('D', 1));
	/*
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
	//creating white King
	desk[7][4] = new King('W', pos('E', 8));
	//creating black King
	desk[0][4] = new King('B', pos('E', 1));
	//creating black bishops
	desk[0][2] = new Bishop('B', pos(3, 1));
	desk[0][5] = new Bishop('B', pos(6, 1));
	//creating white bishops
	desk[7][2] = new Bishop('W', pos(3, 8));
	desk[7][5] = new Bishop('W', pos(6, 8));
	//creating white Queen
	desk[7][3] = new Queen('W', pos('D', 8));
	//creating black Queen
	desk[0][3] = new Queen('B', pos('D', 1));
	*/
}

Desk::Desk(const Desk& New)
{
	CheckForBlack = New.CheckForBlack;
	CheckForWhite = New.CheckForWhite;
	try {
		desk = new piece * *[8];
	}
	catch (std::exception & ex) {
		throw ex;
	}

	for (int i = 0; i < 8; i++) {
		desk[i] = new piece * [8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			desk[i][j] = New.desk[i][j];
		}
	}
}

Desk Desk::operator=(const Desk& second)
{
	CheckForBlack = second.CheckForBlack;
	CheckForWhite = second.CheckForWhite;
	try {
		desk = new piece * *[8];
	}
	catch (std::exception & ex) {
		throw ex;
	}

	for (int i = 0; i < 8; i++) {
		desk[i] = new piece * [8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			desk[i][j] = second.desk[i][j];
		}
	}
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
	return true;
}

char Desk::makeTurn(char player, pos first, pos second)
{
	//allocating memmory for tmp desk
	piece*** buff;
	try {
		buff = new piece * *[8];
		for (int i = 0; i < 8; i++) {
			buff[i] = new piece * [8];
		}
	}
	catch (std::exception & ex) {
		throw ex;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			buff[i][j] = desk[i][j];
		}
	}
	///////trying to do move
	//if throw
	buff[first.number][first.letter]->move(buff, second);
	//testing check after moove
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (buff[i][j] != nullptr && typeid(*buff[i][j]) == typeid(King))
				if (buff[i][j]->GetColor() == 'W') {
					if (dynamic_cast<King*>(buff[i][j])->checkTest(buff) == false)
						CheckForWhite = false;
					else
						CheckForWhite = true;
				}
				else
					if (dynamic_cast<King*>(buff[i][j])->checkTest(buff) == false)
						CheckForBlack = false;
					else
						CheckForBlack = true;
		}
	}


	//throwing ecxeption if we have check
	if (CheckForBlack == false && CheckForWhite == false) {
		for (int i = 0; i < 8; i++) {
			delete[] desk[i];
		}
		delete desk;
		desk = buff;
		//////saving positions
		return '0';
	}
	else {
		for (int i = 0; i < 8; i++) {
			delete[] buff[i];
		}
		delete buff;
		FillCheckStatus();
		throw std::exception("Your turn is invalid! Check!\n");
	}

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
	FillCheckStatus();
	std::cout << std::setw(18) << "White\n";
	if (CheckForWhite == true) std::cout << "Check for white!\n";
	if (CheckForBlack == true) std::cout << "Check for black!\n";
}