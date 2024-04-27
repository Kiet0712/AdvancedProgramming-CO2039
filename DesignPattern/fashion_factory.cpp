#include <iostream>
using namespace std;


class IDress{
    public:
    virtual string GetName() = 0;
    virtual string GetModel() = 0;
};
class IShoes{
    public:
    virtual string GetName() = 0;
    virtual string GetModel() = 0;
};
class IFashion{
    public:
    virtual IDress* Create_Dress() = 0;
    virtual IShoes* Create_Shoes() = 0;
};
class SummerDress : public IDress{
    public:
    string GetName() {
        return "Summer Dress";
    }
    string GetModel() {
        return "Summer";
    }
};
class SummerShoes : public IShoes{
    public:
    string GetName() {
        return "Summer Shoes";
    }
    string GetModel() {
        return "Summer";
    }
};
class WinterDress : public IDress{
    public:
    string GetName() {
        return "Winter Dress";
    }
    string GetModel() {
        return "Winter";
    }
};
class WinterShoes : public IShoes{
    public:
    string GetName() {
        return "Winter Shoes";
    }
    string GetModel() {
        return "Winter";
    }
};
class SummaerFashion : public IFashion {
    public:
    IDress* Create_Dress() {
        return new SummerDress();
    }
    IShoes* Create_Shoes() {
        return new SummerShoes();
    }
};
class WinterFashion : public IFashion{
    public:
    IDress* Create_Dress() {
        return new WinterDress();
    }
    IShoes* Create_Shoes() {
        return new WinterShoes();
    }
};
class Clients{
    public:
    void ClientsMethod(IFashion* fashion) {
        IDress* Dress = fashion->Create_Dress();
        IShoes* Shoes = fashion->Create_Shoes();
        cout << Dress->GetName() << " " << Dress->GetModel() << endl;
        cout << Shoes->GetName() << " " << Shoes->GetModel() << endl;
        delete Dress;
        delete Shoes;
    }
};

int main() {
    IFashion* fashion = new WinterFashion();
    Clients temp;
    temp.ClientsMethod(fashion);
    delete fashion;
    return 0;
}