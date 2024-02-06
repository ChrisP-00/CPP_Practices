#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    list<int> myList;
    list<int>::iterator iter = myList.begin();

    string command = "";
    int stationNumber, station, constructionCount = 0;

    cin >> stationNumber >> constructionCount;

    while(stationNumber--)
    {
        cin >> station;

        myList.push_back(station);
    }

    while(constructionCount--)
    {
        cin >> command;
        cin >> stationNumber;

        while(*iter != stationNumber)
        {
            if(iter == myList.end())
            {
                iter = myList.begin();
            }
            else
            {
                iter++;
            }
        }
        
        if(command == "BN") // print next station number and add new station front
        {
            cin >> station;

            if(*iter == myList.back())
            {
                iter = myList.begin();
            }
            else
            {
                ++iter;
            }

            cout << *iter << '\n';
            iter = myList.insert(iter, station);

        }
        else if(command == "BP") // print previous station number and add new station after 
        {
            cin >> station;

            if(*iter == myList.front())
            {
                iter = myList.end();
            }
            else
            {
                --iter;
            }

            cout << *iter << '\n';
            ++iter;
            iter = myList.insert(iter, station);
        }
        else if(command == "CP") // delete next station and print the deleted station number 
        {
            if(*iter == myList.front())
            {
                iter = myList.end();
            }
            else
            {
                --iter;
            }

            cout << *iter << '\n';
            iter = myList.erase(iter);
        }
        else if(command == "CN") // delete previous station and print the deleted station number 
        {
            if(*iter == myList.back())
            {
                iter = myList.begin();
            }
            else
            {
                ++iter;
            }

            cout << *iter << '\n';
            iter = myList.erase(iter);
        }
    }

    myList.clear();
    return 0;
}
