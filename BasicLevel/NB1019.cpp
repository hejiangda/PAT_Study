#include <iostream>
#include <vector>
using namespace std;
bool isHuiWen(int n,int code)
{
	vector<int> buf;
	while(n){
		buf.push_back(n%code);
		n/=code;
	}
	auto it1=buf.begin();
	auto it2=buf.rbegin();
	for(;it1!=buf.end();it1++,it2++){
		if(*it1!=*it2)
			return false;
	}
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool flg=false;
		for(int i=2;i<=16;i++){
			if(isHuiWen(n,i)){
				cout<<"Yes"<<endl;
				flg=true;
				break;
			}
		}
		if(flg==false)
		cout<<"No"<<endl;
	}
	return 0;
}
