#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long a, b, c;

    cin >> a >> b >> c;

    a = pow(a,b);

    cout << a % c;

    return 0;
}