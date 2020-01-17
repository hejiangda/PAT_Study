#include <iostream>
#include <map>
using namespace std;

int main(){
	string num;
	cin>>num;
	map<char,int> mp;
	for(auto it:num)
	{
		mp[it]++;
	}
	for(auto it:mp)
	{
		cout<<it.first<<":"<<it.second<<endl;
	}
	return 0;
}
