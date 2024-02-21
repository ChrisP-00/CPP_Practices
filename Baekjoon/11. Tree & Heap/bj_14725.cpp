#include <iostream> 
#include <string>
#include <queue>

using namespace std;

struct node 
{
    string data; 
    node* left; 
    node* right;
};

node* intsertNode(node* rootNode, string data)
{
    priority_queue<node> myQueue;

    node* newNode = new node;
    newNode.data = data;

    myQueue.push(newNode);

    while(!myQueue.empty())
    {
        node* tempNode = myQueue.front();
        myQueue.pop();

        if(rootNode->left.data < tempNode->data)
        {




            
        }


    }

    return rootNode;
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
