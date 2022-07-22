#include <stdio.h>

#define BOARD_SIZE 3

void welcome(); // Function Declaration
void initBoard(char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration

int main (void)
{
    // Local Declarations
    char board[BOARD_SIZE][BOARD_SIZE]; // 2D array for our game board
    int winner; // winner of the game, 1/2 for player/computer, 0 for tie
    int numMoves; // total number of moves made on the board

    // Statements
    welcome(); // function call
    initBoard(board); // function call
    printBoard(board); // function call
    getchar();

    // play the game
    winner = 0;
    //do
    //{
    //    /* code */
    //} while (numMoves < BOARD_SIZE * BOARD_SIZE && winner == 0);

    return 0;
    // main
}

void welcome()
{
    // Statements
    printf("Welcome to the Tic-Tac-Toe Game!\n");
    printf("You will be playing against the Computer\n\n");
    printf("You are X's (you have no choice, deal with it\n\n");
}

void initBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int i; // used in outer for loop
    int j; // used in inner for loop
    int num; // numbers to init each board slot as

    // Statements
    num = 49; // ASCII table starts '1' at this value
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = num;
            num++;
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int i; // used in outer for loop
    int j; // used in inner for loop

    // Statements
    printf("\n-------");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c", board[i][j]);
        }
    }
    printf("\n-------\n");
}