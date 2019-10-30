#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int id,best;
    int score[4],rank[4];
}stu[2005];
// 用10^6数组来进行散列，记录排名
int exist[1000000],flag=-1;
// 比较函数，通过全局变量flag来控制对哪个数据进行比较
bool cmp1(node a,node b){
    return a.score[flag]>b.score[flag];
}
int main(){
    int n,m,id;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        // 计算平均数，并+.5来进行四舍五入
        stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0+.5;
    }
    for(flag=0;flag<=3;flag++){
        sort(stu,stu+n,cmp1);
        stu[0].rank[flag]=1;
        for(int i=1;i<n;i++){
            // 排序填名次
            stu[i].rank[flag]=i+1;
            if(stu[i].score[flag]==stu[i-1].score[flag])
                stu[i].rank[flag]=stu[i-1].rank[flag];
        }
    }
    for(int i=0;i<n;i++){
        // 哈希表保存该学号对应的数组下标,+1是为了区分不存在的结点
        exist[stu[i].id]=i+1;
        stu[i].best=0;
        // 找出排名最靠前的
        int minn=stu[i].rank[0];
        for(int j=1;j<=3;j++){
            if(stu[i].rank[j]<minn){
                minn=stu[i].rank[j];
                stu[i].best=j;
            }
        }
    }
    char c[5]={'A','C','M','E'};
    for(int i=0;i<m;i++){
        scanf("%d",&id);
        int temp=exist[id];
        if(temp){
            int best = stu[temp-1].best;
            printf("%d %c\n",stu[temp-1].rank[best],c[best]);
        }else{
            printf("N/A\n");
        }
    }
    return 0;
}
