#include <iostream>
#include <stack>
#include <queue>
#include <string>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    stack <char> bracket;
    queue <string> resultQueue;

    string testSentence = ""; 
    bool isTest = true;
    bool isBalanced = true;
    int idx = 0;

    while(isTest)
    {
        getline(cin, testSentence);

        if(testSentence[0] == '.')
        {
            isTest = false;
            break;
        }

        isBalanced = true;
        idx = 0;
        
        while(testSentence[idx] != '.' && isBalanced)
        {
            switch(testSentence[idx])
            {
                case '(':
                    bracket.push('(');
                    break;
                case ')':
                    if(bracket.empty() || bracket.top() != '(')
                    {
                        isBalanced = false;
                        break;
                    }
                    bracket.pop();
                    break;
                case '[':
                    bracket.push('[');
                    break;
                case ']':
                    if(bracket.empty() || bracket.top() != '[') 
                    {
                        isBalanced = false;
                        break;
                    }
                    bracket.pop();
                    break;
            }

            idx++;
        }

        if(isBalanced && bracket.empty())
        {
            resultQueue.push("yes");
        }
        else if(!isBalanced || !bracket.empty())
        {
            resultQueue.push("no");
        }

        while(!bracket.empty())
        {
            bracket.pop();
        }
    }

    while(!resultQueue.empty())
    {
        cout << resultQueue.front() << '\n';
        resultQueue.pop();
    }
    

    return 0;
}