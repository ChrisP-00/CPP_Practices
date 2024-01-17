#include <iostream>
#include <map>
#define fastTime ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std; 

map <string, double> grade;

int main()
{
    grade["A+"] = 4.5;
    grade["A0"] = 4.0;
    grade["B+"] = 3.5;
    grade["B0"] = 3.0;
    grade["C+"] = 2.5;
    grade["C0"] = 2.0;
    grade["D+"] = 1.5;
    grade["D0"] = 1.0;
    grade["F"]  = 0.0;


    string subject, myGrade = "";
    double myMark, credit, totalCredits = 0.0;

    for(int index = 0; index < 20; index++)
    {
        cin >> subject >> credit >> myGrade;

        if(myGrade == "P")
        {
            continue;
        }

        myMark += grade[myGrade] * credit;
        totalCredits += credit;
    }

    cout << myMark / totalCredits;

    return 0;
}