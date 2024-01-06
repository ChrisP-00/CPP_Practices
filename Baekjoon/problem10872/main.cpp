#include <iostream>
using namespace std;

int factorial(int x);

int main()
{
    int num;

    cin >> num;

    cout << factorial(num);

    return 0;
}

int factorial(int x)
{
    if (x <= 1) return 1;

    return x * factorial(x - 1);
}