#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include <map> 
#include <tuple>

using namespace std;

queue<int> myQ;
vector<vector<int>> myGraph; 
map<int, pair<int, int>> myMap;
void BFS(int cur);
vector<int> answer(4, 0);

vector<int> solution(vector<vector<int>> edges) {


    int size = edges.size();
    
    myGraph.resize(size + 1);
    
    // map <key, value<in, out>>
    for(auto edge : edges)
    {
        myGraph[edge[0]].push_back(edge[1]);

        // out간선의 수
        if(myMap.find(edge[0]) == myMap.end())
        {
            myMap[edge[0]] = make_pair(0, 1);
        }
        else
        {
            myMap[edge[0]].second++;
        }

        // in간선의 수
        if(myMap.find(edge[1]) == myMap.end())
        {
            myMap[edge[1]] = make_pair(1, 0);
        }
        else
        {
            myMap[edge[1]].first++;
        }
    }

    for(int i = 1; i <= myMap.size(); ++i)
    {
        cout << "key: " << i << " first: " << myMap[i].first << " second: " << myMap[i].second << '\n';

        if(myMap[i].first == 0)
        {
            answer[0] = i;
        }
    }
    BFS(answer[0]);
    
    answer[1] = myGraph[answer[0]].size() - answer[2] - answer[3];
    

    cout << "총 노드의 수: " << myGraph[answer[0]].size() << '\n';
    cout << "시작 노드: " << answer[0] << " 도넛: " << answer[1] << " 스틱: " << answer[2] << " 8자: " << answer[3] << '\n';
    
    return answer;
}

void BFS(int startNode)
{
    vector<bool> visited(myGraph.size() + 1, false);
    
    queue<int> myQ; 
    myQ.push(startNode);

       while(!myQ.empty())
    {
        int cur = myQ.front();
        myQ.pop();
        
        visited[cur] = true;
           
           // first - in, second - out 
             // first - in, second - out 
        for(int node : myGraph[cur])
        {                    
            if(myMap[node].second == 0)
            {
                answer[2]++;
                continue;
            }
            
            else if(myMap[node].second == 2)
            {
                answer[3]++;
                continue;
            }
        
            if(!visited[node])
            {
                myQ.push(node);
                visited[node] = true;
            }
        }
    }
}



int main()
{
    vector<vector<int>> edges = 
    {
        {2, 3}, 
        {4, 3}, 
        {1, 1}, 
        {2, 1}
    };


    vector<vector<int>> edges2 = 
    {
       {4, 11}, 
       {1, 12}, 
       {8, 3}, 
       {12, 7}, 
       {4, 2}, 
       {7, 11}, 
       {4, 8}, 
       {9, 6}, 
       {10, 11}, 
       {6, 10}, 
       {3, 5}, 
       {11, 1}, 
       {5, 3}, 
       {11, 9}, 
       {3, 8},
       {4, 13},
       {13, 14},
       {14, 13}
    };

    

    vector<int> answer;

    solution(edges2);

    // for(auto value: answer)
    // {
    //     cout << "answer : " << value << '\n';
    // }

    return 0;
}