#include <iostream>
#include "namesp.h"
namespace pers{
    using std::cout;
    using std::cin;
    void getPersion(Persion &rp){
        cout<<"Enter first name: ";
        cin>>rp.fname;
        cout<<"Enter last names: ";
        cin>>rp.lname;
    }

    void showPersion(const Persion &rp){
        std::cout<<rp.lname<<", "<<rp.fname;
    }
}

namespace debts{
    void getDebt(Debt &rd){
        getPersion(rd.name);
        std::cout<<"Enter debt: ";
        std::cin>>rd.amount;
    }

    void showDebt(const Debt &rd){
        showPersion(rd.name);
        std::cout<<": $"<<rd.amount<<std::endl;
    }

    double sumDebts(const Debt ar[],int n){
        double total=0;
        for(int i=0;i<n;i++)
            total+=ar[i].amount;
        return total;
    }
}