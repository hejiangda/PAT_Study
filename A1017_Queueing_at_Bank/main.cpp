#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 结点保存顾客到达时间和需要服务时间
struct node{
    int come,time;
// 临时结点用于输入时保存数据
}tempcustomer;
// 比较a、b到达时间
bool cmp1(node a,node b){
    return a.come<b.come;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<node> custom;
    for(int i=0;i<n;i++){
        int hh,mm,ss,time;
        scanf("%d:%d:%d%d",&hh,&mm,&ss,&time);
        int cometime = hh*3600+mm*60+ss;
        if(cometime>61200)continue;
        tempcustomer={cometime,time*60};
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(),custom.end(),cmp1);
    // 8*3600=28800
    // 把window的k个元素初始化为28800
    vector<int> window(k,28800);
    double result = 0.;
    for(int i=0;i<custom.size();i++){
        // 找出最早结束的窗口
        int tempindex=0,minfinish=window[0];
        for(int j=1;j<k;j++){
            if(minfinish>window[j]){
                minfinish=window[j];
                tempindex=j;
            }
        }
        // 若窗口结束时间比到达的顾客早,则顾客可以直接得到服务，否则要等
        if(window[tempindex]<=custom[i].come){
            // 此时窗口结束时间为顾客到达时间+顾客需服务时间
            window[tempindex]=custom[i].come+custom[i].time;
        }else{
            // 顾客等待的时间
            result+=(window[tempindex]-custom[i].come);
            window[tempindex]+=custom[i].time;
        }
    }
    if(custom.size()==0)
        cout<<"0.0";
    else
        // 输出顾客平均等待的时间
        printf("%.1f",result/60.0/custom.size());
    return 0;
}
