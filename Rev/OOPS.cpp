#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int a = 19;
};
class B : public A{
    public:
        void display(){
            cout<<a<<endl;
        }
};

int main(){
    B obj;
    obj.display();
}