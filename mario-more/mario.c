#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Height:
    int h;
    do
    {
        h = get_int("Height: ");
    }while (h < 1 || h > 8);

    int row = 0;
    while (row < h)
    {
        //Space 1:
        for (int i = 0; i < h - row - 1; i++)
        {
            printf(" ");
        }

        //Left:
        for (int j = 0; j < row + 1; j++)
        {
            printf("#");
        }

        //Space 2:
        printf("  ");

        //Right:
        for (int j = 0; j < row + 1; j++)
        {
            printf("#");
        }
        printf("\n");
        row++;
    }

}