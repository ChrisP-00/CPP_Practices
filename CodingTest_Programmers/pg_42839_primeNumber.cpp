#include <string>
#include <vector>
#include <set> 
#include <algorithm> 
#include <cmath>

using namespace std;

set<int> mySet;
vector<bool> isVisited(7);

bool isPrime(int target)
{
    if(target <= 1) return false;
    for(int n = 2; n <= sqrt(target); ++n)
    {
        if(target % n == 0)
            return false;
    }
    return true;
}

void DFS(string& numbers, string target)
{
    if(!target.empty())
    {
        int temp = stoi(target);
        if(isPrime(temp))
        {
            mySet.insert(temp);
        }
    }
    
    for(int idx = 0; idx < numbers.length(); ++idx)
    {
        if(isVisited[idx]) continue;
        
        isVisited[idx] = true;
        DFS(numbers, target + numbers[idx]);
        isVisited[idx] = false;
    }
}


int solution(string numbers) 
{
    DFS(numbers, "");
    
    return mySet.size();
}