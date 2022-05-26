#include <iostream>
#include <string>
#include <fstream>
#include "gameOfLife.h"
using namespace std;

int main() {
	
	gameOfLife the_game;
;
	bool dalje;
	the_game.set_start();
	do {
		
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		
	

		cout << "dalje (1/0): ";
	cin >> dalje;
	system("CLS");
	} while (dalje);

	return 0;
}