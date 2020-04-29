#include <iostream>
#include <conio.h>
#include "Desk.h"
#include "pos.h"
bool Turn(const char* color, Desk* desk) {
	char posL, posN;
	pos f, s;
	bool In = true;
	while (In) {
		try {
			system("CLS");
			desk->view();
			///// input piece to move
			std::cout << color << ": Which piece would you like to move?\n";
			std::cout << "Enter column from A to H: ";
			std::cin >> posL;
			std::cout << "Enter row from 1 to 8: ";
			std::cin >> posN;
			posL = (char)std::toupper(posL);
			f = pos(posL, posN);
			////// preValidation
			desk->PreValidation(color[0], f);
			system("CLS");
			desk->view();
			//////// input destination
			std::cout << color << ": Enter destination\n";
			std::cout << "enter column from A to H: ";
			std::cin >> posL;
			std::cout << "enter row from 1 to 8: ";
			std::cin >> posN;
			posL = (char)std::toupper(posL);
			s = pos(posL, posN);
			/// turn
			if (desk->makeTurn(color[0], f, pos(posL, posN)) == '1')
				return true;
			In = false;
			return false;
		}
		catch (const std::exception & ex){
			std::cout << ex.what() << "\n";
			std::cout << "\nPress any button to try again";
			_getch();
		}
	}
}
int main() {

	Desk ChessBoard;
	char posL, posN;
	while (1) {
		
		if (Turn("White", &ChessBoard)) { std::cout << "Check mate white wins!\n"; break; }
		if (Turn("Black", &ChessBoard)) { std::cout << "Check mate black wins!\n"; break; }
	}
	system("pause");
}
