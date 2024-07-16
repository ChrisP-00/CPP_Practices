#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

void ConvertToBinary(const long long* from, string* to)
{
    cout << "num: " << *from << '\n';

    long long num = *from;
    string temp = "";
    while(num > 0)
    {
        temp += to_string(num % 2);
        num /= 2;
    }
    reverse(temp.begin(), temp.end());

    // 노트와 높이를 계산하여 완전 이진트리의 노드 수 계산
    int nodes = temp.length();
    int height = ceil(log2(nodes + 1));
    int totalNodes = pow(2, height) - 1;

    int dummy = totalNodes - nodes;

    cout << "Nodes: " << nodes << " height: " << height << " total: " << totalNodes << " Dummy: " << dummy << '\n';

    while(dummy)
    {
        dummy--;
        *to += '0';
    }

    *to += temp;

    cout << "binary: " << *to << '\n';
    cout << '\n';
}

int CheckCompleteBinary(string num)
{
    if(num.length() < 1)
    {
        return 1;
    }

    string leftTree = num.substr(0, num.length() / 2);
    string rightTree = num.substr(num.length() / 2 + 1);

    char root = num[num.length() / 2];
    char left = leftTree[leftTree.length() / 2];
    char right = rightTree[rightTree.length() / 2];

    cout << "Root: " << root << " left: " << left << " right: " << right << '\n';

    if(root == '0' && (left == '1' || right == '1'))
    {
        return 0;
    }
    
    return CheckCompleteBinary(leftTree) && CheckCompleteBinary(rightTree);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer = { 99, 99 };
    
    // 이진 트리의 노드의 개수 n = 2^h - 1
    // 이진 트리의 높이 h = log2(n + 1)
    // 이진수로 변환한 트리의 높이를 구하고 -> 그 높이에 맞는 노드의 개수를 구한 차이 만큼 0을 추가해줌
    // 완전 이진 트리에서 루트부터 inorder로 순회
    // 부모가 0인데 자식이 1인 경우 이진 트리를 만들 수 없다.
    //       0
    //      / \
    //     1   0
    // 트리는 부모가 없는데 자식이 만들어질 수 없기 때문!

    for(int i = 0; i < numbers.size(); ++i)
    {
        string longToBinary = "";
        ConvertToBinary(&numbers[i], &longToBinary);

        cout << longToBinary << '\n';

        answer.push_back(CheckCompleteBinary(longToBinary));
    }

    return answer;
}


int main()
{
    vector<long long> numbers = {7, 42, 5};
    
    vector<int> answer = solution(numbers);
    
    for(int num : answer)
    {
        cout << num  << '\n';
    }

    return 0;
}