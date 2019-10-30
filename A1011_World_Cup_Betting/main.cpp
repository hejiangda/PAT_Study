#include <iostream>
using namespace  std;
int main(){
    // 用字符数组标记各类别
    char c[4]={"WTL"};
    // 结果的积，边输入边处理
    double ans=1.0;
    for(int i=0;i<3;i++){
        double maxvalue = 0.0;
        int maxchar=0;
        // 找出每行最大的数以及类型
        for(int j=0;j<3;j++){
            double temp;
            scanf("%lf",&temp);
            if(maxvalue<=temp){
                maxvalue=temp;
                maxchar=j;
            }
        }
        // 乘积
        ans*=maxvalue;
        // 打印类型
        printf("%c ",c[maxchar]);
    }
    // 计算结果
    printf("%.2f",(ans*.65-1)*2);
    return 0;
}
