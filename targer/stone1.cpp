#include <iostream>
#include "stonewt1.h"
int main(){
    using std::cout;
    Stonewt poppins(9,2.8);
    double p_wt=poppins;
    cout<<"Convert to double=> ";
    cout<<"Poppins: "<<p_wt<<" pounds.\n";
    cout<<"Convert to int => ";
    cout<<"Poppins: "<<int(poppins)<<" pounds.\n";
    int ar[20];
    Stonewt temp(14,4);
    int Temp=1;
    printf("%d\n",(int)temp);
    printf("%p\n",&(ar[(int)temp]));
    cout<<ar[(int)temp]<<"!\n";
    return 0;
}