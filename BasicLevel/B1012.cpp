#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long  a,b;
	int d;
	cin>>a>>b>>d;
	long long res=a+b;
	vector<int> output;
	while(res>0){
		output.push_back(res%d);
		res=res/d;
	}
	for(auto it=output.rbegin();it!=output.rend();it++)
		cout<<*it;
	return 0;
}
