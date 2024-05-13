#include <iostream> 

using namespace std; 


class parent 
{
    int a, b; 

    public : 
    parent(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    virtual void print()
    {
        cout << a + b;
    }
};

class child: public parent
{
    int c = 5;

    public: 
    child(int n) : parent(n, n + 1) {}
    void print() override
    {
        cout << c * c;
    }
};

int main()
{
    parent *myclass = new child(2);
    myclass->print();

    return 0;
}