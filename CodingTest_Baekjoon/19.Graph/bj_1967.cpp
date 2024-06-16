#include<iostream>
#include<vector> 

using namespace std; 

vector<pair<int, int>> myTree[10001];
vector<bool> visited;
int maxDistance, farthestNode = 0;

void DFS(int cur, int sum)
{
    if(sum > maxDistance)
    {
        maxDistance = sum; 
        farthestNode = cur;
    }

    visited[cur] = true;

    for(int idx = 0; idx < myTree[cur].size(); ++idx)
    {
        if(visited[myTree[cur][idx].first]) continue;

        DFS(myTree[cur][idx].first, sum + myTree[cur][idx].second);
    }
}

int main()
{
    int n; 
    cin >> n;

    visited.resize(n + 1, false);

    for(int idx = 0; idx < n - 1; ++idx)
    {
        int a, b, c; 

        cin >> a >> b >> c;

        myTree[a].push_back({b, c});
        myTree[b].push_back({a, c});
    }

    DFS(1, 0);

    visited.assign(n + 1, false);
    maxDistance = 0;

    DFS(farthestNode, 0);

    cout << maxDistance;

    return 0;
}