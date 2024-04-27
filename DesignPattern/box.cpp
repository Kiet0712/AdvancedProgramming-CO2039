#include<iostream>
#include<vector>
using namespace std;

class GiftBase {
    protected:
        string name;
        int price;
    public:
        virtual int CalculateTotalPrice() = 0;
};
class IGiftOperations{
    public:
        virtual void add(GiftBase* gift) = 0;
};
class CompositeGift : public GiftBase, IGiftOperations {
    private:
        vector<GiftBase*> gifts;
    public:
        int CalculateTotalPrice() {
            int a = 0;
            for (int i = 0; i < (int)gifts.size(); ++i) {
                a+=gifts[i]->CalculateTotalPrice();
            }
            return a;
        }
        void add(GiftBase* gift) {
            gifts.push_back(gift);
        }
        ~CompositeGift() {
            for(int i = 0; i < (int)gifts.size();++i) {
                delete gifts[i];
            }
        }
};
class SingleGift : public GiftBase {
    public:
        SingleGift(string name, int price) {
            name = name;
            price = price;
        }
        int CalculateTotalPrice() {
            return price;
        }
};
void Client() {
    GiftBase* phone = new SingleGift("phone",256);
    CompositeGift* box_base = new CompositeGift();
    GiftBase* truckToy = new SingleGift("truckToy",289);
    GiftBase* plainToy = new SingleGift("plainToy",587);
    box_base->add(truckToy);
    box_base->add(plainToy);
    CompositeGift* box_child = new CompositeGift();
    GiftBase* computer = new SingleGift("computer",1000);
    box_child->add(computer);
    box_base->add(box_child);
    cout << box_base->CalculateTotalPrice();
    delete box_base;
}
int main() {
    Client();
}