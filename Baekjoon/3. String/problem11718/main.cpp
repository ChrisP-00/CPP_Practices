#include <iostream>
using namespace std; 

// cin == get input value before blank 
// getline == get input value of line 

int main()
{   
    string input; 

    while(true)
    {
        getline(cin, input);

        if(input ==  "")
        {
            break;
        }

        cout << input << endl;
    }
    return 0;
}