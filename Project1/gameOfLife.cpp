#include "gameOfLife.h"
#include<ctime>
int gameOfLife::celija_zauzeta(int i, int j)
{
	//radimo provjeru hoce li umrijeti roditi se ili ce prezivjeti za sljedecu generaciju

	int n = 0;

	if (this->_generacija[i - 1][j - 1] == '*')
		n++;
	if (this->_generacija[i][j - 1] == '*')
		n++;
	if (this->_generacija[i - 1][j] == '*')
		n++;
	if (this->_generacija[i - 1][j + 1] == '*')
		n++;
	if (this->_generacija[i + 1][j - 1] == '*')
		n++;
	if (this->_generacija[i + 1][j] == '*')
		n++;
	if (this->_generacija[i][j + 1] == '*')
		n++;
	if (this->_generacija[i + 1][j + 1] == '*')
		n++;

	return n;
}

int gameOfLife::slucajna_vrijednost(int min, int max)
{

	return rand()%(max-min+1)+min;
}

gameOfLife::gameOfLife()
{

	this->_generacija[0][0] = '-';
	this->_sljedeca_generacija[0][0] = '-';

}

void gameOfLife::set_start()
{
	srand(time(nullptr));  //mogli smo iz bez ovog pa bi svaki put generirao iste brojeve

	//pozivamo igru prvi put 

	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			this->_generacija[i][j] = '-';
		}
	}

	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			//25% sanse da se u celiji nade zivi organizam
			if (this->slucajna_vrijednost(1, 4) == 4) {
				this->_generacija[i][j] = '*';
			}
		}
	}
}

void gameOfLife::sljedeca_generacija()
{
	int n;

	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			//gledamo koliko je n i onda na osnovu koliki je broj postavljamo uvjete dane u teksu
			n = this->celija_zauzeta(i, j);
			if (n < 2)
				this->_sljedeca_generacija[i][j] = '-';
			else if (n > 3)
				this->_sljedeca_generacija[i][j] = '-';
			else if (n == 3)
				this->_sljedeca_generacija[i][j] = '*';
			else if (this->_generacija[i][j] == '*' && n == 2)
				this->_sljedeca_generacija[i][j] = '*';
			else
				_sljedeca_generacija[i][j] = '-';
		}

	}
	//postavljo sljedecu u sadasnju generaciju
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	}
}

void gameOfLife::iscrtaj()
{
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			if (this->_generacija[i][j] != '*')
				this->_generacija[i][j] = '-';

			cout << this->_generacija[i][j];

		}
		cout << endl;
	}
}





