#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int add(char *a,int len,int b){
	int last=b;
	for(int i=len-1;i>=0;i--){
		int tmp=a[i]=='\0'?0:a[i]-'0';
		tmp+=last;
		a[i]=tmp%10+'0';
		cout<<"ai"<<a[i]<<"tmp:"<<tmp<<endl;
		last=tmp/10;
		if(last==0)break;
	}
		cout<<"res:"<<a<<endl;
	return last;
}

int main(){
	string a;
	int b;
	cin>>a>>b;
	int len=a.length();
	char *res=new char[len+1];
	
	memset(res,0,len+1);
	res[len]='\0';
	char *q=new char[len+1];
	memset(q,0,len+1);
	q[len]='\0';
	int flg=0;
	while(!flg&&strcmp(a.c_str(),res)>0){
		flg=add(res,len,b);
		if(!flg&&strcmp(a.c_str(),res)>0)
		add(q,len,1);
	}
	cout<<res;
	cout<<q;
	return 0;
}
