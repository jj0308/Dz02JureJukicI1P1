#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class gameOfLife
{
private:
		static const unsigned int STUPACA = 40;
		static const unsigned int REDAKA = 20;

		char _generacija[REDAKA][STUPACA];
		char _sljedeca_generacija[REDAKA][STUPACA];

		int slucajna_vrijednost(int min, int max);
		int celija_zauzeta(int i, int j);
		
		

public:


		gameOfLife();
		void set_start();
		void sljedeca_generacija();
		void iscrtaj();
		

};





