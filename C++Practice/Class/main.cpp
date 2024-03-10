#include <iostream>
using namespace std; 

class DayOfYear
{
    int month;
    int day;

    public:
     void output()
     {
        cout << "Today is " << month << "/" << day;
     }
};

int main()
{
    DayOfYear today;

    today.output();

    return 0;
}