#include <iostream>
#include <queue>
#include <string>
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    queue <int> myQueue;
    queue <int> resultQueue;

    string command = "";

    int commandsCount = 0;
    int num = 0;

    cin >> commandsCount;

    while(commandsCount--)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> num;
            myQueue.push(num);
        }
        else if(command == "pop")
        {
            if(myQueue.empty())
            {
                resultQueue.push(-1);
            }
            else
            {
                resultQueue.push(myQueue.front());
                myQueue.pop();
            }
        }
        else if(command == "size")
        {
            resultQueue.push(myQueue.size());
        }
        else if(command == "empty")
        {
            myQueue.empty() ? resultQueue.push(1) : resultQueue.push(0);
        }
        else if(command == "front")
        {
            myQueue.empty() ? resultQueue.push(-1) : resultQueue.push(myQueue.front());
        }
        else if(command == "back")
        {
            myQueue.empty() ? resultQueue.push(-1) : resultQueue.push(myQueue.back());
        }
    }

    while(!resultQueue.empty())
    {
        cout << resultQueue.front() << '\n';
        resultQueue.pop();
    }

    return 0;
}