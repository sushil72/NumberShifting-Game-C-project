#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void createMAtrix(int arr[][4])
{
    int n = 15;
    int num[n];
    int lastindex = n - 1, index;

    // Fill array with desired numbers
    for (int k = 0; k < 15; k++)
        num[k] = k + 1;

    srand(time(NULL));
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (lastindex >= 0)
            {

                index = rand() % (lastindex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastindex--];
            }
        }
    }
     arr[i - 1][j - 1] = 0; 
}

void display(int arr[][4])
{
    int i, j;
    printf("-------------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf(" %2d  |", arr[i][j]);
            else
                printf("     |");
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void shiftup(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 3)
        return 0;
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1;
}
void shiftdown(int arr[][4])
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 0)
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]);
    return 1;
}
void shiftRight(int arr[][4])
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 0)
        return 0;
    swap(&arr[i][j], &arr[i][j - 1]);
    return 1;
}
void shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 3)
        return 0;
    swap(&arr[i][j], &arr[i][j + 1]);
    return 1;
}

int win(int arr[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
        {
            if (arr[i][j] != k && k != 16)
                break;
        }
    }
    if (j == 4)
        return 1;
    else
        return 0;
}

void Rules(int arr[][4])
{
    printf("Game Rules :\n1. You can move only 1 step at a time with the arrow key.\n2. You can move numbers at an empty position only.\n3. For each valid move : your total number of moves will decrease by 1.");

    printf("\n.......winning situation........\n");
    int i, j, k = 1;
    printf("-------------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++, k++)
        {
            if (arr[i][j] != 0)
                printf(" %2d  |", k);
            else
                printf("     |");
        }
        printf("\n");
    }
    printf("-------------------------\n");

    printf("\n\t\tEnter any key to start:");
    _getch();
}

/*main driver code */

int main()
{
    int moves = 5;
    int arr[4][4];
    int k;
    char name[20];
    system("cls");
    printf("\n Enter player name:");
    scanf("%s", name);

    while (1)
    {
        createMAtrix(arr);
        Rules(arr);
        while (!win(arr))
        {

            system("cls");
            printf("\n...............Press esc to exit..........\n");
            printf("\nMoves:%d\t", moves);
            printf("%s\n", name);
            if (moves == 0)
            {
                break;
            }
            display(arr);
            k = _getch();
            if (k == 0)
                k = _getch();
            switch (k)
            {
            case 72: // up key
                // printf("UP working...");
                shiftup(arr);
                moves--;
                break;
            case 75: // left key
                // printf("Left working...");
                shiftLeft(arr);
                moves--;
                break;
            case 77: // right key
                // printf("Right working...");
                shiftRight(arr);
                moves--;
                break;
            case 80: // down key
                // printf("Down working...\n");
                shiftdown(arr);
                moves--;
                break;
            case 27: // esc key
                exit(0);
            }
        }
        if (win(arr))
        {
            printf("\n\t\tCONGRATULATIONS \n");
            printf("\n\t\tYou are a winners \n");
        }
        if (moves == 0)
        {
            printf("\n\t\tNo more  moves ");
            printf("\n\t\t  You Loose \n");
        }
        char ch;
        printf("\nPress 'y' to play again:");
        scanf("%s",&ch);
        if(ch!='y')
        break;
        moves=5;

    }

    return 0;
}
