#include <iostream>

using namespace std;

int main()
{
    // a为十进制下的数，b为要转换的基数
    int a,b;
    cin>>a>>b;
    // arr数组用来保存每一个数位的数据，数组大小设为40应该是考虑到2^32有32位吧
    // index用以记录数位个数，同时若a为0则index不变还是为0,可以通过这个来判断输入的是不是0
    int arr[40],index=0;
    while(a!=0){
        arr[index++]=a%b;
        a=a/b;
    }
    // flag用来标记判断的结果
    int flag=0;
    // 判断回文数，从数字的两头同时向中间两两对比
    for(int i=0;i<index/2;i++){
        if(arr[i]!=arr[index-i-1]){
            cout<<"No\n";
            flag=1;
            break;
        }
    }
    if(!flag)cout<<"Yes\n";
    for(int i=index-1;i>=0;i--){
        cout<<arr[i];
        if(i!=0)cout<<" ";
    }
    if(index==0)
        cout<<"0";
    return 0;
}
