#include<stdio.h>
#include "Initialize.c"

int board[3][3];

void printBoard();

// int main(){
//     startBoard();
//     printBoard(board);
//     return 0;
// }

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