#include <iostream>
#include <stack>
#include <string>
#include <queue>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    queue <string> results;
    stack <char> myStack;

    int testCases, idx, size = 0;
    string bracket;

    cin >> testCases;

    while(testCases--)
    {
        cin >> bracket;

        size = bracket.length();

        bool isCorrect = true;
        idx = 0;

        while(idx < size && isCorrect)
        {
            if(bracket[idx] == '(')
            {
                myStack.push(bracket[idx]);
            }

            else
            {
                if(myStack.empty())
                {
                    isCorrect = false;
                    break;
                }

                else
                {
                    myStack.pop();
                }
            }
            idx++;
        }

        if(!isCorrect)
        {
            results.push("NO");
        }
        else
        {
            myStack.empty() ? results.push("YES") : results.push("NO");
        }

        // clear stack 
        while(!myStack.empty())
        {
            myStack.pop();
        }
    }

    testCases = results.size();

    while(testCases--)
    {
        cout << results.front() << "\n";
        results.pop();
    }

    return 0;
}