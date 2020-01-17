#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int cnt=0;
	while(n!=1){
		cnt++;
		if(n&1){
			n=3*n+1;
			n/=2;
		}else {
			n/=2;
		}
	}
	cout<<cnt;
		
	return 0;
}
