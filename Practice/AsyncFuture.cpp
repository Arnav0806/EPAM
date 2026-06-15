#include<bits/stdc++.h>
using namespace std;

int helper(int x){
    cout<<"Async function called: "<<x<<endl;
    cout<<"thread running this function: "<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    return 111;
}
void promiseHelper(promise<int> &prom, int x){
    cout<<"Promise helper function called "<<x<< endl;
    cout<<"thread running this function: "<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    prom.set_value(222);
    
}
int packagedTaskHelper(int x){
    cout<<"Packaged task helper function called: "<<x<<endl;
    cout<<"thread running this function: "<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    return 333;
}

int main(){
    future<int> fut = async(
        launch::deferred, helper, 10
);
    cout<<"Main thread: "<<this_thread::get_id()<<endl;
    future_status status = fut.wait_for(chrono::seconds(1));
    if(status == future_status::ready){
        cout<<"Future is ready"<<endl;
        
    }
    else if(status == future_status::timeout){
        cout<<"Future is not ready after 1 second"<<endl;
    }
    else if(status == future_status::deferred){  // gcc and clang do not support deferred launch policy msvc does so when we do wait_for
        cout<<"Future is deferred"<<endl;
    }
    int result = fut.get();

    cout<<"Result from async function: "<<result<<endl;





    promise<int> prom;
    thread t(promiseHelper, ref(prom), 14);
    future<int> promFut = prom.get_future();
    t.join();
    cout<<"Result from promise: "<<promFut.get()<<endl;





    future<int> packagedFut;
    packaged_task<int(int)> task(packagedTaskHelper);
    packagedFut = task.get_future();
    thread t2(move(task), 20);
    t2.join();
    cout<<"Result from packaged task: "<<packagedFut.get()<<endl;

}