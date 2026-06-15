// 1st way to create singleton class not thread safe
// #include<bits/stdc++.h>
// using namespace std;

// class Single{
//     private:
//         static Single* instance;
//         Single(){
//             cout<<"Constructor called"<<endl;
//         }
//     public:
//         Single(Single& other) = delete;
//         void operator=(const Single&) = delete;
//         static Single* getInstance(){
//             if(instance == nullptr){
//                 instance = new Single();
//             }
//             return instance;
//         }


// };
// Single * Single::instance = nullptr;

// int main(){
//     Single *s1 = Single::getInstance();
//     Single *s2 = Single::getInstance();
//     cout<<s1<<" "<<s2<<endl;
// }

// 2nd way to create singleton class thread safe lazy initialization
// #include<bits/stdc++.h>
// using namespace std;

// mutex mtx;

// class Single{
//     private:
//         static Single * instance;
//         Single(){
//             cout<<"Constructor called"<<endl;
//         }
//         Single(const Single &obj) = delete;
//         Single operator=(const Single&) = delete;
//     public:
//         static Single * getInstance(){
//             if(instance == nullptr){
//                 lock_guard<mutex> lock(mtx);
//                 if(instance == nullptr){
//                     instance = new Single();
//                 }
//             }
//             return instance;
//         }
// };
// Single * Single::instance = nullptr;

// int main(){
//     Single * s1 = Single::getInstance();
//     Single * s2 = Single::getInstance();    
//     cout<<s1<<" "<<s2<<endl;
// }


// 3rd way to create singleton class thread safe eager initialization
// #include<bits/stdc++.h>
// using namespace std;

// class Single{
//     private:
//         static Single * instance;
//         Single(){
//             cout<<"Constructor called"<<endl;
//         }
//         Single(const Single &obj) = delete;
//         Single operator=(const Single&) = delete;
//     public:
//         static Single * getInstance(){
//             return instance;
//         }
// };
// Single * Single::instance = new Single();

// int main(){
//     Single * s1 = Single::getInstance();
//     Single * s2 = Single::getInstance();    
//     cout<<s1<<" "<<s2<<endl;
// }

// 4th way to create singleton class using Meyers singleton thread safe lazy initialization
#include<bits/stdc++.h>
using namespace std;

class Single{
    private: 
        Single(){
            cout<<"Constructor called"<<endl;
        }
        Single(const Single &obj) = delete;
        Single operator=(const Single&) = delete;
    public:
        static Single & getInstance(){
            static Single instance;
            return instance;
        }
};

int main(){
    Single & s1 = Single::getInstance();
    Single & s2 = Single::getInstance();    
    cout<<&s1<<" "<<&s2<<endl;
}