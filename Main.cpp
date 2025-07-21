#include <iostream>


char Board[3][3] =
{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};


void DisplayGame() 
{
    std::cout << " ___ ___ ___ \n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "| " << Board[i][j] << " ";
        }
        std::cout << "|\n";
        std::cout << " ___ ___ ___ \n";
    }
}


bool Win(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == player && Board[i][1] == player && Board[i][2] == player)
            return true;
    }

    for (int j = 0; j < 3; j++)
    {
        if (Board[0][j] == player && Board[1][j] == player && Board[2][j] == player)
            return true;
    }

    if (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player)
        return true;

    if (Board[0][2] == player && Board[1][1] == player && Board[2][0] == player)
        return true;

    return false;
}


bool BoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}


bool IsValidInput(int& input)
{
    std::cin >> input;

    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Please enter a valid number between 0 and 2.\n";
        return false;
    }

    if (input < 0 || input > 2)
    {
        std::cout << "Please choose a number between 0-2.\n";
        return false;
    }

    return true;
}


int main()
{
    int row, column;
    char Player = 'X';

    while (true)
    {
        DisplayGame();

        do
        {
            std::cout << "Player " << Player << ", enter row (0-2): ";
        } while (!IsValidInput(row));

        do
        {
            std::cout << "Enter column (0-2): ";
        } while (!IsValidInput(column));


        if (Board[row][column] == 'O' || Board[row][column] == 'X')
        {
            std::cout << "Cell already taken. Choose a different one.\n";
            continue;
        }
        else
        {
            Board[row][column] = Player;
        }


        if (Win(Player))
        {
            DisplayGame();
            std::cout << "Player " << Player << " WINS!!!\n";
            break;
        }
        else if (BoardFull())
        {
            DisplayGame();
            std::cout << "It's a Draw!\n";
            break;
        }

        Player = (Player == 'X') ? 'O' : 'X';
    }

    return 0;
}
