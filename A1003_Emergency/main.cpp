#include <iostream>
#include <algorithm>
using namespace std;
int n,m,c1,c2;
// e[i][j]表示图中某边的权，i和j分别为结点
// dis[i]表示从出发点到i结点最短路径的路径⻓度
// num[i]表示从出发点到i结点最短路径的条数
// w[i]表示从出发点到i点救援队的数⽬之和
int e[510][510],weight[510],dis[510],num[510],w[510];
bool visit[510];
const int inf = 99999999;
int main(){
    // 读入数据
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++)
        // 该城市救援队的数目
        scanf("%d",&weight[i]);
    // Assigns the given value to the elements in the range [first, last).
    // 对边和距离初始化为无穷大
    fill(e[0],e[0]+510*510,inf);
    fill(dis,dis+510,inf);

    int a,b,c;
    // m 条公路的权
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=e[b][a]=c;
    }
    // 起点
    dis[c1]=0;
    w[c1]=weight[c1];
    num[c1]=1;
    // 每次循环访问一个点
    // 每次访问距离源点最短的那个点,
    // 之后把与这个点相连的点访问一遍,
    // 若通过 u 到 v 比直接到 v 距离短
    // 更新距离及救援队伍数
    // 最短路条数与源点到 u 一样
    // 若距离相等则说明可以直接到 v 或者经 u 到 v
    // 源点到 v 的路多了一条
    for(int i=0;i<n;i++){
        int u=-1,minn=inf;
        // 在没访问过的结点中找出到出发点路程最短的结点
        for(int j=0;j<n;j++){
            if(visit[j]==false&&dis[j]<minn){
                u=j;
                minn=dis[j];
            }
        }
        // 全部遍历过了则结束
        if(u==-1)break;
        // 访问u结点
        // Dijkstra
        visit[u]=true;

        for(int v=0;v<n;v++){
            if(visit[v]==false&&e[u][v]!=inf){
                // 若源点经过 u 到 v 的距离比源点直接到 v 短
                if(dis[u]+e[u][v]<dis[v]){
                    // 更新源点到 v 的距离
                    dis[v]=dis[u]+e[u][v];
                    // 最短路条数与源点到 u 一样
                    num[v]=num[u];
                    // 加上 v 点的救援队伍
                    w[v]=w[u]+weight[v];
                    // 若距离相等则说明可以直接到 v 或者经 u 到 v
                }else if(dis[u]+e[u][v]==dis[v]){
                    // 从源点到 v 的路条数加上从源点到 u 的条数
                    num[v]=num[v]+num[u];
                    // 加上 v 点的救援队伍
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v];
                }
            }
        }
    }
    // 输出最短路径条数，和救援队伍之和
    printf("%d %d",num[c2],w[c2]);
    return 0;
}
