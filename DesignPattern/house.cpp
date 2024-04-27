#include<iostream>
#include<string>
using namespace std;

//subsystem 1
class Lock{
    private:
        string password;
    public:
        Lock(const string& password) : password(password) {}
        bool check_pass(const string& password) {
            return this->password == password;
        }
};
//subsystem 2
class Alarm{
    public:
        void alarm_on() {
            cout << "Alarm is on!" << endl;
        }
        void alarm_off() {
            cout << "Alarm is off!" << endl;
        }
        void alarm_sound() {
            cout << "Beep beep beep!" << endl;
        }
};
//subsystem 3
class Electric{
    public:
        void on() {
            cout << "Electric is on!" << endl;
        }
        void off() {
            cout << "Electric is off!" << endl;
        }
}; 

//facade
class House{
private:
    Lock lock;
    Alarm alarm;
    Electric electric;
public:
    House(const string& password) : lock(password) {}
    void come_home() {
        while (true)
        {
            string password;
            cout << "Please input password!" << endl;
            getline(cin,password);
            if(lock.check_pass(password)) break;
            else {
                alarm.alarm_sound();
            }
        }
        alarm.alarm_off();
        electric.on();
    }
    void go_outside() {
        alarm.alarm_on();
        electric.off();
    }
};

int main() {
    House my_house("tuankiet07122004");
    cout << "I'm going home!!" << endl;
    my_house.come_home();
    cout << "I go to school!!" << endl;
    my_house.go_outside();
    return 0;
}