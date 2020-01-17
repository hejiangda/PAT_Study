#include <iostream>

using namespace std;

int main(){
	int n,r;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		int cnt=0;
		while(n){
			if(n%r==1)cnt++;
			n/=r;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
