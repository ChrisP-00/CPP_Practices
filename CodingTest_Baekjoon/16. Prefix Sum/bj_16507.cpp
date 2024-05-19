#include <iostream>
#include <vector>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

vector<vector<int>> pSum;

int main()
{
    fastTime
    
    int r, c ,q;
    cin >> r >> c >> q; 

    pSum.assign(r+1, vector<int>(c+1,0));

    for(int idxY = 1; idxY <= r; idxY++)
    {
        for(int idxX = 1; idxX <= c; idxX++)
        {
            int num = 0;
            cin >> num;

            pSum[idxY][idxX] = pSum[idxY-1][idxX] + pSum[idxY][idxX-1] - pSum[idxY-1][idxX-1] + num;
        }
    }

    while(q--)
    {
        // r == row, c == column
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int result = pSum[r2][c2] - pSum[r2][c1-1] - pSum[r1-1][c2] + pSum[r1-1][c1-1];
        int divide = (r2 - r1 + 1) * (c2 - c1 + 1);

        cout << result / divide << '\n';
    }
}