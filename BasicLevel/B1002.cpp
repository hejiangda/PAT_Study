#include <iostream>

using namespace std;
int A[6];
bool sign[6];
//A1 = 能被5整除的数字中所有偶数的和； 被5整除 偶数
//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；被5除后余1 交错求和
//A3 = 被5除后余2的数字的个数； 被5除后余2
//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；被5除后余3的数字的平均数
//A5 = 被5除后余4的数字中最大数字。余4的数字中最大数字
int main(){
	int n;
	cin>>n;
	int a4n=0;
	int a2sign=1;
	for(int i=0;i<n;i++){
		int tmp,m;
		cin>>tmp;
		m=tmp%5;
		switch(m){
			case 0:if(int(tmp&1)==0){A[1]+=tmp;
			sign[1]=true;}
			break;
			case 1:A[2]+=a2sign*tmp;a2sign=-a2sign;
			sign[2]=true;
			break;
			case 2:A[3]++;
			sign[3]=true;
			break;
			case 3:A[4]+=tmp;a4n++;
			sign[4]=true;
			break;
			case 4:if(tmp>A[5])A[5]=tmp;
			sign[5]=true;
			break;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(sign[i])
		cout<<A[i]<<" ";
		else cout<<"N"<<" ";
	}
	if(a4n)
		printf("%.1f",double(A[4])/a4n);
	else cout<<"N";
	cout<<" ";
	if(sign[5])
	cout<<A[5]<<endl;
	else cout<<"N"<<endl;
	return 0;
}
