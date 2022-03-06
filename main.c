#include <stdio.h>
#include <stdlib.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

_Bool isGameOver(int turn, int playerNum);
void displayBoard();
void playGame();

int main() 
{
    playGame();
    return 0;
}

void playGame() {
    int turnCount = 0;
    int player = 1;
    while (!isGameOver(turnCount, player))
    {
        player = turnCount % 2 + 1;
        int choice;
        system("cls");
        printf("\n\tTic Tac Toe\n\n");
        printf("Player 1 (X) - Player 2 (O)\n\n");
        displayBoard();
        printf("\nPlayer %d, enter a number:\n", player);
        scanf("%d", &choice);
        choice -= 1;
        if (board[choice] && (board[choice] != 'X' && board[choice] != 'O'))
        {
            board[choice] = player == 1 ? 'X' : 'O';
            turnCount++;
        } else {
            printf("\nWRONG, please choose a valid spot\n");
        }
    }
}

_Bool isGameOver(int turn, int playerNum) {
    if (turn > 8) 
    {
        system("cls");
        displayBoard();
        printf("Too bad, no one wins\n\n");
        return 1;
    }

    if ((board[0] == board[1] && board[0] == board[2]) || 
        (board[3] == board[4] && board[3] == board[5]) ||
        (board[6] == board[7] && board[6] == board[8]) ||
        (board[0] == board[3] && board[0] == board[6]) ||
        (board[1] == board[4] && board[1] == board[7]) ||
        (board[2] == board[5] && board[2] == board[8]) ||
        (board[0] == board[4] && board[0] == board[8]) ||
        (board[2] == board[4] && board[2] == board[6])) 
        {   
            system("cls");
            displayBoard();
            printf("\n\nCongratulations player %d, you win!\n\n", playerNum);
            return 1;
        }
    return 0;
}

void displayBoard() 
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("   |   |   \n");
}