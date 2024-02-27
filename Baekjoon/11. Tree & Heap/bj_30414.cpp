#include <iostream>
#include <vector>

using namespace std;

struct myNode
{
    myNode* children [100001];

    int height;


    void InsertNode()
};


vector<myNode> myTree(100001);




int main()
{
    vector<int> mointainHeight ()
    int n, p, input1, input2 = 0;

    cin >> n >> p;

    for(int idx = 1; idx < n; idx++)
    {
        cin >> input1;
        myTree[idx].height = input1;
    }

    for(int idx = 1; idx < n; idx++)
    {
        cin >> input1;
        myTree[idx].height -= input1;
    }

    for(int idx = 0; idx < n - 1; idx++)
    {
        cin >> input1 >> input2;
        myTree[input1].children = 
    }




    return 0;
}