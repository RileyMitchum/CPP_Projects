#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

char grid[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char AI;

void board()
{
	system("cls");
	cout << "\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << grid[1] << "  |  " << grid[2] << "  |  " << grid[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << grid[7] << "  |  " << grid[8] << "  |  " << grid[9] << endl;

	cout << "     |     |     " << endl << endl;
}

int checkWin()
{
	if (grid[1] == grid[2] && grid[2] == grid[3])
		return 1;
	else if (grid[4] == grid[5] && grid[5] == grid[6])
		return 4;
	else if (grid[7] == grid[8] && grid[8] == grid[9])
		return 7;
	else if (grid[1] == grid[4] && grid[4] == grid[7])
		return 1;
	else if (grid[2] == grid[5] && grid[5] == grid[8])
		return 2;
	else if (grid[3] == grid[6] && grid[6] == grid[9])
		return 3;
	else if (grid[1] == grid[5] && grid[5] == grid[9])
		return 1;
	else if (grid[3] == grid[5] && grid[5] == grid[7])
		return 3;
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' 
                && grid[4] != '4' && grid[5] != '5' && grid[6] != '6' 
              && grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
		return -1;
	else
		return 0;
}

void player1Turn()
{
	int Xchoice;
	cout << "Player 1 (X), where do you want to play? \n";
	cin >> Xchoice;
	if (grid[Xchoice] == 'X' || grid[Xchoice] == 'O' || Xchoice > 9 || Xchoice < 1)
		player1Turn();
	else
		grid[Xchoice] = 'X';
}

void player2Turn()
{
	int Ochoice;
	if(AI == 'Y' || AI == 'y')
		Ochoice = (rand() % 9)+1;
	else
	{
		cout << "Player 2 (O), where do you want to play? \n";
		cin >> Ochoice;
	}
	if (grid[Ochoice] == 'X' || grid[Ochoice] == 'O')
		player2Turn();
	else
		grid[Ochoice] = 'O';
}

void main()
{
	srand(time(NULL));

	cout << "Want to play against AI? Y/N";
	cin >> AI;

	board();

	while(checkWin() == 0)
	{
		player1Turn();
		board();
		if(checkWin() == 0)
		{
			player2Turn();
			board();
		}
	}
	int winner = checkWin();

	if(winner == -1)
		cout << "No winner! \n";
	else
	{
		if (grid[checkWin()] == 'X')
			cout << "Player 1 Wins! \n";
		else
			cout << "Player 2 Wins! \n";
	}
}
