/******************************************************************************
 * A1002.A+B for Polynomials(25)模拟
 * This time, you are supporsed to find A+B where A and B are two polynomials.
 *
 * Input
 *
 * Each input file contains one test case. Each case occupies 2 lines, and each
 * line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK,
 * where K is the number of nonzero terms in the polynomial, Ni and aNi(i=1,2,
 * ...,K) are the exponents and coefficients, respectively. It is given that 1<=
 * K<=10, 0<=NK<...<N2<N1<=1000.
 *
 * Output
 *
 * For each test case you should output the sum of A and B in one line, with the
 * same format as the input. Notice that tere must be NO extra space at the end
 * of each line. Please be accurate to 1 decimal place.
 *
 * Sample Input
 *
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 *
 * Sample Output
 *
 * 3 2 1.5 1 2.9 0 3.2
 *****************************************************************************/
/******************************************************************************
 * 计算多项式 A+B 的和
 * 分析：设立一个数组 c 并初始化为 0，长度为多项式指数的最大值，将输入的 A 和 B 分别按其每位
 * 的指数加到对应的 c[i] 中，输出时从后向前依次输出多项式的指数和系数
 *****************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    float c[1001]={0};
    int m,n,t;
    float num;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%f",&t,&num);
        c[t]+=num;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%f",&t,&num);
        c[t]+=num;
    }
    int cnt=0;
    for(int i=0;i<1001;i++)
    {
        if(c[i]!=0)cnt++;
    }
    printf("%d",cnt);
    for(int i=1000;i>=0;i--)
    {
        if(c[i]!=0)
            printf(" %d %f",i,c[i]);
    }
    return 0;
}
