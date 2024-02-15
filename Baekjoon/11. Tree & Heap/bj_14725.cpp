#include <iostream> 
#include <string>

using namespace std;

struct node 
{
    string data; 
    node* left; 
    node* right;
}

int main()
{
    int n = 0;
    string food = "";

    cin >> n;

    while(n--)
    {
        cin >> food;
    }

    return 0;
}
