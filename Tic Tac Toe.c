#include<stdio.h>
#include<stdbool.h>
#include "Funtions.h"
// Global variable
int board[3][3];
struct playerEntry
{
    char column;
    int row;
};


int main(){
    int player=1, turns=1, row;
    char column;
    bool draw=false;

    while (!(checkIfWin()))
    {
        player = (turns%2!=0)? 1: 2;
        printBoard();
        printf("Player %d goes. ",player);
        askMove(&column,&row,player);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                draw=(board[i][j]==0);
            }
            
        }
        if (!draw)
        {
            printf("It's a draw, good luck next time.\n");
            break;
        }
        
        ++turns;
    }
    if (draw)
    {
        printf("Player %d wins!",player);
    }

}