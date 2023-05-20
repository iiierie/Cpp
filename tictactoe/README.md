# Tic-Tac-Toe-in-CPP
## Extremely simple and beginner level Tic Tac Toe Game in CPP

**This is a Tic Tac Toe game written in C++. The program allows two players to play the game. The players can enter their names, and the first player will play as "X".**

The game is played on a 3x3 grid. The players take turns to place their symbol ("X" or "O") on an empty slot in the grid. The game ends when one of the players has three symbols in a row (horizontally, vertically, or diagonally), or when all slots in the grid are filled (in which case the game ends in a tie).

The program uses a 2D array to represent the grid, and various functions are defined to check for winning conditions, to display the grid, and to get the player's move.

To play the game, the user needs to compile and run the program. The program will prompt the users to enter their names and will display the initial grid. The players can then take turns to enter the slot where they want to place their symbol. The program will check for winning conditions after each move and will display the updated grid. If a winning condition is met, the program will declare the winner and end the game. If all slots in the grid are filled and no winning condition is met, the game will end in a tie.



## Functions in the code:
- **make_table()**
This function is used to display the current state of the tic-tac-toe board. It prints the current state of the space array using formatted output to show the board.

- **choose_slot()**
This function prompts the current player to choose a slot on the board where they want to place their marker (X or O). It takes input from the player and updates the space array with the chosen marker if the chosen slot is not already occupied. If the chosen slot is already occupied, the function prompts the player to choose another slot.

- **gameover()**
This function checks whether the game is over by checking the state of the space array. It checks for winning conditions by checking if any row, column or diagonal has all the same markers. If a winning condition is found, the function returns true, indicating that the game is over. If no winning condition is found, the function checks if all the slots on the board are occupied. If all the slots are occupied and no winning condition is found, the function returns true, indicating that the game is over and that it is a tie. If there are still empty slots on the board and no winning condition is found, the function returns false, indicating that the game is not over yet.

- **main()**
This function is the entry point for the program. It first prompts the user to enter the names of the players and sets the first player to play as X. It then enters a loop that continues until the game is over. In each iteration of the loop, it calls make_table() to display the current state of the board, prompts the current player to choose a slot using choose_slot(), and checks if the game is over using gameover(). If the game is over, it prints the result of the game (win or tie) and prompts the user to play again. If the user chooses to play again, the function resets the space array and the current player to X. If the user chooses not to play again, the program exits.
