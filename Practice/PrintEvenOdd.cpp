// Printing even and odd numbers till 20 using two threads
#include<bits/stdc++.h>
using namespace std;
mutex mtx;
condition_variable cv;

int counter = 1;
void printOdd(){
    while(counter <= 20){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return counter % 2 == 1;});
        cout<<counter<<" ";
        counter++;
        cv.notify_all();
    }
}
void printEven(){
    while(counter <= 20){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return counter % 2 == 0;});
        cout<<counter<<" ";
        counter++;
        cv.notify_all();
    }
}

int main(){
    thread odd(printOdd);
    thread even(printEven);
    odd.join();
    even.join();
}