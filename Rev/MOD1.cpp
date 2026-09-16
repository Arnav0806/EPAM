#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 100;
    int *ptr = &x;
    cout<<*ptr;
    // Pointer: stores the address of a variable, ptr here is a integer pointer variable that stores the address of x
    cout<<endl;
    int &ref = x;
    cout<<ref << endl;
    // Reference: an alias for a variable

    // const with pointer and reference
    int y = 200;
    // const int *ptr2 = &y;
    // with const int pointer we cant change the value of the original variable through the pointer like
    // *ptr2 = 300; // this will give an error
    
    // now with int * const ptr3 = &y; // here we can change the value of the original variable through the pointer like
    // *ptr3 = 300; // this will work fine but we cant change the address of the pointer like ptr3 = &x; // this will give an error 

   // const int * const ptr4 = &x;
   // with this we cant change the value of the original variable through the pointer and also we cant change the address of the pointer like *ptr4 = 300; // this will give an error and ptr4 = &y; // this will also give an error

    return 0; 

    
}