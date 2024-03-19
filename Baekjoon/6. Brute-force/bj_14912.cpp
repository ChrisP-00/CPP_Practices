#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, count = 0;
    char d;

    cin >> n >> d; 

    for(int num = 1; num <= n; num++)
    {
        string str = to_string(num);

        for(int idx = 0; idx < str.length(); idx++)
        {
            if(str[idx] == d) count++;
        }
    }

    cout << count;

    return 0;
}