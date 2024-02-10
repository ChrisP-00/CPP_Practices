#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int idx; 
    int size; 
    
    int next;
    int prev;
};

int main()
{
    vector<node> myList (600000);
    deque<int> myDeque;
    const int maxValue = 500002;

    int microbeIdx, microbeSize, totalSize, origin = 0;
    int tempNext = maxValue, tempPrev = maxValue;

    cin >> microbeIdx;

    for(int idx = 1; idx <= microbeIdx; idx++)
    {
        cin >> microbeSize;

        totalSize += microbeSize;

        myDeque.push_back(microbeSize);

        myList[microbeSize].idx = idx;
        myList[microbeSize].size = microbeSize;
        myList[microbeSize].prev = tempPrev;
        myList[microbeSize].next = tempNext;

        myList[tempPrev].next = microbeSize;

        tempPrev = microbeSize;
    }

    while(!myDeque.empty())
    {
        int sum = 0;
        microbeIdx = myDeque.front();

        microbeSize = myList[microbeIdx].size;
        tempNext = myList[microbeIdx].next;
        tempPrev = myList[microbeIdx].prev;

        cout << "현재 미생물은 " << microbeSize << '\n';

        if(tempPrev <= microbeSize)
        {
            sum += tempPrev;
            myDeque.pop_back();

            myList[microbeIdx].prev = myList[tempPrev].prev;
            myList[myList[tempPrev].prev].next = microbeIdx;
            cout << "이전 미생물 냠냠 " << tempPrev << '\n';
        }
        if(tempNext <= microbeSize)
        {
            sum += tempNext;

            myDeque.push_back(myDeque.front());
            myDeque.pop_front();

            myDeque.pop_front();

            myList[microbeIdx].next = myList[tempNext].next;
            myList[myList[tempNext].next].prev = microbeIdx;

            cout << "다음 미생물 냠냠 " << tempNext << '\n';
        }
        else
        {
            myDeque.push_back(myDeque.front());
            myDeque.pop_front();
        }

        myList[microbeIdx].size += sum;
        origin = myList[microbeIdx].idx;
    }

    cout << totalSize << '\n';
    cout << origin;

    return 0;
}