#include <iostream>

using namespace std;

int main(){
	string a,b;
	char da,db;
	cin>>a>>da>>b>>db;
	long long pa=0,pb=0;
	int lena=a.length();
	for(int i=0;i<lena;i++){
		if(a[i]==da){
			pa*=10;
			pa+=(long long)(da-'0');
		}
	}
	int lenb=b.length();
	for(int i=0;i<lenb;i++){
		if(b[i]==db){
			pb*=10;
			pb+=(long long)(db-'0');
		}
	}
	cout<<pa+pb;
	return 0;
}
