#include <iostream>
using namespace std;

void display_board(char arr[3][3]);
bool check_win(char arr[3][3]);
bool check_draw(char arr[3][3]);
void restart_board(char arr[3][3], int& turn);
bool enter_choice(char arr[3][3], int choice, char mark);
bool is_valid_choice(char input[]);

int main()
{
    char player1[20];
    char player2[20];
    char input[10];
    int choice;
    int turn = 0;
    bool win, draw;
    bool gameover = false;
    bool condition = true;
    char end[300];
    char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
    cout << "-----------------------------------" << endl;
    cout << "Welcome to AliImtiaz's Tic Tac Toe " << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << "Player 1 enter your name = ";
    cin.getline(player1, 20);
    cout << "Player 2 enter your name = ";
    cin.getline(player2, 20);

    cout << endl;
    display_board(board);
    cout << endl;

    do
    {
        while (!gameover)
        {
            if (turn % 2 == 0)
            {
                cout << player1 << "'s turn (x). Enter the cell number to mark = ";
                cin >> input;
                cout << endl;

                if (!is_valid_choice(input))
                {
                    cout << "Invalid number, try again." << endl << endl;
                    continue;
                }

                choice = input[0] - '0'; 
                char mark1 = 'x';
                if (enter_choice(board, choice, mark1))
                {
                    display_board(board);
                    cout << endl;

                    turn++;
                    win = check_win(board);
                    if (win)
                    {
                        cout << "Congratulations, " << player1 << " wins!" << endl;
                        gameover = true;
                    }
                    draw = check_draw(board);
                    if (draw && !win)
                    {
                        cout << "It's a draw, No winner in this game." << endl;
                        gameover = true;
                    }
                }
                else
                {
                    cout << "This place is already taken, try again." << endl << endl;
                }
            }
            else
            {
                cout << player2 << "'s turn (o). Enter the cell number to mark = ";
                cin >> input;
                cout << endl;

                if (!is_valid_choice(input))
                {
                    cout << "Invalid number, try again." << endl << endl;
                    continue;
                }

                choice = input[0] - '0';
                char mark2 = 'o';
                if (enter_choice(board, choice, mark2))
                {
                    display_board(board);
                    cout << endl;

                    turn++;
                    win = check_win(board);
                    if (win)
                    {
                        cout << "Congratulations, " << player2 << " wins!" << endl;
                        gameover = true;
                    }
                    draw = check_draw(board);
                    if (draw && !win)
                    {
                        cout << "It's a draw, No winner in this game." << endl;
                        gameover = true;
                    }
                }
                else
                {
                    cout << "This place is already taken, try again." << endl << endl;
                }
            }
        }

        cout << "Do you want to play again? (yes/no) = ";
        cin >> end;
        cout << endl;

        if (end[0] == 'y' || end[0] == 'Y')
        {
            condition = true;
            restart_board(board, turn);
            gameover = false;
            display_board(board);
            cout << endl;
        }
        else
        {
            condition = false;
        }
    } while (condition);

    cout << "Thanks for playing Tic Tac Toe!" << endl;
}

void display_board(char arr[3][3])
{
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "___________" << endl;
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "___________" << endl;
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
}

bool enter_choice(char arr[3][3], int choice, char mark)
{
    char choice2 = choice + '0';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == choice2)
            {
                arr[i][j] = mark;
                return true;
            }
        }
    }
    return false;
}

bool check_win(char arr[3][3])
{
    for (int r = 0; r < 3; r++)
    {
        if (arr[r][0] == arr[r][1] && arr[r][1] == arr[r][2])
        {
            return true;
        }
    }
    for (int c = 0; c < 3; c++)
    {
        if (arr[0][c] == arr[1][c] && arr[1][c] == arr[2][c])
        {
            return true;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        return true;
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
    {
        return true;
    }
    return false;
}

bool check_draw(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'x' && arr[i][j] != 'o')
            {
                return false;
            }
        }
    }
    return true;
}

void restart_board(char arr[3][3], int& turn)
{
    turn = 0;

    char count = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = count++;
        }
    }
}

bool is_valid_choice(char input[])
{
    if (input[1] != '\0')
    {
        return false;
    }
    char choice = input[0];
    if (choice >= '1' && choice <= '9')
    {
        return true;
    }
    return false;
}
