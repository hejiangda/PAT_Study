#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
// 将字符串n表示的数字转换成radix进制下的数字
long long convert(string n,long long radix){
    long long sum = 0;
    int index = 0,temp=0;
    // rbegin 指向向量反转后的头，rend指向向量反转后的尾，就是反方向的 begin 和end
    for(auto it = n.rbegin();it!=n.rend();it++){
        // 将字符转换为十进制中的数字
        temp = isdigit(*it)?*it-'0':*it-'a'+10;
        // 从后往前迭代每位相加
        sum+=temp*pow(radix,index++);
    }
    return sum;
}
long long find_radix(string n,long long num){
    // max_element 找出最大的元素的迭代器
    char it=*max_element(n.begin(),n.end());
    // 找到的最大的数就是两个数，至少是这么大的进制
    long long low=(isdigit(it)?it-'0':it-'a'+10)+1;
    // 设定最大进制的范围
    long long high=max(num,low);
    // 将未知进制的数字的进制从low到high之间二分查找，转换为十进制数字进行判断
    while(low<=high){
        long long mid=(low+high)/2;
        // 将数字按mid进制转换
        long long t=convert(n,mid);
        // t大于已知数，说明进制上限太大了，设置为mid-1
        if(t<0||t>num)high=mid-1;
        else if(t==num)return mid;
        else low=mid+1;
    }
    return -1;
}
int main(){
    string n1,n2;
    long long tag=0,radix=0,result_radix;
    cin >> n1>>n2>>tag>>radix;
    result_radix=tag==1?find_radix(n2,convert(n1,radix)):find_radix(n1,convert(n2,radix));
    if(result_radix!=-1){
        printf("%lld",result_radix);
    }else{
        printf("Impossible");
    }
    return 0;
}
