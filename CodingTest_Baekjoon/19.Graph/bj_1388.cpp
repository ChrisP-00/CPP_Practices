#include<iostream>
#include<vector> 

using namespace std; 

int n , m, cnt = 0;

vector<vector<char>> carpet;
vector<vector<bool>> visited;

void CheckHorizontal(int y, int x)
{
    if(x >= m) return;
    if(visited[y][x] || carpet[y][x] != '-') return;

    visited[y][x] = true;
    return CheckHorizontal(y, x + 1);
}

void CheckVertical(int y, int x)
{
    if(y >= n) return;
    if(carpet[y][x] != '|' || visited[y][x]) return;
    
    visited[y][x] = true;
    return CheckVertical(y + 1, x);
}

int main()
{
    char c;

    cin >> n >> m;
    
    visited.resize(n, vector<bool>(m, false));
    carpet.resize(n, vector<char>(m, ' '));
    
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
           cin >> c;
           carpet[y][x] = c; 
        }
    }
    
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            if(visited[y][x]) continue;

            if(carpet[y][x] == '-')
            {
                CheckHorizontal(y, x);
            }
            else
            {
                CheckVertical(y, x);
            }
            
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}