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
class AnimalFactory {
    public:
        static Animal* create_animal(const string & type) {
            if (type=="dog") return new Dog();
            else if (type=="cat") return new Cat();
            else if (type=="duck") return new Duck();
            else return nullptr;
        }
};
int main() {
    string type_animal;
    cin >> type_animal;
    Animal *ani = AnimalFactory::create_animal(type_animal);
    ani->sound();
    delete ani;
}
