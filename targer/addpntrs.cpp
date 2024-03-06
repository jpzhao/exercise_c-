#include <iostream>
int main(){
    using namespace std;
    double wages[3]={10000.0,20000.0,30000.0};
    short stacks[3]={3,2,1};
    double *pw=wages;
    short *ps=&stacks[0];
    cout<<"pw = "<<pw<<",*pw= "<<*pw<<endl; /*10000.0*/
    pw=pw+1;
    cout<<"add 1 to the pw pointer:\n";
    cout<<"pw= "<<pw<<",pw= "<<*pw<<"\n\n";/*20000.0*/
    cout<<"ps= "<<ps<<",*ps= "<<*ps<<endl;/*3*/
    ps=ps+1;
    cout<<"add 1 to the ps pointer:\n";
    cout<<"ps= "<<ps<<",*ps= "<<*ps<<"\n\n";/*2*/
    cout<<"access two elements with array notation\n";
    cout<<"stacks[0]= "<<*stacks
    <<", *(stacks+1)= "<<*(stacks+1)<<endl;/*3,2*/
    cout<<sizeof(wages)<<" =size of wages array\n";/*8*/
    cout<<sizeof(pw)<<" = size of pw pointer\n";/*4*/
    return 0;
}