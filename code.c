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

    int cell_min_number = 1;
    int cell_max_number = 9;
    int min_number = 0;
    int max_number = 8;
    int filled_cells = 0;

    while (filled_cells != 30) // While filled cells is not equal to 30
    {

        int x = rand() % (max_number + 1 - min_number) + min_number;
        int y = rand() % (max_number + 1 - min_number) + min_number;

        if (s.board[y][x] == 0) // If randomly selected cell is empty
        {

            int filling_cell = 1;

            while (filling_cell)
            {

                int is_number_colliding = 0;
                int cell_number = rand() % (cell_max_number + 1 - cell_min_number) + cell_min_number;
                int i;
                int i2;

                for (i = 0; i < 9; i++)
                {
                    if (s.board[y][i] == cell_number)
                    {
                        is_number_colliding = 1;
                    }
                }

                for (i = 0; i < 9; i++)
                {
                    if (s.board[i][x] == cell_number)
                    {
                        is_number_colliding = 1;
                    }
                }

                if (x == 0 || x == 1 || x == 2)
                {
                    if (y == 0 || y == 1 || y == 2)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (i2 = 0; i2 < 3; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }    
                    }
                }

                if (x == 3 || x == 4 || x == 5)
                {
                    if (y == 0 || y == 1 || y == 2)
                    {
                        for (i = 3; i < 6; i++)
                        {
                            for (i2 = 0; i2 < 3; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            } 
                        }
                    }
                }

                if (x == 6 || x == 7 || x == 8)
                {
                    if (y == 0 || y == 1 || y == 2)
                    {
                        for (i = 6; i < 9; i++)
                        {
                            for (i2 = 0; i2 < 3; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (x == 0 || x == 1 || x == 2)
                {
                    if (y == 3 || y == 4 || y == 5)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (i2 = 3; i2 < 6; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (x == 3 || x == 4 || x == 5)
                {
                    if (y == 3 || y == 4 || y == 5)
                    {
                        for (i = 3; i < 6; i++)
                        {
                            for (i2 = 3; i2 < 6; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (x == 6 || x == 7 || x == 8)
                {
                    if (y == 3 || y == 4 || y == 5)
                    {
                        for (i = 6; i < 9; i++)
                        {
                            for (i2 = 3; i2 < 6; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (x == 0 || x == 1 || x == 2)
                {
                    if (y == 6 || y == 7 || y == 8)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (i2 = 6; i < 9; i++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (x == 3 || x == 4 || x == 5)
                {
                    if (y == 6 || y == 7 || y == 8)
                    {
                        for (i = 3; i < 6; i++)
                        {
                            for (i2 = 6; i2 < 9; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if ( x == 6 || x == 7 || x == 8)
                {
                    if (y == 6 || y == 7 || y == 8)
                    {
                        for (i = 6; i < 9; i++)
                        {
                            for (i2 = 6; i2 < 9; i2++)
                            {
                                if (s.board[i2][i] == cell_number)
                                {
                                    is_number_colliding = 1;
                                }
                            }
                        }
                    }
                }

                if (is_number_colliding == 0)
                {
                    s.board[y][x] = cell_number;
                    ++filled_cells;
                    filling_cell = 0;
                }
            }
        }
    }


    return s;
}

void printBoard (struct sudokuBoard s)
{
    int x;
    int y;

    printf("  A B C   D E F   G H I\n");
    for (y = 0; y < 9; y++)
    {
        if (y == 0)
        {
            printf("- - - - - - - - - - - - -");
            printf("\n");
        }

        for (x = 0; x < 9; x++)
        {
            if (x == 0)
            {
                printf("| ");
            }

            printf("%d", s.board[y][x]);

            if (x == 2 || x == 5)
            {
                printf(" |");
            }
            else if (x == 8)
            {
                printf(" |");

                switch (y)
                {
                    case 0:
                        printf(" 1");
                        break;
                    case 1:
                        printf(" 2");
                        break;
                    case 2:
                        printf(" 3");
                        break;
                    case 3:
                        printf(" 4");
                        break;
                    case 4:
                        printf(" 5");
                        break;
                    case 5:
                        printf(" 6");
                        break;
                    case 6:
                        printf(" 7");
                        break;
                    case 7:
                        printf(" 8");
                        break;
                    case 8:
                        printf(" 9");
                        break;
                }
            }

            printf(" ");
        }
        if (y == 2 || y == 5 || y == 8)
        {
            printf("\n");
            printf("- - - - - - - - - - - - -");
        }
        printf("\n");
    }
}

int main ()
{
    srand(time(NULL));
    struct sudokuBoard s;
    int x;
    int y;
    int gameloop = 1;

    for (y = 0; y < 9; y++)
    {
        for (x = 0; x < 9; x++)
        {
            s.board[y][x] = 0;
        }
    }

    s = createSudokuBoard(s);

    while (gameloop)
    {
        char gridChange[2];
        int numberChange;
        int x;
        int y;

        printBoard(s);

        printf("What grid are you changing?: ");
        scanf("%s", &gridChange);

        printf("What are you changing the number to?: ");
        scanf("%d", &numberChange);

        if (gridChange[0] == 'A')
        {
            x = 0;
        } else if (gridChange[0] == 'B')
        {
            x = 1;
        } else if (gridChange[0] == 'C')
        {
            x = 2;
        } else if (gridChange[0] == 'D')
        {
            x = 3;
        } else if (gridChange[0] == 'E')
        {
            x = 4;
        } else if (gridChange[0] == 'F')
        {
            x = 5;
        } else if (gridChange[0] == 'G')
        {
            x = 6;
        } else if (gridChange[0] == 'H')
        {
            x = 7;
        } else if (gridChange[0] == 'I')
        {
            x = 8;
        }


        y = atoi(&gridChange[1]) - 1;
        s.board[y][x] = numberChange;

        }
    return 0;
}

