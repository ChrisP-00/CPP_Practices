#include <iostream> 
#include <vector> 

using namespace std; 

vector<int> sushi;
vector<int> hasEaten (3001);


int main()
{
    // n == 접시의 수, d == 초밥 종류, k == 연속 접시 수, c == 쿠폰
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    sushi.assign(n, 0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> sushi[idx];
    }

    int cnt = 0, ans = 0; 

    // 처음부터 연속된 접시의 갯수만큼 먹을 때의 스시 종류 카운트
    // [sliding window]를 만든다. 
    // k크기만큼을 한번만 만들고 이후엔 이동하면서 더하면 되니 반복문 안에 넣을 필요 없듬
    for(int idx = 0; idx < k; idx++)
    {
        // 아직 안먹은거라면, 쿠폰으로 주는게 아니라면, count 추가
        if(!hasEaten[sushi[idx]])
        {
            cnt++;
        }
        // 먹었던 스시 종류의 먹은 횟수를 증가
        hasEaten[sushi[idx]]++;
    } 

    if(hasEaten[c] == 0) 
    {
        ans = cnt + 1;
    }
    else 
    {
        ans = cnt;
    }

    int en = 0;

    // 만들어둔 범위를 옮겨가면서 합을 계산
    for(int st = 1; st < n; st++)
    {
        // en이 전체 접시의 수를 넘어가면 다시 0부터 확인해야하기 때문에 
        // en은 st의 위치에서 k만큼을 더한 위치에서 n의 나눈 나머지 값을 가짐
        en = (st + k - 1) % n; 

        // 오른쪽으로 옮겼을 때 처음 먹는 종류이다
        if(hasEaten[sushi[en]] == 0)
        {
            cnt++;
        }
        // 먹은 초밥 종류의 누적값을 올림 
        hasEaten[sushi[en]]++;
        
        // st가 옮김에 따라 먹은 초밥 종류의 누적값을 내림
        hasEaten[sushi[st - 1]]--;
        // 누적된 먹은 초밥 종류가 0이라면 전체 합에서 값을 내림
        if(hasEaten[sushi[st - 1]] == 0) 
        {
            cnt--;
        }

        if(ans <= cnt)
        {
            if(hasEaten[c] == 0) 
                ans = cnt + 1;
            else 
            {
                ans = cnt;
            }
        }

        cout << "st: " << st << " ans: " << ans << '\n';
    }
    
    cout << ans;

    return 0;
}