#include <iostream>
using namespace std;

int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int l1=a.length()>b.length()?b.length():a.length();
	int l2=c.length()>d.length()?d.length():c.length();
	int sign=0;
	string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	for(int i=0;i<l1;i++){
		if(sign==0&&a[i]==b[i]&&isupper(a[i])){
			sign=1;
			cout<<week[int(a[i]-'A')]<<" ";
		}
		else if(sign==1&&a[i]==b[i]&&(isdigit(a[i])||(a[i]>='A'&&a[i]<='N'))){
			sign=2;
			if(isdigit(a[i])){
				cout<<"0"<<a[i]<<":";
			}
			else cout<<int(a[i]-'A')+10<<":";
			break;
		}
	}
	for(int i=0;i<l2;i++){
		if(c[i]==d[i]&&isalpha(c[i])){
			printf("%02d",i);
			break;
		}
	}
	return 0;
}
