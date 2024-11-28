#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
void displayBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
}
bool check(const vector<vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}
bool isFull(vector<vector<char>> &board)
{
    for (auto &it : board)
    {
        for (auto &it1 : it)
        {
            if (it1 != 'X' && it1 != 'O')
            {
                return false;
            }
        }
    }
    return true;
}
void comp_Plays(vector<vector<char>> &board)
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');
    board[row][col] = 'O';
}
int main()
{
    srand(time(0));
    vector<vector<char>> board = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    cout << "Let's play Tic Tac Toe! You are 'X', and the computer is 'O'." << endl;
    cout << "You get to play first" << endl
         << "Enter a location to play X" << endl;

    while (!isFull(board))
    {
        char choice;
        int userPlayed = 0;
        displayBoard(board);
        cout << "Enter the letter where you want to place the X" << endl;
        cin >> choice;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == choice)
                {
                    board[i][j] = 'X';
                    userPlayed = 1;
                    break;
                }
            }
            if (userPlayed)
            {
                break;
            }
        }

        if (!userPlayed)
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (check(board, 'X'))
        {
            displayBoard(board);
            cout << "Congratulations! You win!\n";
            break;
        }

        if (isFull(board))
        {
            displayBoard(board);
            cout << "It's a tie!\n";
            break;
        }

        comp_Plays(board);
        if (check(board, 'O'))
        {
            displayBoard(board);
            cout << "Game over! Computer wins!\n";
            break;
        }

        if (isFull(board))
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}
