#include <stdio.h>
// Note for the future: Make it with pointer
int board[3][3];

void startBoard();

// This is just to try this code
// int main(){
//     startBoard();
//     printf("%d %c",board[1][1],(char)board[1][1]);
//     return 0;
// }

void startBoard(){
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=(int)' ';
        }
        
    }
}