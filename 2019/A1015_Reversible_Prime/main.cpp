#include <iostream>
#include <cmath>
using namespace std;
// 判断素数，n不能被从2到根号n的数整除
bool isprime(int n){
    if(n<=1)return false;
    int sqr = int(sqrt(n*1.));
    for(int i=2;i<=sqr;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n,d;
    // 循环输入直到EOF的模板
    while(scanf("%d",&n)!=EOF){
        if(n<0)break;
        scanf("%d",&d);
        if(isprime(n)==false){
            printf("No\n");
            continue;
        }
        // 将数字n转换为d进制
        int len = 0,arr[100];
        do{
            arr[len++]=n%d;
            n=n/d;
        }while(n!=0);
        // 求和得到逆转后的n
        for(int i=0;i<len;i++)
            n=n*d+arr[i];
        // 判断逆转后的n是不是素数
        printf("%s",isprime(n)?"Yes\n":"No\n");
    }
    return 0;
}
