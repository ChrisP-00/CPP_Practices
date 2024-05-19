#include <iostream>
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int pSum[1025][1025];

int main()
{
    fastTime
    
    int n, m;
    cin >> n >> m; 

    for(int idxX = 1; idxX <= n; idxX++)
    {
        for(int idxY = 1; idxY <= n; idxY++)
        {
            int num = 0;
            cin >> num;

            pSum[idxX][idxY] = pSum[idxX-1][idxY] + pSum[idxX][idxY-1] - pSum[idxX-1][idxY-1] + num;
        }
    }

    while(m--)
    {
        int x1, x2, y1, y2; 
        // x 행 row, y열 column
        cin >> x1 >> y1 >> x2 >> y2;

        cout << pSum[x2][y2] - pSum[x1-1][y2] - pSum[x2][y1-1] + pSum[x1-1][y1-1] << '\n';
    }
}