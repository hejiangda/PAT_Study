/******************************************************************************
 * A1001.A+B Format (20) 字符串处理
 * Calculate a+b and output the sum in standard format -- that is, the digits
 * must be separated into groups of three by commas (unless there are less than
 * four digits).
 *
 * Input
 *
 * Each input file contains one test case. Each case contains a pair of integers
 * a and b where -1000000 <= a, b<=1000000. The numbers are separated by a space.
 *
 * Output
 *
 * For each test case, you should output the sum of a and b in one line. The sum
 * must be written in the standard format.
 *
 * Sample input
 *
 * -1000000 9
 *
 * Sample Output
 *
 * -999,991
 *****************************************************************************/
/******************************************************************************
 * 题目大意：计算 A+B 的和，输出时每三位输出一个逗号
 * 分析：把 A+B 的结果转化成字符串，除了第一个负号外只要当前位的下标满足 (i+1)%3==len%3
 * 且 i 不是最后一位，就在逐位输出的时候在该位输出的后面加上一个逗号。
 *****************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    string s= to_string(a+b);
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        cout << s[i];
        // 如果当前位是‘-’则跳过输出逗号的过程
        if(s[i] == '-')continue;
        // 不考虑负号，假设一个7位数1,000,000中间有两个逗号
        // i=0时，(i+1)%3=1 7%3=1
        // 换句话说，7位数需要两个逗号-->7/3=2
        //      7位数第一个逗号的位置-->7%3=1
        // i+1 即为当前位已经输出，在输出下一位时判断是否要输出逗号
        if((i+1)%3==len%3 && i!=len-1)cout<<",";
    }
    return 0;
}
