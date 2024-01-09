#include <iostream>
#include <queue>
using namespace std;

int arr[101] = {0};
queue<int> q;

int main()
{
    int n, m, i, j;

    cin >> n >> m;

    for(int a = 1; a <= n; ++a)
    {
        arr[a] = a;
    }

    for(int a = 0; a < m; ++a)
    {
        cin >> i >> j;

        for(int b = i; b <= j; ++b)
        {
            q.push(arr[b]);
        }

        for(int b = j; b >= i; --b)
        {
            arr[b] = q.front();
            q.pop();
        }
    }

    for(int a = 1; a <= n; ++a)
    {
        cout << arr[a] << " ";
    }


    return 0;
}