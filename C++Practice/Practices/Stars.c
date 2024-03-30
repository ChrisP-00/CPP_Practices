#include <stdio.h>

int main()
{
    int b = 1;
    int s = 1;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5 - b; j++)
        {
            printf(" ");
        }

        for(int k = 0; k < 2 * s - 1; k++)
        {
            printf("*");
        }

        printf("\n");

        if(i == 4)
        {
            printf("\n");
            b = 6;
            s = 6;
        }

        if(i < 4)
        {
            b++;
            s++;
        }
        else
        {
            b--;
            s--;
        }
    }

    return 0;
}