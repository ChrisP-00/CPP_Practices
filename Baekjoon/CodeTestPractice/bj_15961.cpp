#include <iostream> 
#include <vector>
#include <algorithm>

#define fastCPP ios::sync_with_stdio(NULL), cin.tie(0);

using namespace std;

vector<int> sushi;
vector<int> hasEaten;

int main()
{
    fastCPP;

    int n, d, k, c;
    bool ateCoupon = false;

    cin >> n >> d >> k >> c; 

    // 테이블 위에 있는 초밥의 수 
    sushi.assign(n, 0);
    // 테이블 위에 있는 초밥의 종류
    hasEaten.assign(d + 1, 0);

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> sushi[idx];
    }

    int count = 0, answer = 0;

    // make window 7
    // 7 7 "9 7 30' 2" 7 9 25
    for(int idx = 0; idx < k; ++idx)
    {
        if(!hasEaten[sushi[idx]])
            count++;

        // 내가 먹음
        hasEaten[sushi[idx]]++;
    }

    if(!hasEaten[c])
    {
        answer = count + 1;
    }
    else
    {
        answer = count;
    }


    // move window 
    // [7 ('7 9 7] 30') 2 7 9 25
    // 새로운 위치의 윈도우의 가짓수를 계산
    // 이전 가짓수랑 비교
    // idx == start // end == start + k - 1
    for(int idx = 1; idx < n; ++idx)
    {   
        int end = (idx + k - 1) % n;

        if(!hasEaten[sushi[end]])
        {
            count++;
        }

        hasEaten[sushi[end]]++;

        hasEaten[sushi[idx - 1]]--;

        if(!hasEaten[sushi[idx - 1]])
        {
            count--;
        }


        // answer ? count 누가 더 많은가? 
        // 쿠폰이 포함되어있나? 
        // 쿠폰이 없으면 count +1, 있으면 걍 비교
        if(answer <= count)
        {
            if(!hasEaten[c])
            {
                answer = count + 1;
            }
            else
            {
                answer = count;
            }
        }
    }

    cout << answer; 

    return 0;
}