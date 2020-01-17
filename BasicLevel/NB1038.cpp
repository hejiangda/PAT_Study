#include <iostream>

using namespace std;

int main(){
	string num;
	cin>>num;
	int nlen=num.length();
	if(nlen==3){
		for(int i=0;i<num[0]-'0';i++)
		{
			cout<<"B";
		}
		for(int i=0;i<num[1]-'0';i++)
		{
			cout<<"S";
		}
		for(int i=1;i<=num[2]-'0';i++)
		{
			cout<<i;
		}
	}
	if(nlen==2){
		for(int i=0;i<num[0]-'0';i++)
		{
			cout<<"S";
		}
		for(int i=1;i<=num[1]-'0';i++)
		{
			cout<<i;
		}
	}
	if(nlen==1){
		for(int i=1;i<=num[0]-'0';i++)
		{
			cout<<i;
		}
	}
	return 0;
}
