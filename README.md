"Tic-Tac-Toe Game in C++"

Overview:
This is a simple **Tic-Tac-Toe** game developed in C++ where two players can take turns to play on a 3x3 board.
The game provides an interactive console-based environment, allowing users to input their moves and see the game board update in real-time.
Players can restart the game after a win, a draw, or exit once they're done.

Features:
1. Two-Player Game:
   - Player 1 uses **'x'** and Player 2 uses **'o'**.
   - Players take turns selecting cells on the board, and the game checks for wins or draws after each move.
2. Dynamic Board Display:
   - The game board is updated and displayed after each player's move, reflecting the current state of the game.
3. Win Detection:
   - The game checks for winning conditions after every move. A player wins if they successfully mark three cells in a row, column, or diagonal with their symbol.
4. Draw Detection:
   - If all cells are marked without any player winning, the game declares a draw.
5. Input Validation:
   - The game validates the player's input to ensure that the chosen cell is available and the input is correct.
6. Replay Option:
   - After each game (win or draw), players are asked if they want to play again. If they choose yes, the board is reset, and a new game begins.
7. Restartable Board:
   - The game provides the option to reset the board and start a fresh game without quitting the program.

C++ Concepts Used:
Functions:
- **`display_board()`**: Displays the current state of the game board.
- **`check_win()`**: Checks if a player has won the game by marking three consecutive cells in a row, column, or diagonal.
- **`check_draw()`**: Checks if the game is a draw (i.e., all cells are filled, but no player has won).
- **`restart_board()`**: Resets the game board and sets the turn count to 0 for a fresh game.
- **`enter_choice()`**: Marks the player's choice on the board if the cell is available and returns `true`; otherwise, returns `false`.
- **`is_valid_choice()`**: Validates the player's input to ensure they enter a valid cell number between 1 and 9.

Arrays:
- The game uses a 2D **character array** `char board[3][3]` to represent the 3x3 Tic-Tac-Toe board. Each element in the array represents a cell that can be marked by the players.
  
Control Structures:
- **`if-else`**: Used for input validation and checking win/draw conditions.
- **`for` loops**: Used to iterate over the game board for checking win conditions, displaying the board, and resetting the board.
- **`do-while`** loop**: Used to keep the game running until the players decide to stop by choosing not to play again.

How the Game Works:
Game Flow:
1. Players' Input:
   - The game prompts **Player 1** to enter their name and assigns them the symbol **'x'**.
   - Similarly, **Player 2** enters their name and is assigned the symbol **'o'**.
2. Turns:
   - Players take turns choosing a cell number (1-9) corresponding to the Tic-Tac-Toe board.
   - The game checks whether the chosen cell is valid and available. If not, the player is asked to try again.
3. Board Display:
   - After each turn, the updated game board is displayed with the current state of the cells (either marked with 'x', 'o', or left as their cell number).
4. Win or Draw Detection:
   - After each move, the game checks if the current player has won by marking three cells in a row, column, or diagonal. If a player wins, the game announces the winner.
   - If the board is filled and no one wins, the game declares a draw.
5. Replay Option:
   - After a win or draw, the players are asked if they want to play again. If they choose yes, the board is reset, and the game starts over. If no, the game ends.

Example Interaction
```
-----------------------------------
Welcome to AliImtiaz's Tic Tac Toe 
-----------------------------------

Player 1 enter your name = Alice
Player 2 enter your name = Bob

 1 | 2 | 3
___________
 4 | 5 | 6
___________
 7 | 8 | 9

Alice's turn (x). Enter the cell number to mark = 5

 1 | 2 | 3
___________
 4 | x | 6
___________
 7 | 8 | 9

Bob's turn (o). Enter the cell number to mark = 1

 o | 2 | 3
___________
 4 | x | 6
___________
 7 | 8 | 9
```
The game continues until a player wins or the board is filled.

---

Functions in Detail

### 1. `display_board()`
This function takes the current board array as input and displays it in a 3x3 grid format.
```cpp
void display_board(char arr[3][3]) {
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "___________" << endl;
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "___________" << endl;
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
}
```

### 2. `check_win()`
This function checks for a win by looking for three matching marks in a row, column, or diagonal.
```cpp
bool check_win(char arr[3][3]) {
    for (int r = 0; r < 3; r++) {
        if (arr[r][0] == arr[r][1] && arr[r][1] == arr[r][2]) {
            return true;
        }
    }
    for (int c = 0; c < 3; c++) {
        if (arr[0][c] == arr[1][c] && arr[1][c] == arr[2][c]) {
            return true;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        return true;
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        return true;
    }
    return false;
}
```

### 3. `check_draw()`
This function checks if the board is fully marked, but no player has won.
```cpp
bool check_draw(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 'x' && arr[i][j] != 'o') {
                return false;
            }
        }
    }
    return true;
}
```

### 4. `enter_choice()`
This function marks the player's choice on the board if the cell is available. If the cell is already taken, it returns `false`.
```cpp
bool enter_choice(char arr[3][3], int choice, char mark) {
    char choice2 = choice + '0';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == choice2) {
                arr[i][j] = mark;
                return true;
            }
        }
    }
    return false;
}
```

### 5. `is_valid_choice()`
This function ensures that the player's input is a valid cell number between 1 and 9.
```cpp
bool is_valid_choice(char input[]) {
    if (input[1] != '\0') {
        return false;
    }
    char choice = input[0];
    if (choice >= '1' && choice <= '9') {
        return true;
    }
    return false;
}
```

### 6. `restart_board()`
This function resets the board to its initial state and resets the turn count.
```cpp
void restart_board(char arr[3][3], int& turn) {
    turn = 0;
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = count++;
        }
    }
}
```

---

How to Run the Game:

1. Compile the Code:
   You can compile the code using any standard C

++ compiler, such as `g++`. For example:
   ```bash
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```

2. Run the Game:
   After compiling, run the program with:
   ```bash
   ./tic_tac_toe
   ```

Conclusion:
The Tic-Tac-Toe Game project is a fundamental yet practical demonstration of C++ programming concepts like arrays, loops, functions, and input validation.
It offers an interactive and enjoyable way to understand how basic logic and control structures can be applied to a real-world game scenario.
This project not only provides players with an engaging experience but also helps developers enhance their skills in implementing user interactions and game mechanics.
