#include <iostream>
#include <climits> 
using namespace std; 

int main()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;


    cout << "int는 " << sizeof (int) << " 바이트 이다." << endl;
    cout << "short는 " << sizeof (short) << " 바이트 이다." << endl;
    cout << "long은 " << sizeof (long) << " 바이트 이다." << endl;
    cout << "long long 은 " << sizeof (long long) << " 바이트 이다." << endl;

    cout << "최댓값" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;

    return 0;
}
