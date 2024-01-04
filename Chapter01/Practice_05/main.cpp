#include <iostream>
using namespace std; 

int main()
{
    double f;

    cout << "Input temperature value in Fehrenheit and press Enter key; ";
    cin >> f;
    cout << f <<" Fehrenheit is " << 1.8 * f + 32.0 << " Celsious" << endl;
        
    return 0;
}