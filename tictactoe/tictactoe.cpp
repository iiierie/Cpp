/*This program is a Tic Tac Toe game. It allows two players to take turns and mark spaces in a 3x3 grid. The players are represented by the turns X and O, and the game ends when one of the players gets three turns in a row either horizontally, vertically, or diagonally, or when all the spaces in the grid have been filled without a winner. 

The program consists of several functions:

1. `make_table()`: This function displays the current state of the game board.

2. `choose_slot()`: This function prompts the player to select a slot to mark with their turn and updates the game board accordingly.

3. `gameover()`: This function checks whether the game has ended and returns true if it has, indicating that the game should stop.

The program uses a two-dimensional character array `space[3][3]` to represent the game board, where each element of the array represents a space on the board. The turns X and O are represented by the characters 'X' and 'O', respectively.

The program also uses global variables to keep track of the game state, such as the current player's turn and whether the game has ended in a tie.*/




#include<bits/stdc++.h>
using namespace std;
//global variables declaration
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int r,c;
char turn = 'X';
string n1,n2;
bool ties = false;
bool gameover(void);
void make_table(){
    // function for the structure of tic tac toe
    // for the table of tic tac toe
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"   "<<space[0][0]<<"\t|   "<<space[0][1]<<"\t|   "<<space[0][2]<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"________|"<<"_______|"<<"_______"<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"   "<<space[1][0]<<"\t|   "<<space[1][1]<<"\t|   "<<space[1][2]<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"________|"<<"_______|"<<"_______"<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"\t|"<<"\t|"<<endl;
    cout<<"   "<<space[2][0]<<"\t|   "<<space[2][1]<<"\t|   "<<space[2][2]<<endl;
    cout<<"\t|"<<"\t|"<<endl;
}

void choose_slot(){
    //enter where to place X and Os
    //function to place our moves in the table
    // n1 -> X
    // n2 -> O
    int slot; // slot in the table
    if(turn == 'X'){
        cout<<"Your turn "<<n1<<":";
        cin>>slot;
    }
    if(turn == 'O'){
        cout<<"Your turn "<<n2<<":";
        cin>>slot;
    }


    //CASES ( 1 to 9)
    switch (slot)
    {
    case 1:
        r = 0;
        c = 0;
        break;
    case 2:
        r = 0;
        c = 1;
        break;
    case 3:
        r = 0;
        c = 2;
        break;
    case 4:
        r = 1;
        c = 0;
        break;
    case 5:
        r = 1;
        c = 1;
        break;
    case 6:
        r = 1;
        c = 2;
        break;
    case 7:
        r = 2;
        c = 0; 
        break;
    case 8:
        r = 2;
        c = 1;
        break;
    case 9:
        r = 2;
        c = 2;
        break;
    
    default:
        cout<<" Invalid move!"<<endl;
        break;
    }


    if(turn == 'X' && space[r][c] != 'X' && space[r][c] != 'O'){ // if its n1's (X) turn and the slot entered is free
        space[r][c] = 'X'; //fill that space with X
        turn = 'O'; //next turn of O
    }
    else if(turn == 'O' && space[r][c] != 'X' && space[r][c] != 'O'){ // if its n2's (O) turn and the slot entered is free
        space[r][c] = 'O'; //fill that space with O
        turn = 'X'; // next turn of X
    }
    else{
        cout<<"That space is already full. Choose an empty slot."<<endl; // if slot already filled then prompt and then another chance to enter the slot
        choose_slot(); 
    }

}

bool gameover(){ //returns true  when match needs to stop i.e. gameover

    for(int i = 0;i<3;i++){
        //horizontal row and vertical column all 3 matching so one of them won  match needs to stop
        if((space[i][0]== space[i][1] && space[i][0] == space[i][2]) || space[0][i] == space[1][i] && space[0][i] == space[2][i]){
            return true;
        }
        //diagonal matching all 3 matching so one of them won match needs to stop
        if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0])){
            return true;
        }
    }


        // space is not full so match needs to continue
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(space[i][j] != 'X' && space[i][j] != 'O'){
                    return false; 
                }
                }
            }
            //if no slots empty and no winning condition met then it is a tie 
        ties = true;
        return true;
    }

int main(){
    //step 1: enter details of players and first player plays X
    cout<<"Enter the name of player 1: ";
    cin >> n1;
    cout<<"Enter the name of player 2: ";
    cin >> n2;
    cout<<endl;

    cout<<n1<<" will go first and play X."<<endl;
    cout<<n2<<" will go second and play O."<<endl;
    cout<<endl;

    // until the all space is full & it is a tie or one of the player wins; keep taking input from both players and checking simultaneouly 
   while(!gameover()){
        make_table();
        cout<<endl;
        choose_slot();
        gameover();
   }

//comes out of loop when when winning conditions are met i.e match stops
   if(turn == 'X' && ties == false){ // when match stops and  its X turn and there's no tie then O has won
    cout<<n2<<" won."<<endl;
   }
   else if(turn == 'O' && ties == false){ //when match already stop and its O turn and there's no tie then X has won
    cout<<n1<<" won."<<endl;
   }
   else{ // if match stopped and nobody won then the game was prolly a draw.
    cout<<"The game was a draw."<<endl;
   }
    return 0;
}