#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
// 城市结点总数
int n;
// 深搜
void dfs(int node){
    // 访问当前结点
    visit[node]=true;
    // 访问与该结点连通的各个结点
    for(int i=1;i<=n;i++){
        if(visit[i]==false&&v[node][i]==1)
            dfs(i);
    }
}
int main(){
    // m:剩余高速路
    // k:待检查的城市数
    int m,k,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a][b]=v[b][a]=1;
    }
    for(int i=0;i<k;i++){
        // 每个城市检查前需要把visit数组重置
        fill(visit,visit+1010,false);
        scanf("%d",&a);
        int cnt=0;
        // 把该城市置为true模拟城市被攻陷
        visit[a]=true;
        // 深搜求取连通分量数
        for(int j=1;j<=n;j++){
            if(visit[j]==false){
                dfs(j);
                cnt++;
            }
        }
        // 把n个连通分量连通需要n-1条边
        printf("%d\n",cnt-1);
    }
    return 0;
}
