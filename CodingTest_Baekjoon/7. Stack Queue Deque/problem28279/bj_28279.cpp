#include <iostream>
#include <deque>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    deque <int> myDeque;
    int commandCount, num = 0; 

    cin >> commandCount;

    while(commandCount--)
    {
        cin >> num;

        switch(num)
        {
            case 1: 
                cin >> num;
                myDeque.push_front(num);
                break;
            case 2:
                cin >> num;
                myDeque.push_back(num);
                break;
            case 3:
                if(myDeque.empty())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    cout << myDeque.front() << '\n';
                    myDeque.pop_front();
                } 
                break;

            case 4:
                if(myDeque.empty())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    cout << myDeque.back() << '\n';
                    myDeque.pop_back();
                }
                break;
            case 5:
                cout << myDeque.size() << '\n';
                break;
            case 6:
                myDeque.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
                break;
            case 7:
                myDeque.empty() ? cout << -1 << '\n' : cout << myDeque.front() << '\n';
                break;
            case 8:
                myDeque.empty() ? cout << -1 << '\n' : cout << myDeque.back() << '\n';
                break;
        }
    }
    return 0;
}