#include<stdbool.h>
#include<stdio.h>
#include<ctype.h>
#include "Funtions.h"

// Funtions
void startBoard(){
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=(int)' ';
        }
        
    }
}
int winCondH(int i){
    return board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&(board[i][0]=='X'||board[i][0]=='O');
}

int winCondV(int j){
    return board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&(board[0][j]=='X'||board[0][j]=='O');
}


int checkIfWin(){
    bool win=false;
    for (int i = 0; i < 3; i++)
    {
        win=winCond(i);
        if (win)
        {
            return win;
        }
        
    }
    for (int j = 0; j < 3; j++)
    {
        win=winConV(j);
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

void askMove(char * column,int * row,int player){
    char confirm='n';
    printf("Enter the column and row no spaces:\n");
    scanf(" %c%d",column,row);
    *column=toupper(*column);
    printf("Did you choose %c%d?(y:yes,n:no)\n",*column,*row);
    scanf(" %c",&confirm);
    if(confirm=='y')
    {
        printf("Making your move... \n");
        char charToPrint;
        if (player==1)
        {
            charToPrint='X';
        }else{
            charToPrint='O';
        }
        changeEntryType(column,row);
        if (board[*row][*column]==0)
        {
            board[*row][*column]=charToPrint;
        }else{
            printf("Space already filled, try again\n");
            askMove(column,row,player);
        }
        
    }else{
        if (confirm!='n')
        {
            printf("No valid entry, try again\n");
        }
        
        askMove(column,row,player);
    }
}

void changeEntryType(char * column,int * row){
    *row=*row-1;
    switch (*column)
        {
        case 'A':
            *column=0;
            break;
        case 'B':
            *column=1;
            break;
        case 'C':
            *column=2;
            break;
        }
}

void printBoard(){
    for (int i=0;i<3;i++){
        if (i!=0)
        {
            printf("  -----------------------------\n");
        }else{
            printf("%5cA%9cB%9cC\n",' ',' ',' ');
        }
        printf("%d",i+1);
        for(int j=0;j<3;j++){
            printf("%5c",board[i][j]);
            if (j<2)
            {
                printf("    |");
            }
            
        }
        printf("\n");
    }
}
