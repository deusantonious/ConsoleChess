#include <iostream>
#include "Desk.h"
#include "pos.h"
int main() {
	Desk a;
	a.view();
	std::cout << a.WhiteMakesTurn(pos('B', 7), pos('B', 5));
	std::cout << a.WhiteMakesTurn(pos('B', 5), pos('B', 4));
	system("CLS");
	a.view();
}