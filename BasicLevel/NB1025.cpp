#include <iostream>

using namespace std;

int main(){
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		double sum=a+b+c;
		double m=a;
		if(b>m)m=b;
		if(c>m)m=c;
		if(sum-m>m)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
