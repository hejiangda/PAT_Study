#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	string num;
	cin>>num;
	while(num.length()<4){
		num.push_back('0');
	}
	sort(num.begin(),num.end(),cmp);
	string rnum;
	for(auto it=num.rbegin();it!=num.rend();it++)
	{
		rnum.push_back(*it);
	}
	int res=0;
	while(res!=6174)
	{ 
		res=stoi(num)-stoi(rnum);
		if(res==0){
			cout<<"N - N = 0000"<<endl;
			break;
		}
		cout<<num<<" - "<<rnum<<" = "<<res<<endl;
		num=to_string(res);
		sort(num.begin(),num.end(),cmp);
		rnum="";
		for(auto it=num.rbegin();it!=num.rend();it++)
		{
			rnum.push_back(*it);
		}
		
	}
	
	return 0;
}
