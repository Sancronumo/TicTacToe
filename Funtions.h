
#ifndef FUNTIONS_H_
#define FUNTIONS_H_
// Funtions Prototypes
extern int board[3][3];

typedef struct entry_
{
    char * rawtext;
    int row;
    char column;
} entry;

void startBoard();
int checkIfWin();
void askMove(entry* pEntry,int player);
void changeEntryType(entry* pEntry);
void printBoard();
#endif // FUNTIONS_H_