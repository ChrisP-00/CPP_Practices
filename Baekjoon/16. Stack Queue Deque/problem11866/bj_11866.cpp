#include <iostream>
#include <queue>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std; 

int main()
{
    fastTime;

    queue <int> myQueue;
    queue <int> tempQueue;
    queue <int> resultQueue;

    int n, k, idx = 0;

    cin >> n >> k;

    idx = 1;

    while(n--)
    {
        myQueue.push(idx++);
    }

    idx = 1;

    while(!myQueue.empty())
    {
        while(!myQueue.empty())
        {
            if(idx == k)
            {
                resultQueue.push(myQueue.front());
                myQueue.pop();
                idx = 0;
            }
            else
            {
                tempQueue.push(myQueue.front());
                myQueue.pop();
            }

            idx++;
        }

        if(!tempQueue.empty())
        {
            swap(myQueue, tempQueue);
        }
    }

    cout << "<" << resultQueue.front();
    resultQueue.pop();

    while(!resultQueue.empty())
    {
        cout << ", " << resultQueue.front();
        resultQueue.pop();
    }

    cout << ">";

    return 0;
}