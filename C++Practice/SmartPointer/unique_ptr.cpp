#include <iostream>
#include <string>
#include <memory> 

using namespace std; 

class Dog2;

class Dog1
{
    string MyName = "";

    public: 
    weak_ptr<Dog2> weakptr;

    Dog1(string Name){
        MyName = Name;
        cout << "Hi, I'm " << MyName << '\n';
    }

    ~Dog1(){
        cout << "Bye, " << MyName << '\n';
    }
};

class Dog2
{
    string MyName = "";
    
    public: 
    weak_ptr<Dog1> weakptr;

    Dog2(string Name){
        MyName = Name;
        cout << "Hi, I'm " << MyName << '\n';
    }

    ~Dog2(){
        cout << "Bye, " << MyName << '\n';
    }
};


int main()
{    
    shared_ptr<Dog1> sharedPtr1 = make_shared<Dog1>("Shared 1");
    shared_ptr<Dog2> sharedPtr2 = make_shared<Dog2>("Shared 2");

    sharedPtr1->weakptr = sharedPtr2;
    sharedPtr2->weakptr = sharedPtr1;

    cout << "sharedPtr1 use cout: " << sharedPtr1.use_count() << '\n';
    cout << "sharedPtr2 use cout: " << sharedPtr2.use_count() << '\n';


    shared_ptr<Dog1> sharedPtr2 = sharedPtr1;

    shared_ptr<Dog1> sharedPtr2(sharedPtr1);

    return 0;
}