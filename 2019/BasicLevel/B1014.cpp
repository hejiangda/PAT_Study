#include <iostream>
#include <cstdio>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    //char num1[10010],num2[10010];
    char flag1[4],flag2[4];
    char zheng[4];
    char xiao[10010];
    char wei[10];
    scanf("%[+-]%[1-9].%[0-9]E%[+-]%[0-9]",flag1,zheng,xiao,flag2,wei );
    //printf("%s * %s * %s * %s * %s",flag1,zheng,xiao,flag2,wei );
    string num=xiao;
    int mi;
    sscanf(wei,"%d",&mi);
    num.insert(num.begin(),zheng[0]);
    //cout << num<<endl;

    if(flag2[0]=='+'){
        int n=num.size();
        while(num.size()<mi+1){
            num.push_back('0');
        }
        if(num.size()>mi+1)
        {
			num.insert(num.begin()+mi+1,'.');
            //num[mi+1]='.';num.push_back('0');
            
        }
    }else if(flag2[0]=='-'){
        int n=num.size();
        while(num.size()<mi+n){
            num.insert(num.begin(),'0');
        }
        num.insert(num.begin()+1,'.');
    }
    if(flag1[0]=='-')
    num.insert(num.begin(),flag1[0]);
    cout<<num<<endl;
    return 0;
}
