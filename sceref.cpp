#include <iostream>
int main(){
    using namespace std;
    int rats=101;
    int &rodents=rats;
    cout<<"rats= "<<rats;
    cout<<",rodents= "<<rodents<<endl;
    cout<<"rats address= "<<&rats;
    cout<<",rodents address= "<<&rodents<<endl;
    cout<<"-------------------------------------\n";
    int bunnies=50;
    rodents=bunnies;
    cout<<"bunnies= "<<bunnies;
    cout<<",rats= "<<rats;
    cout<<",rodents= "<<rodents<<endl;
    cout<<"bunnies address= "<<&bunnies;
    cout<<", rodents address= "<<&rodents<<endl;
    cout<<"-------------------------------------\n";
    int num=1000;
    int *pt=&num;
    int & num1=*pt;
    int num2=100;
    pt=&num2;
    cout<<"num= "<<num<<endl;
    cout<<"pt= "<<*pt<<" &num= "<<&num<<endl;
    cout<<"pt= "<<*pt<<" &num1= "<<&num1<<endl;
    cout<<"pt= "<<pt<<" &num2= "<<&num2<<endl;
    return 0;
}