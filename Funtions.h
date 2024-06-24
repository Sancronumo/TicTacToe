
#ifndef FUNTIONS_H_
#define FUNTIONS_H_
// Funtions Prototypes
extern int board[3][3];

void startBoard();
int checkIfWin();
void askMove(char * column,int * row,int player);
void changeEntryType(char * column,int * row);
void printBoard();
#endif // FUNTIONS_H_