#include <iostream>
#include <string>
using namespace std; 

// 'A' == 65

int main()
{
    string n;
    int b, result (0); 


    cin >> n >> b;

    int temp = 1; 

    for(int i = n.length()-1; i >= 0; i--)
    {
        int num; 

        if(n[i] >= '0' && n[i] <= '9')
        {
            num = n[i] - '0';
        }
        else 
        {
            num = n[i] - 'A' + 10;                    
        }

        num *= temp;
        result += num;
        temp *= b;
    }
    
    cout << result;

    return 0;
}