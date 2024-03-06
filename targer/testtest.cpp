#include <iostream>
template<typename T>
T Add(T a,T b);

template<typename T>
T Add(T &a,T &b);

int main(){
    using namespace std;
    int m=6;
    int k=7;
    double x= 10.2;
    cout<<Add<double>(x,m)<<endl;
    cout<<Add<double>(k,m)<<endl;
}

template<typename T>
T Add(T a,T b){
    std::cout<<"AAAAAAAAA";
    return a+b;
}

template<typename T>
/*no instance of function template "Add" matches the argument list*/
/*more than one instance of overloaded function "Add" matches the argument */
T Add(T &a,T &b){
    std::cout<<"BBBBBBBBB";
    return a+b;
}