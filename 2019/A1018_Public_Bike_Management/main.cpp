#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 无穷大值
const int inf=99999999;
// cmax：自行车站最大容量，n：站点总数，sp：问题站点的序号，m：路的条数
int cmax,n,sp,m;
// minNeed：需要从原点带的最少的自行车数，minBack：在路上捡的最少自行车数
int minNeed=inf,minBack=inf;
// e：图，dis：原点到某结点的距离，weight：站点当前与cmax/2相比多出的与缺少的自行车数量
int e[510][510],dis[510],weight[510];
// visit：标记Dijkstra最短路算法中访问过的结点
bool visit[510];
// 记录某结点的最短前驱结点
vector<int> pre[510];
vector<int> path,temppath;
void dfs(int v){
    // 记录从问题结点开始的路径
    temppath.push_back(v);
    // 访问到原点后开始处理路径
    if(v==0){
        // need：需要从原点带的自行车，back：路中拾取的多余自行车
        int need=0,back=0;
        // temppath保存的路径是倒着的，temppath.size()-1即原点、0即问题点
        for(int i=temppath.size()-1;i>=0;i--){
            int id=temppath[i];
            // 结点的自行车比理想值多了
            if(weight[id]>0){
                back+=weight[id];
            }else {
                // 已经拾取的自行车比结点缺少的多
                if(back>(0-weight[id])){
                    // 把自行车分给结点
                    back+=weight[id];
                }else{
                    // 已经拾取的自行车比结点缺少的少
                    // 需要从原点带去自行车
                    need += ((0-weight[id])-back);
                    back=0;
                }
            }
        }
        // 找到需要从原点带自行车数量最少的路径
        if(need<minNeed){
            minNeed=need;
            minBack=back;
            path=temppath;
        }else if(need==minNeed&&back<minBack){
            // 若从原点带的数量一致,找到在路上需要捡自行车最少的路径
            minBack=back;
            path=temppath;
        }
        // 弹出当前的结点
        temppath.pop_back();
        return;
    }
    // 依次遍历问题结点的最短前驱结点
    for(int i=0;i<pre[v].size();i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main()
{
    // 图各结点间距初始化为无穷大
    fill(e[0],e[0]+510*510,inf);
    fill(dis,dis+510,inf);
    cin>>cmax>>n>>sp>>m;
    // 第i个站点当前拥有的自行车数量
    for(int i=1;i<=n;i++){
        cin>>weight[i];
        // 第i个站点当前与cmax/2相比多出的与缺少的自行车数量
        weight[i]=weight[i]-cmax/2;
    }
    // 两个结点间的距离
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cin>>e[a][b];
        e[b][a]=e[a][b];
    }
    // Dijkstra 最短路径算法
    dis[0]=0;
    for(int i=0;i<=n;i++){
        // u：待选择的结点，minn：找出到原点距离最短的距离
        int u=-1,minn=inf;
        // 从未遍历的点中找出一个到原点距离最短的点
        for(int j=0;j<=n;j++){
            if(visit[j]==false&&dis[j]<minn){
                u=j;
                minn=dis[j];
            }
        }
        // 全部遍历了则退出
        if(u==-1)break;
        // 访问结点u
        visit[u]=true;
        for(int v=0;v<=n;v++){
            // 遍历与u相邻的结点
            if(visit[v]==false&&e[u][v]!=inf){
                // 若从原点经过u到v比直接到v距离短
                if(dis[v]>dis[u]+e[u][v]){
                    // 更新原点到v的距离
                    dis[v]=dis[u]+e[u][v];
                    // 清空到v点的前驱结点，因为现在从u到v是最短的嘛
                    pre[v].clear();
                    // 把u加到v的前驱结点中
                    pre[v].push_back(u);
                }else if(dis[v]==dis[u]+e[u][v]){
                    // 当直接到v的距离与经u到v的距离相等，
                    // 说明又多了一个到v距离最小的前驱结点
                    pre[v].push_back(u);
                }
            }
        }
    }
    // 对问题结点进行遍历
    dfs(sp);
    cout<<minNeed<<" 0";
    for(int i=path.size()-2;i>=0;i--)
        cout<<"->"<<path[i];
    cout<<" "<<minBack;
    return 0;
}
