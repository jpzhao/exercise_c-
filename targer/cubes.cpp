#include <iostream>
double cube(double a);
double refcube(double &ra);
double refcube1(const double &rc);
int main(){
    using namespace std;
    double x=3.0;
    cout<<cube(x);
    cout<<" = cube of "<<x<<endl;
    cout<<refcube(x);
    cout<<" = cube of "<<x<<endl;
    double side=3.0;
    double *pd=&side;
    double &rd=side;
    long edge=5L;
    double lens[4]={2.0,5.0,10.0,12.0};
    double c1=refcube1(side);
    cout<<" = cube of "<<c1<<endl;
    double c2=refcube1(lens[2]);
    cout<<" = cube of "<<c2<<endl;
    double c3=refcube1(rd);
    cout<<" = cube of "<<c3<<endl;
    double c4=refcube1(*pd);
    cout<<" = cube of "<<c4<<endl;
    double c5=refcube1(edge);
    cout<<" = cube of "<<c5<<endl;
    double c6=refcube1(7.0);
    cout<<" = cube of "<<c6<<endl;
    double c7=refcube1(side+10.0);
    cout<<" = cube of "<<c7<<endl;
    return 0;
}

double cube(double a){
    a*=a*a;
    return a;
}

double refcube(double &ra){
    ra*=ra*ra;
    return ra;
}

double refcube1(const double &rc){
    /*c++ expression must be a modifiable lvalue" 
    是编译器抛出的错误信息，意思是在C++ 中表达式必须是一个可修改的左值*/
    double bc=rc*rc;
    return bc;
}