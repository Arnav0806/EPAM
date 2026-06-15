#include<bits/stdc++.h>
using namespace std;
mutex mtx1, mtx2;

void dead1(){
    // mtx1.lock();
    // mtx2.lock();
    scoped_lock<mutex, mutex> lock(mtx1, mtx2);
    cout<<"Thread 1 has locked mtx1"<<endl;
    cout<<"Thread 1 has locked mtx2"<<endl;
    // mtx2.unlock();
    // mtx1.unlock();
}

void dead2(){
    // mtx1.lock();
    // mtx2.lock();
    scoped_lock<mutex, mutex> lock(mtx1, mtx2);
    cout<<"Thread 2 has locked mtx1"<<endl;
    cout<<"Thread 2 has locked mtx2"<<endl;
    // mtx2.unlock();
    // mtx1.unlock();
}

int main(){
    thread t1(dead1);
    thread t2(dead2);
    t1.join();
    t2.join();
}