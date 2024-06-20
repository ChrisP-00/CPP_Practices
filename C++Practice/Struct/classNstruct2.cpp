#include<iostream>

using namespace std; 

struct MyStruct {
    string parent = "Struct!";

    void WhoIAm() {
        cout << "I am " << parent << '\n'; 
    }
};

struct ChildStruct : MyStruct {
    
    void MyParentIs() {
        cout << parent << " is my parent \n";
    }
};

class MyClass {
public:
    string parent = "Class!";

    void WhoIAm() {
        cout << "I am " << parent << '\n'; 
    }
};

class ChildClass : MyClass {
public: 
    void MyParentIs() {
        cout << parent << " is my parent \n";
    }
};

int main()
{
    ChildStruct childStruct;
    ChildClass childClass;

    childStruct.MyParentIs();
    childClass.MyParentIs();

    cout << "childStruct's pareint is " << childStruct.parent;
    cout << "childClass's parent is " << childClass.parent;

    return 0;
}