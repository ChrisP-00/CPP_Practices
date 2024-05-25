#include <string>
#include <vector>

using namespace std; 

int answer = 0;
vector<bool> isChecked (8, false);

void DFS(int depth, int remain, vector<vector<int>>& dungeons)
{  
    answer = depth > answer ? depth : answer;
  
    for(int idx = 0; idx < dungeons.size(); ++idx)
    {
        if(isChecked[idx]) continue;
        
        if(remain < dungeons[idx][0]) continue;
        
        isChecked[idx] = true;
        
        DFS(depth + 1, remain - dungeons[idx][1], dungeons);
        
        isChecked[idx] = false;
    }
}


int solution(int k, vector<vector<int>> dungeons) {

    DFS(0, k, dungeons);
    
    return answer;
}

int main()
{
    vector<vector<int>> dungeons1 = {{80,20}, {50,40}, {30,10}};
    vector<vector<int>> dungeons2 = {{10,10}, {20,10}};
    vector<vector<int>> dungeons3 = {{100, 1}, {99, 1}, {99, 1}, {99, 1}};

    int k1 = 80;
    int k2 = 20;
    int k3 = 100;

    cout << solution(k2, dungeons2);

    return 0;
}