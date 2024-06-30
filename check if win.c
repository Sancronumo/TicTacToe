#include<stdio.h>
#include<stdbool.h>
int board[3][3];

typedef struct winSum_
{
    int value;
    int times;
} winSum;


int checkIfWin(){
    bool win=false;
    for (int i = 0; i < 3; i++)
    {
        win=board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&(board[i][0]=='X'||board[i][0]=='O');
        if (win)
        {
            return win;
        }
        
    }
    for (int j = 0; j < 3; j++)
    {
        win=board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&(board[0][j]=='X'||board[0][j]=='O');
        if (win)
        {
            return win;
        }
    }
    win=board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&(board[0][0]=='X'||board[0][0]=='O');
    if (win)
        {
            return win;
        }
    win=board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&(board[2][0]=='X'||board[2][0]=='O');
    return win;
    
    
}

// int main(){
//     board[0][0]='X';
//     board[1][1]='X';
//     board[2][2]='X';
//     printf("%d",checkIfWin());
//     return 0;