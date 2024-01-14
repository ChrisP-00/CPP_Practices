#include <iostream>
using namespace std;

int main()
{
    int t, r;
    string s;

    cin >> t; 

    for(int i = 0; i < t; i++)
    {
        cin >> r >> s; 

        for(int j = 0; j < s.length(); j++)
        {
            for(int l = 0; l < r; l++)
            {
                cout << s[j];
            }
        }
        cout << endl;
    }


    return 0;
}