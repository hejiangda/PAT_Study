#include <iostream>
#include <map>
using namespace std;

int isAwin(char a,char b){
	if(a=='B'&&b=='C')
	return 1;
	if(a=='B'&&b=='B')
	return 0;
	if(a=='B'&&b=='J')
	return -1;
	if(a=='C'&&b=='B')
	return -1;
	if(a=='C'&&b=='C')
	return 0;
	if(a=='C'&&b=='J')
	return 1;
	if(a=='J'&&b=='B')
	return 1;
	if(a=='J'&&b=='C')
	return -1;
	if(a=='J'&&b=='J')
	return 0;
	else return 0;
}
int main(){
	int N;
	map<char,int>mp;
	mp['B']=0;
	mp['C']=1;
	mp['J']=2;
	// b c j , s p f
	int a[6]={0};
	int b[6]={0};
	cin>>N;
	for(int i=0;i<N;i++){
		char ta,tb;
		cin>>ta>>tb;
		int res=isAwin(ta,tb);
		if(res==1){a[3]++;b[5]++;}else if(res==-1){a[5]++;b[3]++;}else {a[4]++;b[4]++;}
		if(res==1)
			a[mp[ta]]++;
		else 
			b[mp[tb]]++;
	}
	cout<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<endl;
	cout<<b[3]<<" "<<b[4]<<" "<<b[5]<<" "<<endl;
	int ma=0;
	for(int i=0;i<3;i++)
		if(a[i]>a[ma])ma=i;
	int mb=0;
	for(int i=0;i<3;i++)
		if(b[i]>b[mb])mb=i;
	char cm[3]={'B','C','J'};
	
	cout<<cm[ma]<<" "<<cm[mb]<<endl;
	
	return 0;
}
