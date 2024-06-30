#include<stdio.h>
#include<ctype.h>
#include "print board.c"

int board[3][3];

typedef struct entry_
{
    char * rawtext;
    int row;
    char column;
} entry;


void askMove(entry* pEntry,int player);
void changeEntryType(entry* pEntry);


int main(){
    entry pEntry;
    printBoard();
    askMove(&pEntry,1);
    printBoard();
    // askMove(&column,&row,2);
    // printBoard();

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