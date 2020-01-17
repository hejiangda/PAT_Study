#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,r;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		int sum=0;
		while(n){
			sum+=n%r;
			n=n/r;
		}
		vector<int> ret;
		while(sum){
			ret.push_back(sum%r);
			sum/=r;
		}
		for(auto it=ret.rbegin();it!=ret.rend();it++){
			if(*it<10)
				cout<<*it;
			else {
				cout<<char('A'+*it-10);
			}
		}
	    cout<<endl;
	}
	
	return 0;
}
