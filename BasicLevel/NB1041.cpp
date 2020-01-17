#include <iostream>
#include <vector>
using namespace std;
char buf[90];
int main(){
	vector<string> ret;
	while(scanf("%s",buf)!=EOF){
		string tmp=buf;
		ret.push_back(tmp);
	}
	cout<<*ret.rbegin();
	for(auto it=ret.rbegin()+1;it!=ret.rend();it++){
		cout<<" "<<*it;
	}
	return 0;
}
