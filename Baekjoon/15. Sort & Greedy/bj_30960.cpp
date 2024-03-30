#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std; 

vector<int> people;
vector<int> group;

int main()
{
    int n, m, result = 0;

    cin >> n;

    m = n / 2;

    people.assign(n,0);
    group.assign(m,0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> people[idx];
    }

    sort(people.begin(), people.end());

    for(int idx = 0; idx < n-1; idx++)
    {
        group[idx] = people[idx+1] - people[idx];
        cout << "idx" << idx << " shy: " << people[idx+1] - people[idx] << '\n';
    }

    sort(group.begin(), group.end());

    for(int idx = 1; idx < m; idx++)
    {
        cout << "group: " << group[idx] << '\n';
        result += group[idx];
    }

    cout << result;

    return 0;
} 