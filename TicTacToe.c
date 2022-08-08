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
int checkWinner(int who, char c, char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
void printResults(int winner, char board[BOARD_SIZE][BOARD_SIZE]); // Function Declaration
void goodbye(); // Function Declaration

int main (void)
{
    // Local Declarations
    char board[BOARD_SIZE][BOARD_SIZE]; // 2D array for our game board
    int winner; // winner of the game, 1/2 for player/computer, 3 for tie
    int numMoves; // total number of moves made on the board

    // Statements
    welcome(); // function call
    initBoard(board); // function call

    // play the game
    winner = 0;
    numMoves = 0;
    do
    {
        winner = doMoves(board); // function call
        numMoves++;

        if (numMoves == BOARD_SIZE * BOARD_SIZE && !winner)
        {
            winner = 3; // meaning it's a tie
        }
    } while (numMoves < BOARD_SIZE * BOARD_SIZE && !winner);

    printResults(winner, board); // function call
    goodbye(); // function call

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
    int winner; // winner of the game, 1/2 for player/computer, 3 for tie

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
    placeMove(choice, 'X', board); // function call
    // check for a winner real quick
    winner = checkWinner(1, 'X', board); // function call

    // computer "random" choice
    if(!winner)
    {
        printBoard(board); // function call
        do
        {
            choice = rand() % 9 + 1;
        } while (choice > 9 || choice < 1 || !validOption(choice, board));
        printf("Computer chose: %d\n", choice);
        placeMove(choice, 'O', board); // function call
        // check for a winner real quick again
        winner = checkWinner(2, 'O', board); // function call
    }

    return winner; // return the winner, if any
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

int checkWinner(int who, char c, char board[BOARD_SIZE][BOARD_SIZE])
{
    // Local Declarations
    int winner; // winner of the game, 1/2 for player/computer, 3 for tie

    // Statements
    winner = 0;

    // now check all 8 cases of winning Tic-Tac-Toe
    if (board[0][0] == c && board[0][1] == c && board[0][2] == c)
    {
        winner = who;
    }
    if (board[1][0] == c && board[1][1] == c && board[1][2] == c)
    {
        winner = who;
    }
    if (board[2][0] == c && board[2][1] == c && board[2][2] == c)
    {
        winner = who;
    }
    if (board[0][0] == c && board[1][0] == c && board[2][0] == c)
    {
        winner = who;
    }
    if (board[0][1] == c && board[1][1] == c && board[2][1] == c)
    {
        winner = who;
    }
    if (board[0][2] == c && board[1][2] == c && board[2][2] == c)
    {
        winner = who;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
    {
        winner = who;
    }
    if (board[2][0] == c && board[1][1] == c && board[0][2] == c)
    {
        winner = who;
    }

    return winner; // return the winner, if any
}

void printResults(int winner, char board[BOARD_SIZE][BOARD_SIZE])
{
    // Statements
    printf("\n--------------------");
    printBoard(board); // function call
    switch (winner)
    {
        case 1: printf("You won! Good job :)");
            break;
        case 2: printf("\nYou lost! Better luck next time :(");
            break;
        case 3: printf("\nYou tied! Well at least you didn't lose :/");
            break;
    }
    printf("\n--------------------");
}

void goodbye()
{
    // Statements
    printf("\n\nThanks for playing!\n");
    printf("Press ENTER to exit.");
    getchar();
    getchar();
}