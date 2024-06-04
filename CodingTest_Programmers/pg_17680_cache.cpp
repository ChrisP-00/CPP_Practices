#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> myCache; 
vector<string>::iterator iter;

void lowerCase(string& str)
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){
                  return tolower(c);
              });
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    myCache.assign(cacheSize, "");
    
    for_each(cities.begin(), cities.end(), lowerCase);
    
    for(int idx = 0; idx < cities.size(); ++idx)
    {
        if(cacheSize < 1)
        {
            answer += 5;
            continue;
        }
        
        
        iter = find(myCache.begin(), myCache.end(), cities[idx]);
        
        // 캐시에 있음
        if(iter != myCache.end())
        {
            myCache.erase(iter);
            myCache.push_back(cities[idx]);
            answer += 1;
        }
        // 캐시에 없음
        else
        {
            // 캐시 사이즈 여유로움
            if(myCache.size() < cacheSize)
            {
                myCache.push_back(cities[idx]);
            }
            // 여유롭지 않음
            else
            {
                myCache.erase(myCache.begin());
                myCache.push_back(cities[idx]);
            }
            answer += 5;
        }
    }
    
    
    return answer;
}