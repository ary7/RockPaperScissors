#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void displayOptions(); // display game options
void playerChoice(int choice); // check what option the player chose
int computerChoice(); // return computer choice
int checkChoice(int playerChoice, int computerChoice); // check who won


int main()
{

    bool play = true;
    int choice = 0;
    char playAgain;

    srand(time(NULL));

    while (play)
    {
        displayOptions();
        cin >> choice;

        playerChoice(choice);
        checkChoice(choice, computerChoice());

        cout << "Would you like to play again? Y/N" << endl;
        cin >> playAgain;
        if (playAgain == 'N' || playAgain == 'n')
        {
            play = false;
            cout << "Thanks for playing" << endl;
        }
    }
    return 0;
}

void displayOptions()
{
        cout << "Enter your choice of rock, paper or scissors:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
}
void playerChoice(int choice)
{
    switch(choice)
    {
        case 1:
        cout << "You've selected rock." << endl;
        break;
        case 2:
        cout << "You've selected paper." << endl;
        break;
        case 3:
        cout << "You've selected scissors." << endl;
        break;

        default:
        cout << "Your selection is invalid" << endl;
    }
}
int computerChoice()
{
    int compChoice = rand()%3 + 1;

    switch(compChoice)
    {
        case 1:
        cout << "The computer has selected rock." << endl;
        break;
        case 2:
        cout << "The computer has selected paper." << endl;
        break;
        case 3:
        cout << "The computer has selected scissors." << endl;
        break;
    }

    return compChoice;
}

int checkChoice(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
    {
        cout << "The game has ended in a tie" << endl;

    }
    else if ((playerChoice == 1 && computerChoice == 2) || (playerChoice == 2 && computerChoice == 3) || (playerChoice == 3 && computerChoice == 1))
    {
        cout << "The computer wins this round" << endl;

    }
    else
    {
        cout << "You've won this round" << endl;
    }
}
