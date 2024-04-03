#include <iostream>
int main(){
	using namespace std;
	cout<<"Enter number: ";
	int sum=0;
	int input;
	while(cin>>input){
		sum+=input;
	}

	cout<<"Last value entered = "<<input<<endl;
	cout<<"Sum = "<<sum<<endl;
	return 0;
}
