#include<iostream>
using namespace std;

class Animal{
    public:
        virtual void sound() = 0;
};

class Dog : public Animal{
    public:
        void sound() override {
            cout << "woof, woof" << endl;
        }
};
class Cat : public Animal{
    public:
        void sound() override {
            cout << "meow, meow" << endl;
        }
};
class Duck : public Animal{
    public:
        void sound() override {
            cout << "quack, quack" << endl;
        }
};

int main() {
    int  a;
    cin >> a;
    Animal *ani;
    if(a==1) {
        ani = new Dog(); 
    }
    else if(a==2) {
        ani = new Cat();
    }
    else if(a==3) {
        ani = new Duck();
    }
    ani->sound();
    delete ani;
}
