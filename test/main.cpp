// N
// M
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> t[110];
int maxdepth=-1;
bool visit[110];
int height[110];
void dfs(int node,int depth){
    if(!visit[node]){
        visit[node]=true;
        if(t[node].size()==0){
            height[depth]++;
        }else{
            for(int i=0;i<t[node].size();i++){
                dfs(t[node][i],depth+1);
            }
        }
        maxdepth=max(depth,maxdepth);
    }

}
int main(){
    int n,m,node,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>node>>k;
        for(int j=0;j<k;j++){
            int tmp;
            cin>>tmp;
            t[node].push_back(tmp);
        }
    }
    dfs(1,0);
    cout<<height[0];
    for(int i=1;i<=maxdepth;i++){
        cout<<" "<<height[i];
    }
}
