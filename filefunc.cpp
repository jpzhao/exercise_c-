#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream &os,double fo,const double fe[],int n);
const int LIMIT=5;
int main(){
    ofstream fout;
    const char *fn="ep-data.txt";
    fout.open(fn);
    if(!fout.is_open()){
        cout<<"Can't open "<<fn<<". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout<<"Enter the focal length of your "
    "telescope objective in mm: ";
    cin>>objective;      /*1800*/
    double eps[LIMIT];
    cout<<"Enter the focal lengths,in mm,of "<<LIMIT
    <<" eyepieces:\n";
    for(int i=0;i<LIMIT;i++){
        cout<<"Eyepiece #"<<i+1<<": ";
        cin>>eps[i];  /*30,19,14,8.8,7.5*/
    }
    file_it(fout,objective,eps,LIMIT);
    file_it(cout,objective,eps,LIMIT);
    cout<<"Done\n";
    return 0;
}

void file_it(ostream &os,double fo,const double fe[],int n){
    ios_base::fmtflags initial;
    initial=os.setf(ios_base::fixed);//initial=cout.setf(ios_base::fixed);得到初始化格式信息
    //ios_base::fmtflags 是存储这种信息所需的数据类型名称
    //ios_base::fmtflags initial;声明一个用于储存格式化信息的变量
    os.precision(0);
    os<<"Focal length of objective: "<<fo<<" mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os<<"f.1. eyepiece";
    os.width(15);
    os<<"magnification"<<endl;
    for(int i=0;i<n;i++){
        os.width(12);
        os<<fe[i];
        os.width(15);
        os<<int(fo/fe[i]+0.5)<<endl;
    }
    os.setf(initial); //方法setf()返回调用它之前有效的格式化设置
                      //cout.setf(initial);恢复到原始格式
}






