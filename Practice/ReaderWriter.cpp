#include<bits/stdc++.h>
using namespace std;

shared_mutex mtx;
string str;
mutex mt2;
condition_variable cv;
bool edited = false;

void reader(){
    shared_lock<shared_mutex> lock(mtx);
    // cv.wait(lock, [](){return edited;});
    mt2.lock();
    cout<<"Reader reading the string: "<<str<<endl;
    mt2.unlock();

}
void writer(string message){
    unique_lock<shared_mutex> lock(mtx);
    cout<<"Writer Editing the string: "<<endl;
    str += message;
}
int main(){
    
    thread t1(reader);
    thread t2(writer, "First ");
    thread t3(reader);
    thread t4(writer, "Second ");
    thread t5(reader);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
}