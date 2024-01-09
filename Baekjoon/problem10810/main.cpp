#include <iostream>
using namespace std;

int arr[101] = {0};

int main()
{
    int b1, b2, b3;

    // number of lines 
    int n;

    // number of balls 
    int m;

    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        cin >> b1 >> b2 >> b3;

        for(int j = b1; j <= b2; ++j)
        {
            arr[j] = b3;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}