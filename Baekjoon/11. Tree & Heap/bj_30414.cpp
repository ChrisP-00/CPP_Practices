#include <iostream>
#include <vector>

using namespace std;

struct myNode
{
    vector<int> children;
    int height;

    myNode() : children(100001), height(0) {}


    void printData(int root)
    {
        if(root == 0)
        {
            return;
        }

        cout << height << '\n';

        printData(children[root]);
    }
};


vector<myNode> myTree (100001);




int main()
{
    int n, p, input1, input2 = 0;

    cin >> n >> p;

    for(int idx = 1; idx < n + 1; idx++)
    {
        cin >> input1;
        myTree[idx].height = input1;
    }

    for(int idx = 1; idx < n + 1; idx++)
    {
        cin >> input1;
        myTree[idx].height -= input1;
    }

    for(int idx = 1; idx < n; idx++)
    {
        cin >> input1 >> input2;

        myTree[input1].children.push_back(input2);
        myTree[input2].children.push_back(input1);
    }

    


    return 0;
}