#include <iostream>
using namespace std;
int main(){
    int n1,n2,a,cnt=0;
    scanf("%d",&n1);
    double b,arr[1001]={0.0},ans[2010]={0.0};
    // 保存第一个数
    for(int i=0;i<n1;i++){
        scanf("%d %lf",&a,&b);
        arr[a]=b;
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d %lf",&a,&b);
        for(int j=0;j<1001;j++){
            // 每得到一位数与第一个数的每个数字进行计算，指数相加，乘数相乘
            ans[j+a]+=arr[j]*b;
        }
    }
    for(int i=2000;i>=0;i--)
        if(ans[i]!=0.0)cnt++;
    printf("%d",cnt);
    for(int i=2000;i>=0;i--)
        if(ans[i]!=0.0)
            printf(" %d %.1f",i,ans[i]);
    return 0;
}
