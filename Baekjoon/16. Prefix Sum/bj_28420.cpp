#include <iostream> 
#include <vector> 
#include <queue>

using namespace std; 

vector<vector<int>> map;
vector<int> carSize(3);
priority_queue<int> myPQ;

int prefixSum(int y, int x, int[3] arr, int iY, int iX)
{
    if(iY > 3 || iX > 3) return map[y][x];

    return map[y][x] - map[y - arr[iY]][x] - map[y][x - arr[iX]] + prefixSum(y - arr[iY], x - arr[iX], arr, iY++, iX++); 
}





int main()
{
    // 세로, 가로
    int n, m;
    int a,b,c;

    cin >> n >> m;

    map.assign(n+1, vector<int>(m+1,0));

    cin >> carSize[0] >> carSize[1] >> carSize[2];

    for(int idxY = 1; idxY <= n; idxY++)
    {
        for(int idxX = 1; idxX <= m; idxX++)
        {
            int num;
            cin >> num;
            map[idxY][idxX] = map[idxY][idxX-1] + map[idxY-1][idxX] - map[idxY-1][idxX-1] + num;
        }
    }

    for(int idxY = 0; idxY <= n; idxY++)
    {
        for(int idxX = 0; idxX <= m; idxX++)
        {
            cout << "Y " << idxY << " X " << idxX << '\n';

            //    c  b
            // [+][+][] a 
            if((idxX + c + b) <= m && (idxY + a) <= n)
            {
                int[3]arr = {}
                myPQ.push(prefixSum(idxY + a, idxX + c + b));
            }
            //   c   a
            // [+][+]   
            //       [] b
            if((idxX + c + a) <= m && (idxY + a + b) <= n)
            {
                myPQ.push();

            }
            // b  a
            // []
            //   [+] c
            //   [+] 
            if((idxX + b + a) <= m && (idxY + a + c) <= n)
            {
                myPQ.push();
            }
        }
    }

    cout << abs(myPQ.top());

    return 0;
}