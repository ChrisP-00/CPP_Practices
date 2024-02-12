#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int idx; 
    int size; 
    int nextIdx;
    int prevIdx;
};

int main()
{
    vector<node> myList (500003);
    deque<int> myDeque;
    const int maxValue = 500002;

    int microbeIdx, tempSize, tempPrevSize, tempNextSize, tempIdx = 0;
    int tempNextIdx = maxValue, tempPrevIdx = maxValue;
    int totalSize = 0;


    cout << totalSize << " 총 미생물 \n";

    cin >> microbeIdx;

    for(int idx = 1; idx <= microbeIdx; idx++)
    {
        cin >> tempSize;

        totalSize += tempSize;

        myDeque.push_back(idx);

        myList[idx].idx = idx;
        myList[idx].size = tempSize;
        myList[idx].prevIdx = tempPrevIdx;
        myList[idx].nextIdx = tempNextIdx;

        myList[tempPrevIdx].nextIdx = idx;

        cout << tempPrevIdx << "의 다음은 " << myList[tempPrevIdx].nextIdx << '\n';

        tempPrevIdx = idx;
    }
    
    // connect head to tail 
    myList[tempPrevIdx].nextIdx = maxValue;
    myList[maxValue].size = maxValue;

    cout << tempPrevIdx << "의 다음은 " << myList[tempPrevIdx].nextIdx << '\n';


    for(int idx = 1; idx <= microbeIdx; idx++)
    {
        cout << "=== 덱의 인덱스 " << myDeque.front() << " ===\n";

        myDeque.push_back(myDeque.front());
        myDeque.pop_front();

        cout << idx << "번째 미생물은 " << myList[idx].size << '\n';
        cout << "이전은 " << myList[idx].prevIdx << " 다음은 " << myList[idx].nextIdx << '\n';
    }


    while(myDeque.size() != 1)
    {
        int sum = 0;

        microbeIdx = myDeque.front();
        myDeque.pop_front();

        tempIdx = myList[microbeIdx].idx;
        tempSize = myList[microbeIdx].size;
        tempNextIdx = myList[microbeIdx].nextIdx;
        tempPrevIdx = myList[microbeIdx].prevIdx;

        tempPrevSize = myList[tempPrevIdx].size;
        tempNextSize = myList[tempNextIdx].size;

        cout << "============================\n";
        cout << "현재 인덱스는 " << microbeIdx << '\n';
        cout << "현재 미생물 크기는 " << tempSize << '\n';

        if(tempPrevSize <= tempSize)
        {
            sum += tempPrevSize;
            myDeque.pop_back();

            cout << "이전 미생물 냠냠 " << tempPrevSize << " 지금 사이즈는 " << tempSize + sum << '\n';

            myList[myList[tempPrevIdx].prevIdx].nextIdx = microbeIdx;
            myList[microbeIdx].prevIdx = myList[tempPrevIdx].prevIdx;

            myList[microbeIdx].size = tempSize + sum;

            cout << microbeIdx << " 의 이전 미생물은 " <<  myList[microbeIdx].prevIdx << "/ 다음 미생물은 " << myList[microbeIdx].nextIdx << '\n';

        }
        if(tempNextSize <= tempSize)
        {
            sum += tempNextSize;

            myDeque.pop_front();    // pop nextIdx node 

            cout << "다음 미생물 냠냠 " << tempNextSize << " 지금 사이즈는 " << tempSize + sum << '\n';

            myList[tempPrevIdx].nextIdx = microbeIdx;
            myList[myList[tempNextIdx].nextIdx].prevIdx = microbeIdx;
            myList[microbeIdx].nextIdx = myList[tempNextIdx].nextIdx;

            myList[microbeIdx].size = tempSize + sum;

            cout << microbeIdx << " 의 이전 미생물은 " <<  myList[microbeIdx].prevIdx << "/ 다음 미생물은 " << myList[microbeIdx].nextIdx << '\n';
        }
        else
        {
            cout << "오우 먹을게 없어 다음으로..'\n";
        }

        myDeque.push_back(microbeIdx);

        cout << myList[microbeIdx].idx << "위치 현재 미생물 크기는 " << myList[microbeIdx].size << '\n';
        cout << "이전 미생물은 " <<  myList[microbeIdx].prevIdx << " 다음 미생물은 " << myList[microbeIdx].nextIdx << '\n';
        cout << "다음 미생물의 이전 인덱스는 " << myList[myList[microbeIdx].nextIdx].prevIdx << " // 사이즈는 " << myList[myList[myList[microbeIdx].nextIdx].prevIdx].size << '\n'; 
    }

    cout << "============================\n";
    cout << totalSize << '\n';
    cout << myDeque.front();

    return 0;
}