/* Author: Stewart Moon
Class: CSC 223-100
Professor: Jeffrey Howard
Due Date: 10/10/2017
Page & Problem #: Page 243, #19
Description:  This program manages a list of up to 10 players, and their high scores.
There will be 4 functions that allow the user to interact with the program by managing (adding, deleting)
players and their highscores in the program.  This program will not utilize a struct or class.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void menuAction();
//Pre-condition: No parameters passed to the function
//post-condition: No parameters returned from the function

int UserSelection();
//Pre-condition: No parameters passed to the function
//post-condition: int Parameter returned from the function

void menuAction(int userchoice);
//Pre-condition: Parameter user choice is passed to the function.  Type int must be initiliazed before.
//post-condition: No parameters returned from the function

class Arrays
{
public:

public:
	string players;
	int scores;
};

int main()
{
	//start work-flow
	int userchoice = UserSelection();
	menuAction(userchoice);
}

//Description: This function is the has the program workflow included. It contains all the choices the user can make.

void menuAction(int userchoice)
{
	//Declare variables
	int count = 0;
	int counter = 0;

	string deletedplayer;

	Arrays somename;
	Arrays info[10] = { somename };

	//Begin calling workflows

	do {

		//Logic for if user wants to add a player
		if (userchoice == 1)
		{
			//Prompt user for input
			for (int i = counter; i <= count; i++)
			{
				cout << "Please enter a player: " << endl;
				cin >> info[i].players;
				cout << "Please enter a score: " << endl;
				cin >> info[i].scores;

				cout << endl;
			}

			//Print out the new array
			for (int i = 0; i <= count; i++)
			{
				cout << info[i].players << endl;
				cout << info[i].scores << endl;
			}

			//Increase place in Arrays
			count++;
			counter++;
			userchoice = UserSelection();
		}

		else if (userchoice == 2)
		{
			//Print out the array
			for (int i = 0; i <= count; i++)
			{
				cout << info[i].players << endl;
				cout << info[i].scores << endl;
			}
			userchoice = UserSelection();
		}

		else if (userchoice == 3)
		{
			//Declare variables
			string userinput;

			//Prompt user for input
			cout << "Please enter a player to look up their score: " << endl;
			cin >> userinput;

			//Logic for searching for player
			for (int i = 0; i < 10; i++)
				if (userinput == info[i].players)
				{
					cout << userinput << "'s score is: " << info[i].scores << endl;;
				}
			cout << endl;//Empty Line
			userchoice = UserSelection();
		}
		
		else if (userchoice == 4)
		{
			//Prompt user for input
			cout << "Please enter a player to delete them and their score: ";
			cin >> deletedplayer;

			//Logic for searching for player and deleting them
			for (int i = 0; i <= count; i++)
			{
				if (deletedplayer == info[i].players)
				{
					info[i].players = "";
					info[i].scores = 0;
				}
			}
			//Increment down placeholder of Array
			count--;
			counter--;
			userchoice = UserSelection();
		}
	} while (userchoice != 5);

	cout << "Goodbye!" << endl;
}


//Description: This function prompts a user for input and returns it in the variable userpick.
//It prompts the user for a int value, to decide if to continue the program. 
int UserSelection()
{
	//Define variables
	int userpick;

	//Prompt the user for input
	cout << "1. Add a new player and score. " << endl;
	cout << "2. Print all players & scores to the screen. " << endl;
	cout << "3. Search for a player and score." << endl;
	cout << "4. Remove a player and score from the list" << endl;
	cout << "5. To leave the Exit the Program" << endl;
	cout << "Please select options between 1-5: ";
	cin >> userpick;
	cout << endl;//Empty Line

	return userpick;
}