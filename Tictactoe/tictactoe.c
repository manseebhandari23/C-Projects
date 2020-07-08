#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char square1[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;
char out;
int checkForWin();
void displayBoard();
int initboard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    char player1[10];
    char player2[10];
    printf("\n\n                                        WELCOME TO TIC TAC TOE GAME                                       \n\n");

    printf("\n Enter the 1st player Name:\n");
    scanf("%s",player1);

    printf("\n Enter the 2nd player Name:\n");
    scanf("%s",player2);

    player = 1;


   do
    {
      displayBoard();

      player = (player % 2) ? 1 : 2;

      printf("Player %d, Enter a Number: ", player);
      scanf("%d", &choice);

      mark = (player == 1) ? 'X' : 'O';

      markBoard(mark);

      gameStatus = checkForWin();

      player++;

    }while (gameStatus == -1);

    if (gameStatus == 1)
    {
        if(--player==1)
        {
            printf("\n          %s WON THE GAME               \n\n",strupr(player1));
        }
        else
        {
            printf("\n          %s WON THE GAME               \n\n",strupr(player2));
        }
    }
    else
    {
        printf("        GAME DRAW          \n\n");
        printf("Wants To Play Again Y/N? ");
        scanf("  %c",&out);
        if(out=='Y' || out=='y')
        {
             initboard();
             main();
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}

int initboard()
{
    int i;
    for(i=0;i<10;i++)
    {
        square[i]=square1[i];
    }
}

int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

void displayBoard()
{
    system("cls");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("      |      |     \n");
    printf("  %c   |  %c   |  %c \n", square[1], square[2], square[3]);

    printf("______|______|_____\n");
    printf("      |      |     \n");

    printf("  %c   |  %c   |  %c \n", square[4], square[5], square[6]);

    printf("______|______|_____\n");
    printf("      |      |     \n");

    printf("  %c   |  %c   |  %c \n", square[7], square[8], square[9]);

    printf("      |      |     \n\n");

}

void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("ERROR !! Already Filled Try Again ");
        player--;
        getch();
    }
}

