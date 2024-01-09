#include <iostream>
using namespace std;

int arr[101] = {0}; 

int main()
{
    int n, m, b1, b2;

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        arr[i] = i;
    }

    for(int i = 0; i < m; ++i)
    {
        cin >> b1 >> b2; 

        int temp; 

        temp = arr[b1];
        arr[b1] = arr[b2];
        arr[b2] = temp;
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}