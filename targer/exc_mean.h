#include <iostream>
class had_hmean{
    private:
        double v1;
        double v2;
    public:
        had_hmean(double a=0,double b=0):v1(a),v2(b){}
        void mesg();
};

inline void had_hmean::mesg(){
    std::cout<<"hmean("<< v1<<", "<<v2<<"): "
            <<"invalid arguments: a = -b\n";
}

class bad_gmean{
    public:
        double v1;
        double v2;
        bad_gmean(double a=0,double b=0):v1(a),v2(b){}
        const char * mesg();
};

inline const char * bad_gmean::mesg(){
    return "gmean() arguments should be>=0\n";
}