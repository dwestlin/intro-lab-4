#include <iostream>
#include <sstream> 
#include <string>  
using namespace std;

//Funktioner
//--------------------------
void welcomeText();
bool checkTime(string clock);
int countMin(string clock);
void greaterThan();
double countPrize(string startCall, string stopCall);
char menu();
//---------------------------

//De globala konstanterna
//---------------------------
const string STARTING_TIME = "08:00";
const string STOPPING_TIME = "18:30";
const double TARIFF = 4.00; // Ordinarie taxa. 
const double TIME_DISCOUNT = 0.35; // Räkna ut 65% rabatt på kvällarna efter kl 18 och före kl 08:00
const double LENGTH_DISCOUNT = 0.85; // 15% rabatt.
const double MOMS = 1.25; // Momsen
						  //---------------------------
int main()
{


	string startCall;
	string stopCall;
	bool validFormat;
	char menuChoice;
	double totalPrize = 0;


	// initierar en void där en enkel välkomsttext finns.
	welcomeText();

	do
	{
		do
		{
			do
			{

				cout << "Starting time? (hh:mm eller h:mm) ";
				cin >> startCall;
				validFormat = checkTime(startCall);
			} while (validFormat != true);

			do
			{
				cout << "...And the stop time?(hh:mm eller h:mm) ";
				cin >> stopCall;
				validFormat = checkTime(stopCall);
			} while (validFormat != true);

			if (countMin(startCall) > countMin(stopCall)) {
				greaterThan();
			}

		} while (countMin(startCall) > countMin(stopCall));


		totalPrize = countPrize(startCall, stopCall);

		//Skriver ut totalpriset som hämtas ur funktionen totalPrize().
		cout << endl;
		cout << "Priset for att prata i telefonen mellan " << startCall << " och " << stopCall << " ar: " << totalPrize << endl;
		cout << endl;

		do
		{
			menuChoice = menu();
		} while (!(menuChoice == 'Y' || menuChoice == 'y' || menuChoice == 'n' || menuChoice == 'N'));

	} while (menuChoice == 'Y' || menuChoice == 'y');

	return 0;

}



void welcomeText()
{
	cout << "*******************************************" << endl;
	cout << "*******************WELCOME*****************" << endl;
	cout << "***********TO COUNTING CALLTAXES***********" << endl;
	cout << endl;
}


bool checkTime(string clock) {


	//Lokala Variablar samt leta efter semikolon för att dels se till så att det är rätt format
	//...Men även kunna leta upp och senare ersätta med ' ' för att sära på timmar och minutrar.
	// därefter en istream för att dela upp i timmar och minutrar.

	int hour = 0, minute = 0;
	int fourFormat = clock.length() == 4 && clock.find(":") == 1;
	int fiveFormat = clock.length() == 5 && clock.find(":") == 2;

	if (fourFormat || fiveFormat) {

		clock.replace(clock.find(":"), 1, " ");
		istringstream iss(clock);
		iss >> hour >> minute;

		if (minute < 0 || minute > 59) {
			cout << "Wrong input." << endl;

			return false;
		}

		if (hour < 0 || hour > 23) {
			cout << "Wrong input." << endl;

			return false;
		}

		return true;

	}
	else
		cout << "WRONG INPUT, TRY AGAIN" << endl;


	return false;
}


//Void-funktion som skriver ut att tiden är större än stoptiden och att vi börjar om.
void greaterThan() {
	cout << endl;
	cout << "The starting time is greater than the stopping time, we'll start over" << endl;
	cout << endl;
}



// Här behöver man använda sig av find-kommandot för att särskilja mellan timmar och minutrar för att sen returnera (60 minuter x timmar) och minutrar i retur. 
// Denna funktion fungerar även för att jämföra så att stoptid är större än starttid i if-loopen för att skriva ut funktionen greaterThan(). Samt som del while-loopen för att starta om, om start och stop-tid
// är nåt som är fel.
int countMin(string clock) {
	int hour = 0, minute = 0, countingMinutes = 0;

	clock.replace(clock.find(":"), 1, " ");

	istringstream iss(clock);
	iss >> hour >> minute;
	countingMinutes = (60 * hour) + minute;

	return countingMinutes;
}


//Börja med att deklarera antal minuter på starttid och stopptid i en egen integer samt beräkna totalaminutrarna.

double countPrize(string startCall, string stopCall)
{
	int discTime1 = countMin(STARTING_TIME);
	int discTime2 = countMin(STOPPING_TIME);
	int callStoped = countMin(stopCall);
	int callStarted = countMin(startCall);
	int countPrizeDisc1 = 0;
	int countPrizeDisc2 = 0;
	int countPrizeFull = 0;


	if (callStoped >= discTime2 && callStarted >= discTime2) {
		countPrizeDisc2 = callStoped - callStarted;
	}

	if (callStoped > discTime2 && callStarted < discTime2 && callStarted > discTime1 && callStoped > discTime1) {
		countPrizeDisc2 = callStoped - discTime2;
		countPrizeFull = discTime2 - callStarted;
	}

	if (callStoped > discTime2 && callStarted < discTime2 && callStarted < discTime1) {
		countPrizeDisc2 = callStoped - discTime2;
		countPrizeFull = discTime2 - discTime1;
		countPrizeDisc1 = discTime1 - callStarted;
	}

	if (callStoped <= discTime2 && callStarted <= discTime2 && callStarted >= discTime1) {
		countPrizeFull = callStoped - callStarted;
	}

	if (callStoped < discTime2 && callStarted < discTime2 && callStarted < discTime1 && callStoped >= discTime1) {
		countPrizeFull = callStoped - discTime1;
		countPrizeDisc1 = discTime1 - callStarted;
	}

	if (callStoped <= discTime1 && callStarted < discTime1) {
		countPrizeDisc1 = callStoped - callStarted;
	}


	int countPrizeDisc = countPrizeDisc1 + countPrizeDisc2;
	double totalPrize = (countPrizeFull * TARIFF) + (countPrizeDisc * TARIFF * TIME_DISCOUNT);

	totalPrize = totalPrize * MOMS;

	if (countPrizeFull + countPrizeDisc > 30) {
		totalPrize = totalPrize * LENGTH_DISCOUNT;
	}

	return totalPrize;
}



char menu() {
	char menuChoice;

	cout << "Would you like to run the program again (Y/N) ?";
	cin >> menuChoice;

	return menuChoice;
}