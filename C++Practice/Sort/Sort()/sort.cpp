#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

// 숫자 내림차순으로 정렬
bool asc_num(const pair<int,char>& a, const pair<int,char>& b)
{
    return a.first > b.first;
}

// 알파벳 오름차순으로 정렬
bool desc_alphabet(const pair<int,char>& a, const pair<int,char>& b)
{
    return a.second < b.second;
}

// 벡터의 요소를 출력
void print(vector<pair<int,char>> myVector)
{
    for(auto v : myVector)
    {
        cout << "first: " << v.first << " second: " << v.second << '\n';
    }
}

int main()
{
    vector<pair<int, char>> myVector = {{9, 'A'}, {7, 'B'}, {5, 'D'}, {2, 'H'}, {1, 'Z'}, {1, 'K'}};

    cout << "not sorted yet!\n";
    print(myVector);

    sort(myVector.begin(), myVector.end());

    cout << "\ndefault sort\n";
    print(myVector);

    sort(myVector.begin(), myVector.end(), asc_num);

    cout << "\nsort ascending by number\n";
    print(myVector);

    sort(myVector.begin(), myVector.end(), desc_alphabet);

    cout << "\nsort descending by alphabet \n";
    print(myVector);

    cout << "\nusing lamda\n";
    
    sort(myVector.begin(), myVector.end(), [](const pair<int,char>& a, const pair<int,char>& b)-> bool{
        return a.first < b.first;
    });
    print(myVector);

    return 0;
}