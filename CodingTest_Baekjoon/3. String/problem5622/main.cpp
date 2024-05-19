#include <iostream>

// 'A' == 65 
// 1-6, 8 == 3 letters 
// 7, 9 has 4 letters 
// PQRS == 80 ~ 83, WXYZ == 87 ~ 90

using namespace std; 

int main()
{                 // ABC      DEF      GHI      JKL      MNO      PRQS        TUV       WXYZ      
    int dial [26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    string n;
    int time = 0;

    cin >> n;

    for(int i = 0; i < n.length(); i++)
    {
        time += dial[n[i] - 'A'];
    }
    
    cout << time;

    return 0;
}