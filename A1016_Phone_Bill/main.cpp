#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// 用结点结构体记录用户的姓名状态和打电话的起止时间
struct node{
    string name;
    int status,month,time,day,hour,minute;
};
// sort()函数所需的比较函数，用 ? : 表达式可以方便地表示判断语句
bool cmp(node a,node b){
    return a.name!=b.name?
                a.name<b.name:
                a.time<b.time;
}
// 计算从0天0时0分开始打电话到目前时间的花费
double billFromZero(node call,int* rate){
    double total = rate[call.hour]*call.minute+ rate[24]*60*call.day;
    for(int i=0;i<call.hour;i++)
        total+=rate[i]*60;
    // 单价是按 美分/分钟 计算的要换算成 美元
    return total/100.0;
}
int main(){
    // 前0～23记录每个时间段的费率，24记录打一整天电话的费率
    int rate[25]={0},n;
    for(int i=0;i<24;i++){
        scanf("%d",&rate[i]);
        rate[24]+=rate[i];
    }
    scanf("%d",&n);
    // n条数据
    vector<node> data(n);
    // 输入每条记录
    for(int i=0;i<n;i++){
        cin>>data[i].name;
        scanf("%d:%d:%d:%d",
              &data[i].month,
              &data[i].day,
              &data[i].hour,
              &data[i].minute);
        // 在线离线状态
        string temp;
        cin>>temp;
        data[i].status=(temp == "on-line")?1:0;
        // 计算从0天0时0分开始的绝对时间
        data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;
    }
    // 排序，先按名称再按时间排序
    sort(data.begin(),data.end(),cmp);
    // 用map将顾客通话记录映射到顾客名上
    map<string,vector<node> > custom;
    for(int i=1;i<n;i++){
        // 通话记录配对
        if(data[i].name==data[i-1].name && data[i-1].status== 1 && data[i].status==0){
            custom[data[i-1].name].push_back(data[i-1]);
            custom[data[i].name].push_back(data[i]);

        }
    }
    // Range-based for loop (since C++11)
    // for遍历的新写法，it为custom中的每个元素
    // 遍历每个顾客
    for(auto it:custom){
        vector<node> temp = it.second;
        // 输出顾客姓名
        cout<<it.first;
        // 输出电话账单月份
        printf("%02d\n",temp[0].month);
        // 总金额
        double total = 0.0;
        // 每次取一对进行计算账单
        for(int i=1;i<temp.size();i+=2){
            // 计算从0开始打电话需要的金额，两者互减可以得到本次通话的金额
            double t = billFromZero(temp[i],rate) - billFromZero(temp[i-1],rate);
            // 输出本次的通话起止时间和金额
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].minute,temp[i].day,temp[i].hour,temp[i].minute,temp[i].time-temp[i-1].time,t);
            // 累积得到总金额
            total+=t;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}
