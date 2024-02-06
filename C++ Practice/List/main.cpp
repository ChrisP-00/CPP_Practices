#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> myList;
    list<int>::iterator iter = myList.begin();



    int input = 0;

    for(int idx = 0; idx < 3; idx++)
    {
        cin >> input;

        myList.push_back(input);
    }

    for(int idx = 0; idx < 4; idx++)
    {
        iter++;
        cout << "my iter is " << *iter << '\n';
    }

    cout << "my number is " << *iter;


    return 0;
}