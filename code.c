#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct sudokuBoard { int board[9][9]; };

struct sudokuBoard createSudokuBoard(struct sudokuBoard s)// There will be 30 filled in squares
{
    // Randomly pick an x and y coordinate
    // If chosen location is already filled, reroll x and y coordinate
    // Roll random number from 0 to 9
    // If chosen number is already placed vertically or horizontally on the same lines then reroll
    
    int x = rand();
    int y = rand();

    if (s.board[y][x] == 0)
    {
        printf("%s", "ran");
    }

    return s;
}

int main ()
{
    srand(time(NULL));
    struct sudokuBoard s;
    s = createSudokuBoard(s);
}

