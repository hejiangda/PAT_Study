#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node{
    // 队首出队时间 队尾出队时间
    int poptime,endtime;
    queue<int> q;

};

int main(){
    // n：窗口数，m：黄线前最大容量，k：顾客数，Q：顾客请求数
    int n,m,k,q,index=1;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    vector<int> time(k+1),result(k+1);
    // 接待顾客花费时间
    for(int i=1;i<=k;i++){
        scanf("%d",&time[i]);
    }
    vector<node> window(n+1);
    vector<bool> sorry(k+1,false);
    // 把每个窗口黄线前的m个顾客分配到n个窗口
    for(int i=1;i<=m;i++){
        // i=1即每个窗口第一位顾客，i=2即每个窗口第二个顾客……
        for(int j=1;j<=n;j++){
            // index超过k就不是用户了
            if(index<=k){
                window[j].q.push(time[index]);
                // 结束时间超过540分钟（从8点算起，9个小时后是17点）则不提供服务
                if(window[j].endtime>=540)
                    sorry[index]=true;
                // 结束时间加上当前入队的顾客的服务时间
                window[j].endtime+=time[index];
                // 窗口排第一位的顾客服务结束的时间就是队首出队的时间
                if(i==1)
                    window[j].poptime=window[j].endtime;
                // 保存每个顾客服务结束的时间
                result[index]=window[j].endtime;
                index++;
            }
        }
    }
    // 黄线后排队的顾客
    while(index<=k){
        // 找到队首出队时间最短的窗口
        int tempmin=window[1].poptime,tempwindow=1;
        for(int i=2;i<=n;i++){
            if(window[i].poptime<tempmin){
                tempwindow=i;
                tempmin=window[i].poptime;
            }
        }
        // 窗口出队后让黄线外的顾客入队
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        // 更新队首出队时间为新队首的出队时间
        window[tempwindow].poptime+=window[tempwindow].q.front();
        if(window[tempwindow].endtime>=540)
            sorry[index]=true;
        window[tempwindow].endtime+=time[index];
        result[index]=window[tempwindow].endtime;
        index++;
    }
    // 对于顾客们的q次查询进行回复
    for(int i=1;i<=q;i++){
        int query,minute;
        scanf("%d",&query);
        minute=result[query];
        if(sorry[query]==true){
            printf("Sorry\n");
        }else{
            // 8×60=480分钟
            printf("%02d:%02d\n",(minute+480)/60,(minute+480)%60);
        }
    }
    return 0;
}
