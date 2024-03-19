#include <iostream>

using namespace std; 


int n, m; 
int arr[9];
int isChecked[9];

void backTracking(int idx)
{
    if(idx == m)
    {
        for(int idx = 0; idx < m; idx++)
        {
            cout << arr[idx] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int num = 1; num <= n; num++)
    {
        if(isChecked[num]) continue;
        arr[idx] = num;
        isChecked[num] = 1;
        backTracking(idx + 1);
        isChecked[num] = 0;
    }
}



int main()
{
    cin >> n >> m;

    backTracking(0);

    return 0;
}