#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

class phonebook
{
    private: 
    bool answer = true; 

    public : 
    bool getAnswer();
    void checkingNumbers(vector<string> numbers);
};

bool phonebook::getAnswer()
{
    return answer;
}

void phonebook::checkingNumbers(vector<string> numbers)
{
    sort(numbers.begin(), numbers.end());

    for(int idx = 0; idx < numbers.size() - 1; ++idx)
    {
        answer = numbers[idx] == numbers[idx + 1].substr(0, numbers[idx].length()) ? false : true;
        if(!answer) break;
    }
}

bool solution(vector<string> phone_book)
{
    phonebook mypb;
    mypb.checkingNumbers(phone_book);

    return mypb.getAnswer();
}

int main()
{
    vector<string> q = {"119","12","19111","1235","567"};
    
    cout << boolalpha << solution(q);

    return 0;
}