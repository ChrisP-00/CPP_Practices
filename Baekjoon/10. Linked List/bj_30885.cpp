#include <iostream>
#include <queue>

using namespace std; 

struct microbe
{
    int prev;
    int next;
};

int main()
{
    vector<microbe> myMicrobe (5000001);
    queue<pair<int,int> > myMicrobeQueue;
    int howMany, microbeSize = 0;
    int tempPrev = 0;
    int tempNext = 0; 
    int totalSize = 0;

    cin >> howMany;

    for(int idx = 1; idx <= howMany; idx++)
    {
        cin >> microbeSize;

        totalSize += microbeSize;

        // first == index, second size 
        myMicrobeQueue.push(make_pair(idx, microbeSize));

        myMicrobe[microbeSize].prev = tempPrev;
        myMicrobe[microbeSize].next = 0;

        myMicrobe[tempPrev].next = microbeSize;

        tempPrev = microbeSize;
    }


    while(myMicrobeQueue.size() != 1)
    {   
        // index
        howMany = myMicrobeQueue.front().first;
        // microbe size 
        microbeSize = myMicrobeQueue.front().second;

        tempPrev = myMicrobe[microbeSize].prev;
        tempNext = myMicrobe[microbeSize].next;

        cout << microbeSize <<" 크기의 미생물 위치는 " << howMany << '\n';

        if(tempPrev == 0)
        {
            // if prev microbe does not exist 
            if(microbeSize > tempNext)
            {
                cout << "전이 없음 다음 껄 먹었다 " << '\n';
               
                microbeSize += tempNext;

                // pop next microbe from queue
                if(myMicrobeQueue.size() > 1)
                {
                    // push microbe back to queue
                    myMicrobeQueue.push(make_pair(howMany, microbeSize));
                    myMicrobeQueue.pop();

                    cout << "잡아 먹고 다음 미생물은? " << myMicrobeQueue.front().second << '\n';
                    myMicrobe[myMicrobeQueue.front().second].prev = 0;
                }
            }
        }
        else if(tempNext == 0)
        {
            // if next microbe does not exist 
            if(microbeSize > tempPrev)
            {
                cout << "다음이 없음 이전 껄 먹었다 " << '\n';
                
                microbeSize += tempPrev;

                // pop next microbe from queue
                if(myMicrobeQueue.size() > 1)
                {
                    // push microbe back to queue
                    myMicrobeQueue.push(make_pair(howMany, microbeSize));
                    cout << "잡아 먹고 다음 미생물은? " << myMicrobe[microbeSize].next << '\n';
                    myMicrobe[myMicrobe[microbeSize].next].prev = 0;
                }
            }
        }

        // both next and prev exist 
        else if(tempPrev != 0 && tempNext != 0)
        {
            if(tempNext > tempPrev && microbeSize > tempPrev)
            {
                cout << "둘중에 이전 껄 먹었다 " << '\n';
                
                microbeSize += tempPrev;

                // pop next microbe from queue
                if(myMicrobeQueue.size() > 1)
                {
                    // push microbe back to queue
                    myMicrobeQueue.push(make_pair(howMany, microbeSize));
                    cout << "잡아 먹고 다음 미생물은? " << myMicrobe[microbeSize].next << '\n';
                    myMicrobe[myMicrobe[microbeSize].next].prev = 0;
                }
            }
            else if(tempPrev > tempNext && microbeSize > tempNext)   
            {
                cout << "둘중에 다음 껄 먹었다 " << '\n';

                // pop next microbe from queue
                if(myMicrobeQueue.size() > 1)
                {
                    // push microbe back to queue
                    myMicrobeQueue.push(make_pair(howMany, microbeSize));
                    myMicrobeQueue.pop();
                    cout << "잡아 먹고 다음 미생물은? " << myMicrobeQueue.front().second << '\n';
                    myMicrobe[myMicrobeQueue.front().second].prev = 0;
                }
            }
        }
        else
        {
            // push microbe back to queue
            myMicrobeQueue.push(myMicrobeQueue.front());
            myMicrobeQueue.pop();
        }
        
        cout << "지금 미생물 위치는? " << howMany << '\n';
    }

    cout << totalSize << '\n';
    cout << howMany;

    return 0;
}