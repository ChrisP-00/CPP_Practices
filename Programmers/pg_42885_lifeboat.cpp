#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class lifeboat
{
    private: 
    vector<int> people;
    int limit;

    public : 
    lifeboat(vector<int> people, int limit)
    {
        this->people = people;
        this->limit = limit;
        sort(this->people.begin(), this->people.end());
    }
    int answer = 0;
    int calculateBoat();
};

int lifeboat::calculateBoat()
{
    int head = 0;
    int tail = people.size() - 1;

    while(head <= tail)
    {
        if(people[head] + people[tail] <= limit)
        {
            head++;
            tail--;
        }
        else
        {
            tail--;
        }

        answer++;
    }

    return answer;
}


int solution(vector<int> people, int limit) {
    lifeboat myLifeboat(people, limit);
    
    int answer = myLifeboat.calculateBoat();
    return answer;
}

int main()
{
    vector<int> people = {40, 40, 40};
    int limit = 100;

    cout << solution(people, limit);

    return 0;
}