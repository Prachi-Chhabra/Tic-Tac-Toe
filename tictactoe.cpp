
#include <iostream>
#include <stdlib.h>
using namespace std;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


int option;
int row,col;
char turn = 'X';
bool draw = false;



void disp_board(){

    cout<<endl;
    cout<<"PLAYER - 1-> X\t PLAYER - 2 -> O\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    cout<<"\t\t     |     |     \n";
}



void pturn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }
    
    cin>> option;

    

    switch(option){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
            cout<<"INVALID";
    }

    if(turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = 'X';
        turn = 'O';
    }
    
    else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = 'O';
        turn = 'X';
    }
    
    else {
        cout<<"Already filled, Choose another number.\n\n";
        pturn();
    }

    disp_board();
}

bool gameover(){
   
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}


int main()
{
    cout<<"\t\t  TIC-TAC-TOE\t\t\t";
    cout<<"\n\t\tNO. OF PLAYERS -> 2 \n\t";
    while(gameover()){
        disp_board();
        pturn();
        gameover();
    }
    if(turn == 'O' && draw == false){
        cout<<"\n\n\t\t X WON\t\t";
    }
    else if(turn == 'X' && draw == false){
        cout<<"\n\n\t\t O WON\t\t";
    }
    else
    cout<<"\n\n\t\t DRAW!! \t\t\n\n";
} 