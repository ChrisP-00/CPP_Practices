#include <stdio.h>

int main()
{
    int firstNum, secondNum, result = 0;
    char giho = ' ';
    
    while(1)
    {
        printf("firstNum 입력 : ");
        scanf("%d", &firstNum);

        printf("giho 입력 : ");
        scanf(" %c",&giho, 1);

        printf("secondNum 입력 : ");
        scanf("%d", &secondNum);
        
        switch (giho)
        {
            case '+' :
                result = firstNum + secondNum;
                break;
            case '-' : 
                result = firstNum - secondNum;
                break;
            case '*' :
                result = firstNum * secondNum;
                break;
            case '%' :
                result = firstNum / secondNum;
        }

        printf("%d %c %d = %d \n\n", firstNum, giho, secondNum, result);
    }

    return 0;
}