#include<iostream>
using namespace std;

class A{
    private:
        int a = 10;
    public:
    friend void show(A& obj);
    friend class B;
};
void show(A &obj){
    cout<<obj.a;
}
class B{
    public:
    void display(A &obj){
        cout<<obj.a;
    }
};

int main(){
    A a;
    show(a);
    cout<<endl;
    B b;
    b.display(a);
}