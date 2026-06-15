#include<bits/stdc++.h>
using namespace std;
mutex mtx;
condition_variable cv;
int counter = 1;

void oddPrint(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [](){return counter % 2 == 1;});
    while(counter <= 20){
        cout<<"Counter: "<<counter<<endl;
        counter++;
        cv.notify_all();
    }

}
void evenPrint(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [](){return counter % 2 == 0;});
    while(counter <= 20){
        cout<<"Counter: "<<counter<<endl;
        counter++;
        cv.notify_all();
    }

}
int main(){
    thread t1(oddPrint);
    thread t2(evenPrint);
    t1.join();
    t2.join();
}