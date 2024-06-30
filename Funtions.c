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

void askMove(entry* pEntry,int player){
    char confirm='n';
    printf("Enter the column and row no spaces:\n");
    scanf(" %c%d",&pEntry->column,&pEntry->row);
    pEntry->column=toupper(pEntry->column);
    printf("Did you choose %c%d?(y:yes,n:no)\n",pEntry->column,pEntry->row);
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
        changeEntryType(pEntry);
        if (board[pEntry->row][pEntry->column]==0)
        {
            board[pEntry->row][pEntry->column]=charToPrint;
        }else{
            printf("Space already filled, try again\n");
            askMove(pEntry,player);
        }
        
    }else{
        if (confirm!='n')
        {
            printf("No valid entry, try again\n");
        }
        
        askMove(pEntry,player);
    }
}

void changeEntryType(entry* pEntry){
    pEntry->row--;
    switch (pEntry->column)
        {
        case 'A':
            pEntry->column=0;
            break;
        case 'B':
            pEntry->column=1;
            break;
        case 'C':
            pEntry->column=2;
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
