#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int x)
{
	int cnt=0;
	if(x<2)return false;
	if(x==2)return true;
	else {
		int m=sqrt(x);
		for(int i=2;i<=m;i++)
		{
			if(x%i==0)cnt++;
		}
	}
	if(cnt==0)return true;
	else return false;
}
int prime[10010];

int main()
{
	int a,b;
	cin>>a>>b;
	int cnt=0;
	int i=2;
	int j=1;
	while(cnt!=b){
		if(isPrime(i)){
			prime[j++]=i;
			cnt++;
		}
		i++;
	}
	int m=0;
	for(int h=a;h<=b;h++){
		if(h==b){
			cout<<prime[h]<<endl;
		}
		else if(m==9){
			cout<<prime[h]<<endl;m=0;
		}
		else{
			cout<<prime[h]<<" ";
			m++;
		}
		
	}
	return 0;
}
