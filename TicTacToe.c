#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOARD_SIZE 3

void welcome(); // Function Declaration
void initBoard(char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
int doMoves(char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
int validOption(int num, char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
void placeMove(int num, char c, char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration

int main (void)
{
    // Local Declarations
    char board[BOARD_SIZE][BOARD_SIZE]; // 2D array for our game board
    int winner; // winner of the game, 1/2 for player/computer, 0 for tie
    int numMoves; // total number of moves made on the board

    // Statements
    welcome(); // function call
    initBoard(board); // function call

    // play the game
    winner = 0;
    do
    {
        winner = doMoves(board); // function call
    } while (numMoves < BOARD_SIZE * BOARD_SIZE && !winner);

    getchar();

    return 0;
    // main
}

void welcome()
{
    // Statements
    printf("Welcome to the Tic-Tac-Toe Game!\n");
    printf("You will be playing against the Computer\n\n");
    printf("You are X's (you have no choice, deal with it\n");
    printf("Press ENTER to begin...");
    getchar();
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

int doMoves(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int i; // used in outer for loop
    int j; // used in inner for loop
    int choice; // what number the user enters
    int winner; // if someone has won the game or not

    // Statements
    winner = 0;
    // get player input choice
    do
    {
        printBoard(board); // function call
        printf("Where would you like to place? (type number) -> ");
        scanf("%d", &choice);

        if (choice > 9 || choice < 1 || !validOption(choice, board))
        {
            printf("Please enter a valid option!\n");
        }
    } while (choice > 9 || choice < 1 || !validOption(choice, board));
    placeMove(choice, 'X', board);

    // computer "random" choice
    //printBoard(board);
    //do
    //{
    //    choice = rand() % 9 + 1;
    //    if (choice > 9 || choice < 1 || !validOption(choice, board))
    //    {
    //        printf("DEBUG: Rerolling Computer choice...\n");
    //    }
    //} while (choice > 9 || choice < 1 || !validOption(choice, board));
    //printf("Computer chose: %d\n", choice);

    return winner;
}

int validOption(int num, char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int i; // used in outer for loop
    int j; // used in inner for loop
    int valid; // if the given number is a valid option in the board
    char charNum; // char version of the integer input number

    // Statements
    charNum = num + '0';
    valid = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == charNum)
            {
                valid = 1;
            }
        }
    }

    return valid; // return if the given number is a valid option in the board
}

void placeMove(int num, char c, char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int row; // row
    int col; // column

    // Statements
    row = ceil((double) (num) / 3.0) - 1;
    switch (num)
    {
        case 1:
        case 4:
        case 7: col = 0;
            break;
        case 2:
        case 5:
        case 8: col = 1;
            break;
        case 3:
        case 6:
        case 9: col = 2;
            break;
    }
    board[row][col] = c;
}