#include <iostream>

using namespace std;

int e[510][510];
int weight[510];
int dis[510];
int w[510]={0};
int num[510];
bool visited[510];
int n,m,c1,c2;
const int inf=99999999;
int main(){
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    fill(e[0],e[0]+510*510,inf);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        e[a][b]=e[b][a]=c;
    }
    fill(dis,dis+510,inf);
    dis[c1]=0;
    w[c1]=weight[c1];
    num[c1]=1;
    for(int i=0;i<n;i++){
        int u=-1,minn=inf;
        for(int j=0;j<n;j++){
            if(dis[j]<minn&&visited[j]==false){
                minn=dis[j];
                u=j;
            }
        }

        if(u==-1)break;
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(visited[v]==false&&e[u][v]!=inf){
                if(dis[u]+e[u][v]<dis[v]){
                    dis[v]=dis[u]+e[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }else if(dis[u]+e[u][v]==dis[v]){
                    num[v]=num[u]+num[v];
                    if(w[u]+weight[v]>w[v])
                    w[v]=w[u]+weight[v];
                }
            }
        }
    }
    cout<<num[c2]<<" "<<w[c2];
    return 0;
}
