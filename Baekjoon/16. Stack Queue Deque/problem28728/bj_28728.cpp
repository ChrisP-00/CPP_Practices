#include <iostream>
#include <stack>
#define fastTime ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std; 

int main()
{
    fastTime;
    
    stack <int> myStack;
    int n, a, b = 0;

    cin >> n;

    while(n--)
    {
        cin >> a;

        switch(a)
        {
            case 1:
                cin >> b;
                myStack.push(b);
                break;

            case 2:
                if(myStack.empty())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    cout << myStack.top() << '\n';
                    myStack.pop();
                }
                break;
            case 3:
                cout << myStack.size() << '\n';
                break;
            case 4: 
                myStack.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
                break;
            case 5: 
                myStack.empty() ? cout << -1 << '\n' : cout << myStack.top() << '\n';
        }
    }

    return 0;
}
