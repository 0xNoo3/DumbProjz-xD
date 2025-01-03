#include<iostream>
#include<cstdint>
#include<ctime>
using namespace std;

char getUser_choice();
char getComputer_choice();
void show_choice(char choice);
void chooseWinner(char player, char computer);

int32_t main(void)  {

    char player, computer;
    char con;
    do
    {
        cout << "\t\t\tROCK, PAPER AND SCISSORS GAME !" << endl;
        player = getUser_choice();
        show_choice(player);
        computer = getComputer_choice();
        chooseWinner(player, computer);
        cout << "Enter any key to continue or Press 'q' to quit" << endl;
        cin >> con;
    } while (con != 'q');
    cout << "\t\t\tThanks For Playing !" << endl;
    return 0;
}

char getUser_choice()
{
    char player;
    do
    {
        cout << "Enter 'r' for Rock" << endl;
        cout << "Enter 'p' for Paper" << endl;
        cout << "Enter 's' for Scissors" << endl;
        cin >> player;

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

void show_choice(char choice)
{
    switch (choice)
    {
    case 'r':
        cout << "Your choice is Rock" << endl;
        break;
    case 'p':
        cout << "Your choice is Paper" << endl;
        break;
    case 's':
        cout << "Your choice is Scissors" << endl;
        break;
    }
}

char getComputer_choice()
{
    char computer;
    srand(time(0));
    int random = (rand() % 3) + 1;
    switch (random)
    {
    case 1:
        cout << "Computer choice is Rock" << endl;
        computer = 'r';
        break;
    case 2:
        cout << "Computer choice is Paper" << endl;
        computer = 'p';
        break;
    case 3:
        cout << "Computer choice is Scissor" << endl;
        computer = 's';
        break;
    }
    return computer;
}

void chooseWinner(char player, char computer)
{
    if(player == computer)
    {
        cout << "Tie Game" << endl;
        return;
    }
    else if(player == 'r' && computer == 'p')
    {
        cout << "You lose" << endl;
        return;
    }
    else if(player == 'p' && computer == 'r')
    {
        cout << "You win" << endl;
        return;
    }
    else if(player == 'r' && computer == 's')
    {
        cout << "You win" << endl;
        return;
    }
    else if(player == 's' && computer == 'r')
    {
        cout << "You lose" << endl;
        return;
    }
}


