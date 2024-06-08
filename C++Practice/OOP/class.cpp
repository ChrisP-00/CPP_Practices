#include <iostream>
using namespace std; 

class ICooking{
    public:
    virtual void cook() = 0;
    virtual ~ICooking() = default;
};

class FryingPan : public ICooking {
    public:
    void cook() override {
        cout << "Frying... \n";
    };
};

class BakingBread : public ICooking {
    public:
    void cook() override {
        cout << "baking... \n";
    };
};

class Chef {
    private: 
    ICooking* cook;

    public: 
    Chef(ICooking* cook) : cook(cook) {}
    void changeCook(ICooking* newCook){
        this->cook = newCook;
    }
    void makingDish()
    {
        cook->cook();
    }
};

int main()
{
    ICooking* cook1 = new FryingPan();
    ICooking* cook2 = new BakingBread();

    Chef myChef(cook1);
    myChef.makingDish();

    myChef.changeCook(cook2);
    myChef.makingDish();

    return 0;
}