#include <iostream>
#include <string>
using namespace std;

// a ~ z == 97 ~ 122 
// A ~ Z == 65 ~ 90

int main()
{
    int arr[26] = {0};
    string word;

    char letter; 
    int max = 0; 

    cin >> word;

    int size = word.length();

    for(int i = 0; i < size; ++i)
    {
        // if i-th letter is lower case, -'a'(97), upper case is -'A'(65)
        // to get arr index as 0 = a(A), 1 = b(B) in arr 
        if(word[i] >= 97) 
        {
            arr[word[i]-97]++;
        }
        else
        {
            arr[word[i]-65]++;
        }
    }

    for(int i = 0; i < 26; ++i)
    {
        if(arr[i] == max)
        {
            letter = '?';
        }
  
        else if(arr[i] > max)
        {
            max = arr[i];
            letter = i + 65;
        }
    }

    cout << letter;

    return 0;
}