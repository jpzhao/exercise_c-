#include <iostream>
#include <cstring>
#include "tv.h"
#include "workermi.h"

void workmi();
// int main(){
//     using std::cout;
//     Tv s42;
//     cout<<"Initial settings for 42\" TV:\n";
//     s42.settings();
//     s42.onoff();
//     s42.chanup();
//     cout<<"\nAdjusted settings for 42\" TV:\n";
//     s42.settings();
//     Remote grey;
//     grey.set_chan(s42,10);
//     grey.volup(s42);
//     grey.volup(s42);
//     cout<<"\n42\" settings after using remote:\n";
//     s42.settings();

//     Tv s58(Tv::On);
//     s58.set_mode();
//     grey.set_chan(s58,28);
//     cout<<"\n58\" settings:\n";
//     s58.settings();
//     workmi();
//     return 0;
// }

void workmi(){
    const int SIZE=5;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Worker * lolas[SIZE];

    int ct;
    for(ct=0;ct<SIZE;ct++){
        char choice;
        cout<<"Enter the employee category:\n"
            <<"w: waiter s: singer "
            <<"t: singing waiter q: quit\n";
        cin>>choice;
        while(strchr("wstq",choice)==NULL){
            cout<<"Please enter a w,s,t,or q: ";
            cin>>choice;
        }
        if(choice=='q')
            break;
        switch(choice){
            case 'w':lolas[ct]=new Waiter;
                    break;
            case 's':lolas[ct]=new Singer;
                    break;
            case 't':lolas[ct]=new SingingWaiter;
                    break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    cout<<"\nHere is your staff:\n";
    int i;
    for(i=0;i<ct;i++){
        cout<<endl;
        lolas[i]->Show();
    }

    for(i=0;i<ct;i++)
        delete lolas[i];
    cout<<"Bye.\n";

}