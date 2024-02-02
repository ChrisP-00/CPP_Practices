#include <iostream>
using namespace std;

bool numbers[10001] = {false};

int d(int n)
{
    int sum = n;

    while(n != 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    return sum;
}



int main()
{
    for(int i = 1; i <= 10000; ++i)
    {
        numbers[d(i)] = true;
    }

    for(int i = 1; i <= 10000; ++i)
    {
        if (numbers[i] == false)
        {
            cout << i << endl;
        }
    }


    return 0;    
}


