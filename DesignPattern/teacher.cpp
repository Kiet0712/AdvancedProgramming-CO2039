#include<iostream>
using namespace std;

//target intergace
class Teacher{
    public:
        virtual void teaching() = 0;
};

//Adaptee
class ProbabilityTeacher{
    public:
        void teaching_probability() {
            cout << "P(a) = 0.05" << endl;
        }
};
//Adapter
class AdapterTeacher : public Teacher {
    private:
        ProbabilityTeacher teacher;
    public:
       void teaching() override  {
            teacher.teaching_probability();
       }
};
//clients code
void client_code(Teacher * teacher) {
    teacher->teaching();
}

int main() {
    Teacher * teacher = new AdapterTeacher();
    client_code(teacher);
    delete teacher;
}