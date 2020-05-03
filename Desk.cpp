#include "Desk.h"
void Desk::CheckWhite()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] != nullptr && typeid(*desk[i][j]) == typeid(King) && desk[i][j]->GetColor() == 'W') {
				CheckForWhite = dynamic_cast<King*>(desk[i][j])->checkTest(desk, pos(j + 1, i + 1));
				break;
			}		
		}
	}
}
void Desk::CheckBlack()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] != nullptr && typeid(*desk[i][j]) == typeid(King) && desk[i][j]->GetColor() == 'B') {
				CheckForBlack = dynamic_cast<King*>(desk[i][j])->checkTest(desk, pos(j + 1, i + 1));
				break;
			}
		}
	}
}
Desk::Desk()
{
	CheckForBlack = false;
	CheckForWhite = false;
	try
	{
		desk = new piece**[8];
		for (int i = 0; i < 8; i++)
			desk[i] = new piece * [8];

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				desk[i][j] = nullptr;

		desk[7][4] = new King('W');
		//creating black King
		desk[0][4] = new King('B');
		//creating white Queen
		desk[7][3] = new Queen('W');
		//creating black Queen
		desk[0][3] = new Queen('B');
	}
	catch (const std::exception&ex)
	{
		throw ex;
	}
	
	
	
	
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

Desk::Desk(Desk& a)
{
	try
	{
		desk = new piece * *[8];
		for (int i = 0; i < 8; i++)
			desk[i] = new piece * [8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (a.desk[i][j] == nullptr) { desk[i][j] = nullptr; continue; }
				if (a.desk[i][j]->name == 'P') { desk[i][j] = new pawn(a.desk[i][j]->GetColor()); continue; }
				if (a.desk[i][j]->name == 'R') { desk[i][j] = new rock(a.desk[i][j]->GetColor()); continue; }
				if (a.desk[i][j]->name == 'K') { desk[i][j] = new King(a.desk[i][j]->GetColor()); continue; }
				if (a.desk[i][j]->name == 'Q') { desk[i][j] = new Queen(a.desk[i][j]->GetColor()); continue; }
				if (a.desk[i][j]->name == 'B') { desk[i][j] = new Bishop(a.desk[i][j]->GetColor()); continue; }
				if (a.desk[i][j]->name == 'N') { desk[i][j] = new Knight(a.desk[i][j]->GetColor()); continue; }
			}
		}
	}
	catch (const std::exception & ex)
	{
		throw ex;
	}
}


Desk::~Desk()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (desk[i][j] != nullptr) delete desk[i][j];
		delete desk[i];
	}
	delete desk;
}


bool Desk::PreValidation(char player, pos first)
{
	if (desk[first.number][first.letter] == nullptr) throw std::exception("Selected position is empty");
	if (player != desk[first.number][first.letter]->GetColor()) throw std::exception("Selected position must contain your piece!\n");
	return true;
}

char Desk::makeTurn(char player, pos first, pos second)
{
	//make copy
	Desk buff(*this);
	//make move in copy
	buff.makeTestTurn(player, first, second);
	if (player == 'W') {
		buff.CheckWhite();
		if (buff.CheckForWhite == true) throw std::exception("U cant do this move! Check!\n");
		CheckForWhite = false;
	}
	else {
		buff.CheckBlack();
		if (buff.CheckForBlack == true) throw std::exception("U cant do this move! Check!\n");
		CheckForBlack = false;
	}
	makeTestTurn(player, first, second);
	if (player == 'W') {
		CheckBlack();
	}
	else {
		CheckWhite();
	}
	return'0';
}

void Desk::makeTestTurn(char player, pos first, pos second)
{
	desk[first.number][first.letter]->move(desk, first, second);
}



void Desk::view()
{
	std::cout << std::setw(18) << "Black\n";
	for (int i = 0; i < 8; i++) {
		std::cout << i + 1 << " |";
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] != nullptr)
				desk[i][j]->Display();
			else
				std::cout << "  ";
			std::cout << "|";
		}
		std::cout << "\n";
	}
	std::cout << "   A  B  C  D  E  F  G  H\n";
	std::cout << std::setw(18) << "White\n";
	if (CheckForWhite == true) std::cout << "Check for white!\n";
	if (CheckForBlack == true) std::cout << "Check for black!\n";
}