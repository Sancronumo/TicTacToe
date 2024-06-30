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
int winCon(winSum* winSum1,char orientation){
    if(orientation=='D'){
        for (int x = 0; x < 2; x++)
        {
        for (int i = 0; i < 3; i++)
        {
        if (x)
        {
            if (winSum1->value==board[i][2-i]){
            winSum1->times++;
            }else{
            winSum1->times=0;
            winSum1->value=board[i][2-i];
            }
        }else
        {
            if (winSum1->value==board[i][i]){
            winSum1->times++;
            }else{
            winSum1->times=0;
            winSum1->value=board[i][i];
            }
        }
        }
        if (winSum1->times==2)
        {
            return true;
        }
        }
    return false;
    }

    int a,b;
    for (int i = 0; i < 3; i++)
    {
    winSum1->value=0;
    winSum1->times=0;
    for (int j = 0; j < 3; j++)
    {
        if (orientation=='V')
        {
            a=j;
            b=i;
        }else{
            a=i;
            b=j;
        }
        
        if (!(board[a][b]==' '))
        {
            if (winSum1->value==board[a][b])
            {
                winSum1->times++;
            }else{
                winSum1->times=0;
                winSum1->value=board[a][b];
            }
            
        }
        
    }
    if (winSum1->times==2)
    {
        return true;
    }
        
    }
    return 0;
}


int checkIfWin(){
    bool win=false;
    winSum winSum1;   
    win=winCon(&winSum1,'D');
    win=winCon(&winSum1,'V')? winCon(&winSum1,'V'):win;
    win=winCon(&winSum1,'H')? winCon(&winSum1,'H'):win;
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
