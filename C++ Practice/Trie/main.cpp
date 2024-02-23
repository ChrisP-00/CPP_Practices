#include <iostream> 

using namespace std; 

struct TRIE
{
    bool Finish;
    TRIE *Node[26];
    TRIE()
    {
        Finish = false;
        for(int idx = 0; idx < 26; idx++)
        {
            Node[idx] = NULL;
        }
    }


    void Insert(char *str)
    {
        if(*str == NULL)
        {
            Finish = true;
            return;
        }
        int Cur = *str - 'A';

        if(Node[Cur] == NULL)
        {
            Node[Cur] = new TRIE();
        }
        Node[Cur]->Insert(str + 1);
    }

    bool Find(char *str)
    {
        if(*str == NULL)
        {
            if(Finish == true) 
            {
                return true;
            }
        }
        int Cur = *str - 'A';
        if(Node[Cur] == NULL)
        {
            return false;
        }

        return Node[Cur]->Find(str + 1);
    }
}

void IsSorting(TRIE *N, char str[], int Idx)
{
    if(N->Finish == true)
    {
        cout << str << '\n';
    }

    for(int i = 0; i < 26; i++)
    {
        if(N->Node[i] != NULL)
        {
            char C = i + 'A';
            str[Idx] = C;
            N->IsSorting(N->Node[i], str, Idx + 1);
        }
    }
}


int main()
{
    TRIE *Root = new TRIE();
    char *String[5];
    String[0] = "ZYX";
    String[1] = "BCG";
    String[2] = "ABC";
    String[3] = "BDE";
    String[4] = "ABCD";

    for(int i = 0; i < 26; i++)
    {
        if(Root->Node[i] != NULL)
        {
            char str[5] = {NULL};
            str[0] = i + 'A';
            Root->IsSorting(Root->Node[i], str, 1);
        }
    }
}