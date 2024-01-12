#include <iostream>
#include <string>
using namespace std;

/*
int WordChecker (string n);

int main()
{
    int words;
    string input; 
    int count = 0;

    cin >> words;

   for(int i = 0; i < words; i++)
   {
        cin >> input;
        count += WordChecker(input);
   }

    cout << count;

    return 0;
}

int WordChecker(string n)
{
    // reset array to false
    bool arr [26] = {false};
    arr[0] = true;

    int length = n.length();

    for(int i = 1; i < length; i++)
    {
        // are letters continuous?  
        if((i > 0) && (n[i] == n[i-1]))
        {
            arr[n[i]-'a'] = true;
            continue;
        }

        // has been checked? 
        if(arr[n[i]-'a'] == true)
        {
            return 0; 
        }
  
        arr[n[i]-'a'] = true;
    }

    return 1;
}
*/

int main() 
{
    int n; 
    string word;
    int count = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> word;
        int length = word.length();
        
        if(length < 3)
        {
            continue;
        }

        else
        {
            for(int j = 0; j < length-1; j++)
            {
                if(word[j] != word[j+1])
                {
                    if(word.find(word[j], j + 2) != string::npos)
                    {
                        count++;
                        break;
                    }
                }

            }
        }

    }
    cout << n - count;
}
