#include<iostream>
using namespace std; 

struct MyStruct {
    string parent = "Struct!";

    void WhoIAm() {
        cout << "I am " << parent << '\n'; 
    }
};

class MyClass {
    string parent = "Class!";

    void WhoIAm() {
        cout << "I am " << parent << '\n'; 
    }
};

int main() {
    MyStruct myStruct; 
    MyClass myClass;

    myStruct.WhoIAm();
    myClass.WhoIAm();

    return 0;
}
