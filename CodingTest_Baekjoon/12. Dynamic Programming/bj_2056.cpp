#include<iostream>
#include<vector> 
#include<queue>

using namespace std; 

int main()
{
    int dp[n + 1] = {0};            
    int time [n + 1] = {0};           
    int precedingCount[n + 1] = {0};  
    vector<int> jobs [n + 1];   
    queue<int> waitingList;    
    
    int n, answer = 0;
    int curTime = 0;

    cin >> n;     

    for(int i = 1; i <= n; ++i)
    {
        int count; 

        cin >> time[i] >> count; 

        dp[i] = time[i];
        precedingCount[i] = count;

        // 선행 작업이 없는 작업을 큐에 넣음
        if(count == 0)
        {
            waitingList.push({i});      
            continue;
        }

        // 해당 선행 작업에 현 작업을 푸쉬백
        for(int j = 0; j < count; ++j)
        {
            int pre; 
            cin >> pre;
            jobs[pre].push_back(i);
        }
    }

    while(!waitingList.empty())
    {
        int cur = waitingList.front();
        waitingList.pop();
        
        // 현재 작업을 선행작업으로 하는 작업들의 실행 시간 계산
        for(int i = 0; i < jobs[cur].size(); ++i)
        {
            // next = 후속 작업의 인덱스
            int next = jobs[cur][i];

            // 후속 작업 시간 = 누적된 후속 작업 시간 vs 현재 작업 시간 + 후속 작업 시간
            dp[next] = max(dp[next], dp[cur] + time[next]);

            // 후속 작업의 선행 작업 갯수 빼기
            precedingCount[next] -= 1;

            // 선행 작업이 없을 경우 
            if(precedingCount[next] == 0)
            {
                waitingList.push(next);
            }
        }
    }

    for(int h : dp)
    {
        answer = answer < h ? h : answer;
    }

    cout << answer;

    return 0;
}