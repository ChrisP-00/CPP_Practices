#include <iostream>
#include <queue>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    // first - index, second - priority 
    queue <pair<int, int> > myQueue; 
    priority_queue <int> myPq;
    int testCase, docNum, targetIndex, printPriority, printCount = 0;

    cin >> testCase; 

    while(testCase--)
    {
        cin >> docNum >> targetIndex;

        printCount = 0;

        for(int idx = 0; idx < docNum; idx++)
        {
            cin >> printPriority;
            myPq.push(printPriority);
            myQueue.push(make_pair(idx, printPriority));
        }

         while(!myQueue.empty())
        {
            if(myQueue.front().second == myPq.top())
            {
                printCount++;

                if(myQueue.front().first == targetIndex)
                {
                    cout << printCount << '\n';
                }

                myPq.pop();
                myQueue.pop();
            }
            else
            {
                myQueue.push(myQueue.front());
                myQueue.pop();
            }
        }
    }

    return 0;
}