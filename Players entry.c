#include<stdio.h>
#include<ctype.h>
#include "print board.c"

int board[3][3];

void askMove(char * column, int *row,int player);
void changeEntryType(char * column,int * row);

int main(){
    char column;
    int row;
    printBoard();
    askMove(&column,&row,1);
    printBoard();
    askMove(&column,&row,2);
    printBoard();

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