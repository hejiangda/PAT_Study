// 给出一棵家谱树，找出每一层中没有孩子的结点个数
// 注意：不是二叉树！！而是普通的树
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
// book 记录每层没有孩子结点的结点个数
int book[100],maxdepth=-1;
void dfs(int index,int depth){
    // 如果 index 结点没有孩子
    if(v[index].size()==0){
        // 该结点所在层的结点个数加一
        book[depth]++;
        // 更新树的最大层数
        maxdepth = max(maxdepth,depth);
        return ;
    }
    // 对于每个结点，遍历其字节点
    for(int i=0;i<v[index].size();i++)
        // 遍历子结点时深度加一
        dfs(v[index][i],depth+1);
}

int main(){
    int n,m,k,node,c;
    // n 结点总数, m 非空结点个数
    scanf("%d %d",&n,&m);
    // 读入 m 个非空结点的 k 个孩子结点
    for(int i=0;i<m;i++){
        scanf("%d %d",&node,&k);
        // 将孩子结点存放在链表中
        for(int j=0;j<k;j++){
            scanf("%d",&c);
            v[node].push_back(c);
        }
    }
    // 遍历第一个结点，深度为零
    dfs(1,0);
    printf("%d",book[0]);
    // 输出每层没有孩子结点的结点个数
    for(int i=1;i<=maxdepth;i++)
        printf(" %d",book[i]);
    return 0;
}
