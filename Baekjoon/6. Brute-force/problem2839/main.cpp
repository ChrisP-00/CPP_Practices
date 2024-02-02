#include <iostream>

int sugarBag(int sugar)
{
    int result = 0;

    sugar /= 5;


    if(sugar < 3)
    {
       result = -1;
    }

    else
    {
        sugarBag(sugar);
    }

    return result; 
}

int main()
{

    return 0;
}

