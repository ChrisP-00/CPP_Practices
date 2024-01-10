#include <iostream>
using namespace std; 

int main()
{
    int n;
    int dot = 2; 

    cin >> n;

    while(n--)
    {
        dot += dot - 1;
    }

    cout << dot * dot;

    return 0;
}