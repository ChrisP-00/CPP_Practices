#include <iostream> 

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

    TrieNoe() : chilrend(), isEnd(false);

    void Insert(string& key, int index)
    {
        if(index == key.length() - 1)
        {
            isEnd = true;
        }
        else
        {
            int next = toIndex(key[index]);
            if(children[next] = nullptr)
            {
                children[next] = new Trienode;
            }
            
            children[next]->Insert(key, index + 1);
        }
    }

    void PrintTrie(string& key, int depth)
    {

    }
};


int main()
{


    return 0;
}