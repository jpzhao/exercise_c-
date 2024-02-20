#include <string>
namespace pers{
    struct Persion{
        std::string fname;
        std::string lname;
    };
    void getPersion(Persion &);
    void showPersion(const Persion &);
}

namespace debts{
    using namespace pers; /*using编译指令*/
    struct Debt{
        Persion name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[],int n);
}