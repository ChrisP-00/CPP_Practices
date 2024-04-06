#include <iostream> 
#include <vector> 
#define fastCPP ios::sync_with_stdio(NULL), cin.tie(0);

using namespace std; 

vector<bool> isChecked(988, true);

bool isValidNum(int nums);

int main()
{
    fastCPP;

    int n, ans = 0; 

    cin >> n;

    for(int idx = 123; idx < 988; ++idx)
    {
        isChecked[idx] = isValidNum(idx);
    }


    while(n--)
    {
        int nums, str, ball; 
        cin >> nums >> str >> ball;
        
        string input = to_string(nums);

        for(int idx = 123; idx < 988; ++idx)
        {
            if(!isChecked[idx]) continue;

            string checkNum = to_string(idx);

            int chkstr = 0, chkball = 0;

            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    if(input[i] == checkNum[j])
                    {
                        if(i == j)
                            chkstr++;
                        else
                            chkball++;
                    }
                }
            }

            if(!(chkstr == str && chkball == ball))
                isChecked[idx] = false;
        }
    }

    for(int idx = 123; idx < 988; ++idx)
    {
        if(isChecked[idx])
            ans++;
    }

    cout << ans;

    return 0;
}


bool isValidNum(int nums)
{
    int hundreds = nums / 100;
    nums %= 100;
    int tens = nums / 10;
    int ones = nums % 10;

    if(hundreds == tens || tens == ones || ones == hundreds)
        return false; 

    if(hundreds == 0 || tens == 0 || ones == 0)
        return false;
    
    return true;
}
