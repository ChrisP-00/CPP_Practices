#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long left = 1; 
    long long right = times.back() * n;
    long long mid = 0;
    long long count = 0;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        count = 0; 
        
        cout << "Left: " << left << " Right: " << right << " Mid: " << mid << '\n';

        for(int i = 0; i < times.size(); ++i)
        {
            count += mid / times[i];
            cout << "count: " << count << '\n';
        }
        
        if(count >= n)
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }

        answer = left;
    }
    
    return answer;
}


int main()
{
    int n = 6;
    vector<int> times = { 7, 10};

    cout << solution(n, times);


}