#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double input;

    cout << "Convert miles to km" << endl;
    cout << "miles : ";

    cin >> input;

    cout << fixed << setprecision(5) << input << " miles is " << input * 1.60934 << "km" << endl;

    return 0;
}