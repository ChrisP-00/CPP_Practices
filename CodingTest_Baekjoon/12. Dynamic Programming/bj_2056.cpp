#include<iostream>
#include<vector> 
#include<queue>

using namespace std; 


int main()
{
    int n, answer = 0;

    cin >> n;     

    int dp[n + 1] = {0};     
    
    for(int i = 1; i <= n; ++i)
    {
        int cur, count, maxValue = 0;
        cin >> cur >> count;

        for(int j = 0; j < count; ++j)
        {
            int preP;
            cin >> preP; 

            maxValue = maxValue > dp[preP] ? maxValue : dp[preP];
        }

        dp[i] = maxValue + cur;
        answer = answer > dp[i] ? answer : dp[i];

        cout << "curMax: " << maxValue << "  dp" << i << " : " << dp[i] << '\n';
    }

    cout << answer;

    return 0;
}