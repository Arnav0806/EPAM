#include<bits/stdc++.h>
using namespace std;
std::function<void()> getLambda()
{
    int x = 10;

    return [&]() {
        std::cout << x << '\n';
    };
}
void print(int x){
    cout<<x<<endl;
}   
template<typename T>
void print(T t){
    cout<<t<<endl;
}
template<>
void print <bool>(bool t){
    cout<<(t ? "Added" : "Already Exists")<<endl;
}
int main()
{
    void (*ff)(int) = print;
    ff(10);
    auto f = getLambda();

    // f();   // Undefined Behavior
    vector<int> v = {1, 2, 3, 4, 5};
    
    vector<int> :: iterator it = v.erase(v.begin());
    cout<<*it<<endl;
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    set<int> st = {1, 2, 3, 4, 5};
    auto it2 = st.emplace(6);
    print(it2.second);
    
    // try{
    //     cout<<v.at(10)<<endl; // throws out_of_range exception
    // }
    // catch(const std::exception& e){
    //     cout<<"Caught exception: "<<e.what()<<endl;
    // }
    //  list<string> l1 = {"a", "ABC", "ab"};
    // list<string> l2 = {"ba", "BC", "b"};
    // l1.sort();
    // l2.sort();
    // l1.merge(l2);
    // for(auto it : l1){
    //     cout<<it<<" ";
    // }
}
