#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //number of card:
    long card_number = get_long("Number: ");

    int size = 0;
    int first_figure;
    int second_figure;
    int checksum = 0;
    long  remain_figures = card_number;
    //caculate result:
    while (remain_figures > 0)
    {
        int figure = remain_figures % 10;
        remain_figures = remain_figures / 10;
        if (size > 0)
        {
            second_figure = first_figure;
        }
        first_figure = figure;
        if (size % 2 == 0)
        {
            checksum += figure;
        }
        else
        {
            checksum += figure * 2 % 10 + figure * 2 / 10;
        }
        size++;
    }

    //check result:
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //AMEX:
    if (size == 15 && first_figure == 3 && (second_figure == 4 || second_figure == 7))
    {
        printf("AMEX\n");
        return 0;
    }

    //MasterCard
    if (size == 16 && first_figure == 5 && (second_figure >= 1 && second_figure <= 5))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    //Visa
    if ((size == 13 || size == 16) && first_figure == 4)
    {
        printf("VISA\n");
        return 0;
    }
    printf("INVALID\n");
}