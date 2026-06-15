#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int Ab = 200;
};

int main(){
    // int a = 10;
    // int *ptr = &a;
    // *ptr *= 10;
    // cout<<a;

    // const int *p = &a;
    // a = 200;
    // cout<<*p;
    
    // int num = 10;
    // int *firstPointer = &num;
    // int **secondPointer = &firstPointer;
    // cout<<firstPointer << " " << secondPointer;
    // int val = 100;
    // int const* ptr = &val;
    // cout<<ptr<<endl;
    // ptr++;
    // cout<<ptr;
    // double dVal = 10.00;
    // double *dptr = &dVal;
    // cout<<sizeof(dptr);
    // cout<<"\n" <<sizeof(dVal);
    // cout<<"\n"<<sizeof(void*);
   
    shared_ptr<A> sp = make_shared<A>();
    weak_ptr<A> wp = sp;
    if(auto t = wp.lock()){
        // sp.reset();
        // t.reset();
        // cout<<t->Ab<<endl;
        cout<<sp.use_count()<<endl;
    }
    
    int x = 10;
    const int * ptr = &x;
    int y = 78;
    cout<<*ptr<<endl;
    ptr = &y; // This is allowed because ptr is a pointer to a const int, not a const pointer. We can change where ptr points, but we cannot change the value of the int it points to through ptr.
    cout<<*ptr<<endl;
    // *ptr = 20; // This line will cause a compilation error because ptr is a pointer to a const int
    int * const ptr2 = &x;
    *ptr2 = 20; // This is allowed because ptr2 is a const pointer to an int, meaning we can change the value of the int it points to, but we cannot change where ptr2 points.
    cout<<*ptr2<<endl;
    // ptr2 = &y; // This line will cause a compilation error because ptr2 is a const pointer, so we cannot change where it points.
    
}

