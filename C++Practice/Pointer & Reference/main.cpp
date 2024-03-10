#include <iostream>
 
using namespace std;


void sumRef(int& ref)
{
    ref += 10;
}

void sumPtr(int* ptr)
{
    *ptr += 10;
}


int main()
{
    int a = 10;

    // * Dereference operator == 주소의 값을 접근
    // & Address of operator == 주소를 접근
    // 둘다 같은 선언
    // int *ptrA // int* ptrA
    int* ptrA = &a;


    int& refA = a;

    cout << "원본 A의 값은 " << a << '\n';

    cout << "포인터 A의 값은 " << ptrA << '\n';
    cout << "포인터 A의 주소에 있는 값은 " << *ptrA << '\n';
    cout << "레퍼런스 A의 값은 " << refA << '\n';

    sumPtr(ptrA);
    cout << "포인터에 10 더하기! \n";
    cout << "원본 A의 값은 " << a << '\n';
    cout << "포인터 A의 값은 " << ptrA << '\n';
    cout << "포인터 A의 주소에 있는 값은 " << *ptrA << '\n';
    cout << "레퍼런스 A의 값은 " << refA << '\n';

    sumRef(refA);
    cout << "레퍼런스에 10 더하기! \n";
    cout << "원본 A의 값은 " << a << '\n';
    cout << "포인터 A의 값은 " << ptrA << '\n';
    cout << "포인터 A의 주소에 있는 값은 " << *ptrA << '\n';
    cout << "레퍼런스 A의 값은 " << refA << '\n';


    return 0;
}