#include <iostream> 

using namespace std; 

int sum(int a, int b)
{
    return a + b;
}

auto lamda_sum = [](int a, int b){
    return a + b;
};


int main()
{

    int result = lamda_sum(3, 4);
    int l_result = [](int a, int b){ return a + b; }(3, 4);

    cout << result;
    cout << l_result;

    return 0;
}