#include<stdio.h>
#include<stdbool.h>
#include "Initialize.c"
int board[3][3];

typedef struct winSum_
{
    int value;
    int times;
} winSum;

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

// int main(){
//     startBoard();
//     board[0][0]='O';
//     board[1][1]='O';
//     board[][2]='O';
//     printf("Devolvio: %d",checkIfWin());
//     return 0;
//     }
