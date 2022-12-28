/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 6 Project
* Sport Team Win/Loss Display (using Structures)
*/

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

struct WinLoss {
	int wins, losses;
};
struct Team {
	string name;
	WinLoss total;
	WinLoss home;
	WinLoss away;
};

const int SIZE = 100;
Team Sport_Teams[SIZE];
int counter = 0;


int menu();
WinLoss getWinLoss(string);
void displayWinLoss(WinLoss);
Team getTeam();
void displayTeam(Team);
void findTeam(Team[], int);

int main()
{
	int choice = 1;
	do
	{
		choice = menu();
		if (choice == 1)
		{
			Sport_Teams[counter] = getTeam();
			counter++;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < counter; i++) {
				displayTeam(Sport_Teams[i]);
			}
		}
		else if (choice == 3)
		{
			findTeam(Sport_Teams, counter);
		}
	} while (choice != 4);

	cout << endl << endl;
	system("pause");
	return 0;
}
int menu()
{
	bool notValid = true;
	while (notValid)
	{
		notValid = false;
		int choice;
		cout << "1. Enter a new team";
		cout << "\n2. Display all teams";
		cout << "\n3. Display a particular team";
		cout << "\n4. Exit the program";
		cout << endl;
		cin >> choice;
		if (choice < 1 || choice > 4)
		{
			cout << "Not a valid choice...";
			notValid = true;
		}
		else {
			return choice;
		}
	}
}
WinLoss getWinLoss(string score)
{
	WinLoss tempScore;
	cout << "Enter the " << score << " wins: ";
	cin >> tempScore.wins;
	cout << "Enter the " << score << " losses: ";
	cin >> tempScore.losses;
	return tempScore;
}
void displayWinLoss(WinLoss games)
{
	cout << games.wins << "-" << games.losses << endl;
}
Team getTeam()
{
	struct WinLoss tempHome, tempAway, tempTotal;
	struct Team tempTeam;

	cout << "Team name? ";
	cin.ignore();
	getline(cin, tempTeam.name);

	tempHome = getWinLoss("home");
	tempTeam.home = tempHome;

	tempAway = getWinLoss("away");
	tempTeam.away = tempAway;


	tempTotal.wins = tempHome.wins + tempAway.wins;
	tempTotal.losses = tempHome.losses + tempAway.losses;

	tempTeam.total = tempTotal;

	return tempTeam;
}
void displayTeam(Team Sport_Team_S)
{
	cout << Sport_Team_S.name << endl;
	cout << "Total record ";
	displayWinLoss(Sport_Team_S.total);

	cout << "Home record ";
	displayWinLoss(Sport_Team_S.home);

	cout << "Away record ";
	displayWinLoss(Sport_Team_S.away);
}
void findTeam(Team teams[], int size)
{
	string inputSearch;

	cout << "Team name? ";
	cin.ignore();
	getline(cin, inputSearch);

	if ((counter / 2) != 0)
	{
		for (int i = 0; i < counter; i++)
		{
			if (teams[i].name == inputSearch)
			{
				displayTeam(teams[i]);
			}
		}
	}
	else {
		for (int i = 0; i < counter; i++)
		{
			displayTeam(teams[i]);
		}
	}
}