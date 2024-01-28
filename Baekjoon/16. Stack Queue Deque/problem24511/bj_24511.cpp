#include <iostream>
#include <deque>
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    deque <int> myDeque;
    bool checkQueueStack[100001] = {false};
    int sequanceCount, num = 0;

    cin >> sequanceCount; 

    // 0 == queue, 1 == stack 
    for(int idx = 0; idx < sequanceCount; idx++)
    {
        cin >> checkQueueStack[idx];
    }

    for(int idx = 0; idx < sequanceCount; idx++)
    {
        cin >> num;

        if(!checkQueueStack[idx])
        {
            myDeque.push_back(num);
        }
    }

    cin >> sequanceCount; 

    for(int idx = 0; idx < sequanceCount; idx++)
    {
        cin >> num;

        if(myDeque.empty())
        {
            cout << num << ' ';
            continue;
        }

        cout << myDeque.back() << ' ';
        myDeque.push_front(num);
        myDeque.pop_back();
    }

    return 0;
}

