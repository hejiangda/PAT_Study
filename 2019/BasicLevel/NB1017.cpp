#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	int n,r;
	while(scanf("%d%d",&n,&r)!=EOF){
		vector<int>ret;
		while(n){
			ret.push_back(n%r);
			n/=r;
		}
		for(auto it=ret.rbegin();it!=ret.rend();it++)
		{
			if(*it<10)
			{
				cout<<*it;
			}
			else {
				cout<<char(*it-10+'A');
			}
		}
		cout<<endl;
	}
	return 0;
}
