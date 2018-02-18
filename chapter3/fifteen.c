/**
 * fifteen.c
 *
 * CS50 AP
 * Fifteen
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 * Extra features including printing an actual grid to make it look more
 * tile-like, and using ANSI color sequences for some additional customizing
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// ansi escape sequence to print grid color
// replace the number beteen [ and m with 31 for red, 32 for green, 33 for brown,
// 34 for blue, 35 for purple, 36 for cyan, 37 for gray
#define COLOR "\033[32m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// saved locations of the blank tile
int blank_row;
int blank_col;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int nums = d * d - 1;
    // Iterate and add values to 2d array from nums to 0
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = nums;
            nums--;
            // Special case to make the game solvable if d is even
            if (nums == 0 && d % 2 == 0)
            {
                board[i][j - 1] = 1;
                board[i][j] = 2;
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Print "_" if zero, else print the coresponding number
            (board[i][j] == 0) ? printf(" _ ") : printf("%2i ", board[i][j]);
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // Check if tile is in boundaries
    if (d * d - 1 < tile || tile < 1)
    {
        return false;
    }

    int row, column;

    // Determine the coordinates of given tile
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                row = i;
                column = j;
            }
        }
    }

    // Check and swap
    if (row + 1 < d && board[row + 1][column] == 0)
    {
        board[row + 1][column] = tile;
        board[row][column] = 0;
        return true;
    }
    else if (row - 1 >= 0 && board[row - 1][column] == 0)
    {
        board[row - 1][column] = tile;
        board[row][column] = 0;
        return true;
    }
    else if (column + 1 < d && board[row][column + 1] == 0)
    {
        board[row][column + 1] = board[row][column];
        board[row][column] = 0;
        return true;
    }
    else if (column - 1 >= 0 && board[row][column - 1] == 0)
    {
        board[row][column - 1] = board[row][column];
        board[row][column] = 0;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int nums = 1;

    // Iterate through board, if it's in order nums == d * d
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != nums)
            {
                // Winning condition will find '0' at the end of the board will return true instead of false
                return (nums == d * d);
            }
            nums++;
        }
    }
    return false;
}
