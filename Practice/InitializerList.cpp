#include<bits/stdc++.h>
using namespace std;

class A{
    int x;
    int y;
    public:
        A(int val) : y(val), x(y + 2){
            cout<<"Value of x: "<<x<<" Value of y: "<<y<<endl;
        } 
};

int main(){
    A a(10);
}