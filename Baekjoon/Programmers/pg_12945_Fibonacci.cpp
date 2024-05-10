#include <iostream>
#include <string>
#include <vector>

#define baseNum 1234567
using namespace std;

class Fibo 
{
    public : 
    vector<int> memory;

    Fibo();
    int calculateFibo(int n);
    int getAnswer();
};

Fibo::Fibo()
{
    memory.assign(100001, 0);
}

int Fibo::calculateFibo(int n)
{
    if(memory[n] != 0) return memory[n];
    
    
    if(n <= 2) return memory[n] = 1;
        
    else 
        return memory[n] = (calculateFibo(n-1) + calculateFibo(n-2)) % baseNum;
}


int solution(int n) {
    int answer = 0;

    Fibo mypibo;

    answer = ((mypibo.calculateFibo(n-1) % baseNum) + (mypibo.calculateFibo(n-2) % baseNum)) % baseNum;

    return answer;
}

int main()
{
    cout << solution(5);

    return 0;
}