#include <iostream>
#include "namesp.h"
void other(void);
void another(void);
int main(void){
    using debts::Debt;   /*using声明*/
    using debts::showDebt;
    Debt golf={{"Benny","Goatsniff"},120.0};
    showDebt(golf);
    other();
    another();
    return 0;
}

void other(void){
    using std::cout;
    using std::endl;
    using namespace debts;
    Persion dg={"Doodles","Glister"};
    showPersion(dg);
    cout<<endl;
    Debt zippy[3];
    int i;
    for(i=0;i<3;i++)
        getDebt(zippy[i]);
    
    for(i=0;i<3;i++)
        showDebt(zippy[i]);
        
    cout<<"Total debt: $"<<sumDebts(zippy,3)<<endl;
    return;
}

void another(void){
    using pers::Persion;
    Persion collector={"Milo","Rightshift"};
    pers::showPersion(collector);
    std::cout<<std::endl;
}