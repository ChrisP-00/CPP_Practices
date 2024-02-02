#include <iostream>
#include <stack>
#include <string> 
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std; 

int main()
{
    stack <int> shoulder;
    string result = "Nice";
    int count, num, out = 1;

    cin >> count; 

    while(count--)
    {
        cin >> num;

        if(out == num)
        {   
            out++;
        }
        else
        {
            shoulder.push(num);
        }

        while(!shoulder.empty())
        {
            if(out == shoulder.top())
            {
                shoulder.pop();
                out++;
            }
            else
            {
                break;
            }
        }
    }

    while(!shoulder.empty())
    {
        if(out == shoulder.top())
        {
            shoulder.pop();
            out++;
            continue;
        }
        else
        {
            result = "Sad";
            break;
        }
    }

    cout << result;

    return 0;
}