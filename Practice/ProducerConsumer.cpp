#include<bits/stdc++.h>
using namespace std;
mutex mtx;
condition_variable cv;
optional<int> buffer;

// void producer(){
//     for(int i = 1 ; i < 5 ; i++){
//         unique_lock<mutex> lock(mtx);
//         cv.wait(lock, [](){return !buffer.has_value();});
//         buffer = i;
//         cout<<"Produced: "<<i<<endl;
//         cv.notify_all();
//     }
// }
// void consumer(){
//     for(int i = 1 ; i < 5 ; i++){
//         unique_lock<mutex> lock(mtx);
//         cv.wait(lock, [](){return buffer.has_value();});
//         cout<<"Consumed: "<<buffer.value()<<endl;
//         buffer.reset();
//         cv.notify_all();
//     }
// }
void producer(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [](){return !buffer.has_value();});
    buffer = 111;
    cout<<"Produced: "<<buffer.value()<<endl;
    lock.unlock();
    cv.notify_all();
}
void consumer(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [](){return buffer.has_value();});
    cout<<"Consumed: "<<buffer.value()<<endl;
    buffer.reset();
    lock.unlock();
    cv.notify_all();
}

int main(){
    thread prod(producer);
    thread cons(consumer);
    prod.join();
    cons.join();
}