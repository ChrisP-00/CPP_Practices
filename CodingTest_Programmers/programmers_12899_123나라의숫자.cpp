#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
        
    while(n > 0)
    {
        int temp = n % 3;
        
        switch(temp)
        {
            case 0 : 
                answer += "4";
                break;
            
            case 1 : 
                answer += "1";
                break;
                
            case 2 : 
                answer += "2";
                break;
        }
        
        n /= 3;
    }
    
    return answer;
}