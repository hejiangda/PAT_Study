// 给出一个非负整数，对每一位求和，用英文按位输出结果
//
#include <iostream>
using namespace std;
int main(){
    string a;
    cin >> a;
    int sum =0;
    for(int i=0;i<a.length();i++)
        sum+=(a[i]-'0');
    // to_string()将其他类型转化为字符串
    string s = to_string(sum);
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout<<arr[s[0]-'0'];
    for(int i=1;i<s.length();i++)
        cout<<" "<<arr[s[i]-'0'];
    return 0;
}
