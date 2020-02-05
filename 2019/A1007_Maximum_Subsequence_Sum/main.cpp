#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    // 声明一个长度为 n +
    vector<int> v(n);
    // 最终要返回的左右索引
    int leftindex=0,rightindex=n-1,
            sum=-1,temp=0,tempindex=0;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        // 累积
        temp = temp+v[i];
        // 若累积小于0则重置为0,将索引置为下一个
        if(temp<0){
            temp=0;
            tempindex=i+1;
        }else if(temp>sum){
            // 累积大于当前最大的和，则保存 tempindex 为左索引，右索引为当前索引
            sum = temp;
            leftindex=tempindex;
            rightindex=i;
        }
    }
    if(sum<0)sum=0;
    printf("%d %d %d",sum,v[leftindex],v[rightindex]);
    return 0;
}
