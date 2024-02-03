#include <iostream>

using namespace std;

// node 
struct node
{
    int data;
    // address of node 
    node* nextNode;
};


// linked list class 
class myLinkedList
{
    // private member variable
    private:
        node* head;
        node* tail;

    // public member function declaration 
    public: 
        // constructor 
        myLinkedList()
        {
            head =  NULL;
            tail = NULL;
        }

        // add front node
        void addFrontNode(int n);

        // add back node
        void addBackNode(int n);

        // insert node 
        void insertNode(node* prevNode, int n);

        // delete node 
        void deleteNode(node* prevNode);

        // get head node 
        node* getHead()
        {
            return head;
        }

        // print linked list 
        void printNode(node* headNode);
};

// myLinkedList class memeber function definotion
// add front node
void myLinkedList::addFrontNode(int n)
{
    // make new node 
    node* newNode = new node;

    // store data 
    newNode->data = n;

    if(head == NULL)
    {
        // set head & tail 
        head = newNode;
        tail = newNode;
    }
    // if there is data in linked list 
    else
    {
        // newNode -> next node -> previous head node 
        newNode->nextNode = head;
        // set head 
        head = newNode;
    }
}

// add back node
void myLinkedList::addBackNode(int n)
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
void myLinkedList::insertNode(node* prevNode, int n)
{
    node* newNode = new node;
    newNode->data = n;

    newNode->nextNode = prevNode->nextNode;
    prevNode->nextNode = newNode;
}

// delete node 
void myLinkedList::deleteNode(node* prevNode)
{
    // get node to be deleted 
    node* deletedNode = prevNode->nextNode;

    // link prev node and next node 
    prevNode->nextNode = deletedNode->nextNode;

    // delete node 
    delete deletedNode;
}


// print linked list 
void myLinkedList::printNode(node* headNode)
{
    if(headNode == NULL)
    {
        cout << "Linked list is empty.\n";
    }
    else
    {
        // print head node data 
        cout << headNode->data << '\n';
        // recurcive function print next node of current node
        printNode(headNode->nextNode);
    }
}

int main()
{
    myLinkedList myLL;

    myLL.addBackNode(1);
    myLL.addBackNode(2);
    myLL.addBackNode(3);

    myLL.printNode(myLL.getHead());

    return 0;
}
