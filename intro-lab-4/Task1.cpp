
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <random>
using namespace std;

//global deklaration
void welcomeText1();


int main()
{
	int dice = 0;
	double dice1 = 0;
	double dice2 = 0;
	double dice3 = 0;
	double dice4 = 0;
	double dice5 = 0;
	double dice6 = 0;
	int totalRoll = 0;

	//h�mta funktionen welcomeText.
	welcomeText1();

	cout << "Input how many times we shall roll the dice" << endl;
	cin >> totalRoll;

	//Slump-generatorn
	default_random_engine generator(static_cast<unsigned>(time(0)));
	uniform_int_distribution<int> random(1, 6);

	// for loop d�r den g�r igenom t�rningskasten antal g�nger man v�ljer att k�ra. Den r�knar �ven in hur mycket av varje som den sl�r i t�rningen.
	for (int i = 0; i < totalRoll; i++)
	{
		dice = random(generator);


		if (dice == 1) {
			dice1++;
		}

		else if (dice == 2) {
			dice2++;
		}

		else if (dice == 3) {
			dice3++;
		}

		else if (dice == 4) {
			dice4++;
		}

		else if (dice == 5) {
			dice5++;
		}

		else if (dice == 6) {
			dice6++;
		}
	}

	// Skriv ut antal av varje samt relativ frekvens. H�r har int skrivits med f�re ekvation f�r att f� det till heltal p� alla dice's oavsett om antal t�rningslag.
	cout << "Antal ettor  : " << dice1 << "  Relativ frekvens: " << setprecision(2) << (int)(dice1 / totalRoll * 100) << "  %" << endl;
	cout << "Antal tvaor  : " << dice2 << "  Relativ frekvens: " << setprecision(2) << (int)(dice2 / totalRoll * 100) << "  %" << endl;
	cout << "Antal treor  : " << dice3 << "  Relativ frekvens: " << setprecision(2) << (int)(dice3 / totalRoll * 100) << "  %" << endl;
	cout << "Antal fyror  : " << dice4 << "  Relativ frekvens: " << setprecision(2) << (int)(dice4 / totalRoll * 100) << "  %" << endl;
	cout << "Antal femmor : " << dice5 << "  Relativ frekvens: " << setprecision(2) << (int)(dice5 / totalRoll * 100) << "  %" << endl;
	cout << "Antal sexor  : " << dice6 << "  Relativ frekvens: " << setprecision(2) << (int)(dice6 / totalRoll * 100) << "  %" << endl;




	system("pause");
	return 0;
}

// funktion f�r att skriva ut v�lkomsttext
void welcomeText1()
{
	cout << "*******************************************" << endl;
	cout << "*******************WELCOME*****************" << endl;
	cout << "**************TO ROLL THE DICE*************" << endl;
	cout << endl;
}





