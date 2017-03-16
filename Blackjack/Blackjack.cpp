#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <ctime>
using namespace std;

vector<string> deck;
vector<string> playersHand;
vector<string> dealersHand;
int playerSum = 0;
int playerAces = 0;
int dealerSum = 0;
int dealerAces = 0;

string drawOne()
{
	// Deal 1 random card, and remove it from the deck
	srand(time(NULL));
	int card = rand() % deck.size();
	string drawnCard = deck[card];
	deck.erase(deck.begin() + card);
	return drawnCard;
}

void generateNewDeck()
{
	deck.clear();
	playersHand.clear();
	dealersHand.clear();
	// Generate a deck of 52 cards
	string suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"} ;
	string value[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
	int count = 0;
	for (int i=0; i<4; i++)
	{
		for(int j=0; j<13; j++)
		{
			string card = value[j] + " of " + suit[i];
			deck.push_back(card);
			count++;
		}
	}
}

void returnPlayersCard(int index)
{
	deck.push_back(playersHand[index]);
	playersHand.erase(playersHand.begin() + index);
}

void sumHands()
{
	// Sum player hand
	if (playerAces > 0 && playerSum > 21)
	{
		playerSum -= 10;
		return;
	}

	playerSum = 0;
	playerAces = 0;
	for (int i=0; i<playersHand.size(); i++)
	{
		string cardValue = playersHand[i].substr(0,2);
		const char* card = cardValue.c_str();
		playerSum += atoi(card);
		if (atoi(card) == 1 && playerAces == 0)
		{
			playerAces = 1;
		}
	}
	// Handle aces
	if (playerSum < 21 && playerAces == 1)
	{
		playerSum += 10;
	}

	if (playerSum > 21 && playerAces == 1)
	{
		playerSum -= 10;
	}

	// Sum dealer hand
	dealerSum = 0;
	for (int i=0; i<dealersHand.size(); i++)
	{
		string cardValue = dealersHand[i].substr(0,2);
		const char* card = cardValue.c_str();
		dealerSum += atoi(card);
		if (atoi(card) == 1 && dealerAces == 0)
		{
			dealerAces = 1;
		}
	}
	// Handle aces
	if (dealerSum < 21 && dealerAces == 1)
	{
		dealerSum += 10;
	}

	if (dealerSum > 21 && dealerAces == 1)
	{
		dealerSum -= 10;
	}
}


void displayPlayersHand()
{
	system("cls");
	cout << "---Your Hand (" << playerSum << ") \n";
	for (int i=0; i<playersHand.size(); i++)
	{
		cout << playersHand[i] << "\n";
	}
}

void displayDealersHand()
{
	cout << "\n ---Dealers Hand (" << dealerSum << ") \n";
	for (int i=0; i<dealersHand.size(); i++)
	{
		cout << dealersHand[i] << "\n";
	}
}

void initialDeal()
{
	for(int i=0; i<2; i++)
	{
		playersHand.push_back(drawOne());
		dealersHand.push_back(drawOne());
	}

	sumHands();

	cout << "---Your Hand (" << playerSum << ") \n";
	for (int i=0; i<playersHand.size(); i++)
	{
		cout << playersHand[i] << "\n";
	}
}

void dealersTurn()
{
	if (dealerSum > 21)
	{
		return;
	}

	if (dealerSum < 17)
	{
		dealersHand.push_back(drawOne());
		sumHands();
		dealersTurn();
	}

	else
		return;
}

void checkBust()
{
	if (playerSum > 21 )
	{
		cout << "BUST!" << "\n";
		dealersTurn();
		return;
	}

	cout << "Stay(1) or Hit(2)?";
	int option;
	cin >> option;

	if (option == 2)
	{
		playersHand.push_back(drawOne());
		sumHands();
		displayPlayersHand();
		checkBust();
	}

	if (option == 1)
	{
		dealersTurn();
		return;
	}
}

void checkWinner()
{
	if (playerSum > dealerSum && playerSum <= 21)
	{
		cout << "\n\n\n";
		cout << "----- Player Wins! -----" << "\n";
	}
	else if (playerSum < dealerSum && dealerSum <= 21)
	{
		cout << "\n\n\n";
		cout << "----- Dealer Wins! -----" << "\n";
	}
	else if (playerSum > 21 && dealerSum <= 21)
	{
		cout << "\n\n\n";
		cout << "----- Dealer Wins! -----" << "\n";
	}
	else if (dealerSum > 21 && playerSum <= 21)
	{
		cout << "\n\n\n";
		cout << "----- Player Wins! -----" << "\n";
	}
	else
	{
		cout << "\n\n\n";
		cout << "----- No Winner! -----" << "\n";
	}
}

int main()
{
	generateNewDeck();
	
	initialDeal();

	sumHands();

	checkBust();

	displayDealersHand();

	checkWinner();

	cout << "\n Play Again???  Yes(Y) or No(N)";

	char option;
	cin >> option;
	
	if (option == 'Y' || option == 'y')
	{
		system("cls");
		main();
	}

	else
	{
		return 0;
	}

	return 0;
}
