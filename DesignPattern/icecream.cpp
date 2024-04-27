#include<iostream>
using namespace std;

class IceCream {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};
class ChocolateIceCream : public IceCream {
public:
    string getDescription() const override
    {
        return "Chocolate Ice Cream";
    }
 
    double cost() const override { return 160.0; }
};
class IceCreamDecorator : public IceCream {
protected:
    IceCream* iceCream;
 
public:
    IceCreamDecorator(IceCream* ic)
        : iceCream(ic)
    {
    }
 
    string getDescription() const override
    {
        return iceCream->getDescription();
    }
 
    double cost() const override
    {
        return iceCream->cost();
    }
};
class MatchaDecorator : public IceCreamDecorator {
    public:
        MatchaDecorator(IceCream* ic) : IceCreamDecorator(ic) {}
        string getDescription() const override
        {
            return iceCream->getDescription() + " with Matcha";
        }
    
        double cost() const override
        {
            return iceCream->cost() + 150.0;
        }
};

int main() {
    IceCream* chocolate_ic = new ChocolateIceCream();
    cout << chocolate_ic->getDescription() << " " << chocolate_ic->cost() << endl;
    IceCream* chocolate_matcha_ic = new MatchaDecorator(chocolate_ic);
    cout << chocolate_matcha_ic->getDescription() << " " << chocolate_matcha_ic->cost() << endl;
    delete chocolate_ic;
    delete chocolate_matcha_ic;
    return 0;
}
