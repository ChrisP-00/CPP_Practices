#include <iostream>
#include <limits.h>
#include <list>

using namespace std; 

struct microbe
{
    int idx;
    int size;
};

int main()
{
    // first - size, second - initial idx, prev, next 
    list<microbe> myList;

    int microbeIdx, microbeSize, tempPrev, tempNext, totalSize = 0;

    cin >> microbeIdx;

    for(int idx = 1; idx <= microbeIdx; idx++)
    {
        cin >> microbeSize;

        totalSize += microbeSize;

        microbe newMicrobe;
        newMicrobe.idx = idx;
        newMicrobe.size = microbeSize;

        myList.push_back(newMicrobe);
    }

    list<microbe>::iterator iter = myList.begin();

    // while(iter != myList.end())
    // {
    //     microbe temp = *iter;
    //     cout << temp.idx << "번째 미생물 " << iter->size << '\n';
    //     iter++;
    // }

    // iter = myList.begin();

    cout << "================" << '\n';

    while(myList.size() > 1)
    {   
        int next, prev = INT_MAX;
        microbe cur = *iter;

        cout << "현재 미생물은 " << cur.size << '\n';

        if(iter == myList.begin())
        {
            ++iter;
            next = iter->size;
            cout << "다음 미생물은? " << next << '\n';
            --iter;
        }
        else if(++iter == myList.end())
        {
            --iter;
            --iter;
            prev = iter->size;
            cout << "이전 미생물은? " << prev << '\n';
            ++iter;
        }
        else
        {
            next = iter->size;
            cout << "중간! 다음 미생물은? " << next << '\n';
            --iter;
            --iter;
            prev = iter->size;
            cout << "중간! 이전 미생물은? " << prev << '\n';
            ++iter;
        }

        if(prev <= cur.size)
        {
            cur.size += prev;
            --iter;
            cout << "이전걸 먹었다 먹힌 미생물은 " << iter->size << '\n';
            iter = myList.erase(iter);
            cout << "다음 미생물은 " << iter->size << '\n';
        }
        if(next <= cur.size)
        {
            cur.size += next;
            ++iter;
            cout << "다음걸 먹었다 먹힌 미생물은 " << iter->size << '\n';

            if(iter != myList.end())
            {               
                iter = myList.erase(iter);
                cout << "다음 미생물은 " << iter->size << '\n';
            }
            else
            {
                iter = myList.erase(iter);
                cout << "다음 미생물은 " << iter->size << '\n';
                iter = myList.begin();
            }
        }

        cout << "현재 미생물 사이즈는 " << cur.size << '\n';
        myList.insert(iter, cur);

        if(iter != myList.end())
        {
            cout << "다음 포인터!" << '\n';
            ++iter;
        }
        else
        {
            cout << "마지막 포인터!" << '\n';
            iter = myList.begin();
        }

        cout << "================" << '\n';
    }

    cout << totalSize << '\n';
    cout << microbeIdx;

    return 0;
}