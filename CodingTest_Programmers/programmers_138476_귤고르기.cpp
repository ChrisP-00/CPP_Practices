#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std; 

class class_tangerineCollector 
{
    private : 
    int answer = 0; 
    int k;
    vector<int> tangerine;

    public : 
    void collectingtangerine();
    int getAnswer();

    class_tangerineCollector(int k, vector<int> tangerine)
    {
        this->k = k;
        this->tangerine = tangerine;
    }
};

int class_tangerineCollector::getAnswer()
{
    return answer;
}

void class_tangerineCollector::collectingtangerine()
{
    map<int, int> myMap; 
    int box = 0;

    for(auto i : tangerine)
    {
        if(myMap.find(i) == myMap.end())
        {
            myMap[i] = 1;
        }
        else
        {
            myMap[i]++;
        }
    }

    deque<pair<int,int>> myPair(myMap.begin(), myMap.end());

    sort(myPair.begin(), myPair.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second;
    });

    while(box < k)
    {
        box += myPair[0].second;
        myPair.pop_front();
        answer++;
    }
}

int solution(int k, vector<int> tangerine) {
    
    class_tangerineCollector myCollector(k, tangerine);
    myCollector.collectingtangerine();
    
    return myCollector.getAnswer();
}

int main()
{
    int k = 4;
    vector<int> tangerine = {1, 3, 2, 5, 4, 5, 2, 3};
    cout << boolalpha << solution(k, tangerine);
}