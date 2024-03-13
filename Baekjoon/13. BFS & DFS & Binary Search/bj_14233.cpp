#include <iostream>
#include <algorithm>

#define fastLapTime 1000000


using namespace std; 

int testCase, players, track, boosterLimit, speed; 

int main()
{
    cin >> testCase;

    while(testCase--)
    {
        cin >> players >> track >> boosterLimit;
        
        int fastTime = fastLapTime;

        for(int idx = 0; idx < players; idx++)
        {
            cin >> speed;
        
            int lapTime = track / speed;

            fastTime = lapTime < fastTime ? lapTime : fastTime;
        }

        

    }




    return 0;
}