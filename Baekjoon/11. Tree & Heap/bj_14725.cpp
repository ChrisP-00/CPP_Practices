#include <iostream> 
#include <string>

using namespace std;

struct node 
{
    string data; 
    node* left; 
    node* right;
};

node* intsertNode(node* rootNode, string data)
{
    node* newNode = new node;
    newNode.data = data;

    if(rootNode->left == NULL)
    {
        rootNode.left = newNode;
    }
    else
    {
        
    }





    return newNode;
}




int main()
{
    int n, k = 0;
    string food = "";
    const string treeLevel = "--";

    cin >> n;

    while(n--)
    {
        while(k--)
        {
            cin >> food;
        }
    }

    return 0;
}
