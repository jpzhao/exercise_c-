#include <iostream>
struct inflatable{
    char name[20];
    float volume;
    double price;
};
int main(){
    using namespace std;
    inflatable bouguet={
        "sunfolwers",
        0.20,
        12.49
    };
    inflatable choice;
    cout<<"bouguet: "<<bouguet.name<<" for $";
    cout<<bouguet.price<<endl;

    choice=bouguet;
    cout<<"choice: "<<choice.name<<" for $";
    cout<<choice.price<<endl;
    return 0;
}