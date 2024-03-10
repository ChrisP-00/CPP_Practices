#include <iostream> 
#include <vector>

using namespace std; 

const int Num_Alphabets = 26;

// convert char to int 
int toIndex(char ch) 
{ 
    return ch - 'A';
}

struct TrieNode
{
    TrieNode* children[Num_Alphabets];
    bool isEnd;

    TrieNode() : children(), isEnd(false) {}

    void Insert(string& key, int index)
    {
        if(index == key.length() - 1)
        {
            isEnd = true;
        }
        else
        {
            int next = toIndex(key[index]);
            if(children[next] == nullptr)
            {
                children[next] = new TrieNode;
            }
            
            children[next]->Insert(key, index + 1);
        }
    }

    bool Find(string& key, int depth)
    {
        if(depth == key.length() - 1 && isEnd)
        {
            return true;
        }
        if(depth == key.length() - 1 && !isEnd)
        {
            return false;
        }
        
        int next = toIndex(key[depth]);

        if(children[next] == nullptr)
        {
            return false;
        }

        return children[next]->Find(key, depth + 1);
    }
};

int main()
{
    vector<string> words = {"APPLE", "BANANA", "PEACH"};

    TrieNode root; 

    for(string word : words)
    {
        root.Insert(word, 0);
    }

    string search = "";

    cin >> search;

    if(root.Find(search, 0)) 
    {
        cout << search << "이 검색 결과에 있습니다.";
    }
    else
    {
        cout << search << "이 검색 결과에 없습니다.";
    }


    return 0;
}