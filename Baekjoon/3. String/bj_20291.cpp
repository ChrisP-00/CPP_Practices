#include <iostream> 
#include <string> 
#include <map>

#define fastCPP ios::sync_with_stdio(NULL), cin.tie(0);

using namespace std; 


map <string, int> myMap;
map <string, int> ::iterator iter;


int main()
{
    fastCPP;

    int n; 
    cin >> n; 

    while(n--)
    {
        string input; 
        cin >> input; 
        
        int idx = input.find('.');

        myMap[input.substr(idx + 1, input.length())] += 1;
    }

    iter = myMap.begin();
    while(iter != myMap.end())
    {
        cout << iter->first << ' ' << iter->second << '\n';
        iter++;
    }

    return 0;
}