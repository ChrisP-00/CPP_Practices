#include <iostream>
#include <queue> 
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    queue<int> myQueue;
    int n = 0;
    int temp = 1;
    cin >> n;

    for(int idx = 1; idx <= n; idx++)
    {
        myQueue.push(idx);
    }

    while(myQueue.size() > 1)
    {
        myQueue.pop();
        temp = myQueue.front();
        myQueue.pop();
        myQueue.push(temp);
    }

    cout << myQueue.front();

    return 0;
}