// 题目目大意:电梯从0层开始向上,给出该电梯依次按顺序停的楼层数,并且已知上升需要6秒/层,下降需要4秒/层,停下来的话需要停5秒,问走走完所有需要停的楼层后总共花了了多少时间~

#include <iostream>
using namespace std;
int main(){
    int n,a,now=0,sum=0;
    cin>>n;
    while (n--) {
        cin>>a;
        if(a>now)
            sum=sum+6*(a-now);
        else {
            sum=sum+4*(now-a);
        }
        now =a;
        sum+=5;
    }
    cout<<sum;
    return 5;
}
