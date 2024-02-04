#include <iostream>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

// node 
struct node
{
    char data;
    // address of node 
    node* nextNode;
    node* prevNode;
};


// linked list class 
class myLinkedList
{
    // private member variable
    private:
        node* head;
        node* tail;
        node* cursor;

    // public member function declaration 
    public: 
        // constructor 
        myLinkedList()
        {
            head =  NULL;
            tail = NULL;
            cursor = NULL;
        }

        // add back node
        void addBackNode(char n);

        // insert node 
        void insertNode(node* cursor, char n);

        // delete node 
        void deleteNode(node* cursor);

        // get head node 
        node* getHead()
        {
            return head;
        }

        // get tail node 
        node* getTail()
        {
            return tail;
        }

        // get cursor 
        node* getCursor()
        {
            return cursor;
        }

        // set cursor 
        void setCursor(node* pos)
        {
            cursor = pos;
        }

        // print linked list 
        void printNode(node* headNode);
};

// add back node
void myLinkedList::addBackNode(char n)
{
    // make new node 
    node* newNode = new node;
    newNode->data = n;

    // no next node point because this is the last node 
    newNode->nextNode = NULL;

    // if there is no data 
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        cursor = tail->nextNode;
    }
    else
    {
        // set tail's next node is new node 
        tail->nextNode = newNode;
        // set tail  
        tail = newNode;
    }
}

// insert node between two nodes 
void myLinkedList::insertNode(node* cursor, char n)
{
    node* newNode = new node;
    newNode->data = n;

    if(cursor != head)
    {
        newNode->prevNode = cursor->prevNode;
        cursor->prevNode->nextNode = newNode;
    }
    else
    {
        newNode->prevNode = NULL;
        head = newNode;
    }

    newNode->nextNode = cursor;
    cursor->prevNode = newNode;
}

// delete node 
void myLinkedList::deleteNode(node* cursor)
{
    // get node to be deleted 
    node* deletedNode = cursor->prevNode;

    // cursor is not head 
    if(deletedNode != NULL)
    {
        // deleted node is not head 
        if(deletedNode != head)
        {
            // link prev node to cursor 
            deletedNode->prevNode->nextNode = cursor;
        }
        else
        {
            head = cursor;
        }

        cursor->prevNode = deletedNode->prevNode;
        
        // delete node 
        delete deletedNode;
    }
}

// print linked list 
void myLinkedList::printNode(node* headNode)
{
    if(headNode != NULL)
    {
        // print head node data 
        cout << headNode->data;
        // recurcive function print next node of current node
        printNode(headNode->nextNode);
    }
}


int main()
{
    fastTime;

    myLinkedList myLL;
    string input;
    int testCase = 0;
    char command, value = ' ';

    cin >> input; 

    for(int idx = 0; idx < input.size(); idx++)
    {
        myLL.addBackNode(input[idx]);
    }

    cin >> testCase; 

    while(testCase--)
    {
        cin >> command;
        
        switch(command)
        {
            case 'L': 
                if(myLL.getCursor() != myLL.getHead())
                {
                    myLL.setCursor(myLL.getCursor()->prevNode);
                }
                break;

            case 'D':
                if(myLL.getCursor() != myLL.getTail())
                {
                    myLL.setCursor(myLL.getCursor()->nextNode);
                }
                break;
            
            case 'B':
                myLL.deleteNode(myLL.getCursor());
                break;
            
            case 'P': 
                cin >> value;
                myLL.insertNode(myLL.getCursor(), value);
                break;
        }
    }

    // print data 
    myLL.printNode(myLL.getHead());

    return 0;
}
