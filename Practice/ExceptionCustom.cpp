#include<bits/stdc++.h>
using namespace std;

class AgeFraud: public exception{
    string message;

    public:
        AgeFraud(string msg = "Age is not correct") : message(msg) {}
        const char * what() const noexcept {
            return message.c_str();
        }
};

class InvalidAge : public AgeFraud{
    public:
        const char * what() const noexcept {
            return "Age is less than 18";
        }
};


class DriversLicense{
    int age;
    public:
        DriversLicense(int a){
            if(a < 18){
                throw InvalidAge();
            }
            age = a;
        }
        void display(){
            cout<<"Driver's License issued for age: "<<age<<endl;
        }
};
// what is object slicing: When an object of a derived class is assigned to an object of a base class, the derived class's specific attributes and behaviors are "sliced off," leaving only the base class's portion. This can lead to loss of information and unexpected behavior, especially when dealing with polymorphism. In the context of exception handling, if you catch an exception by value (e.g., `catch (AgeFraud e)`), it will cause slicing, and you will lose the derived class information (like `InvalidAge`), resulting in the base class's `what()` method being called instead of the derived class's version. To avoid this, exceptions should be caught by reference (e.g., `catch (const AgeFraud& e)`).
int main(){
    try{
        DriversLicense dl(17);
        dl.display();
    }catch(const AgeFraud &e){ // dont catch by value as it will cause slicing and we will lose the derived class information
        cout<<"Exception caught: "<<e.what()<<endl;
    }
}
