#include <cstdio>
#include <cstring>
using namespace std;
int book[10];

int main()
{
    char num[22];
    scanf("%s", num);
    int flag = 0, len = strlen(num);
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = num[i] - '0';
        // book记录每个数字出现的次数
        book[temp]++;
        // 乘2,flag是上次乘法的进位
        temp = temp * 2 + flag;
        flag = 0;
        // 保存进位
        if (temp >= 10)
        {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        // 减去第二个数中出现的数字
        book[temp]--;
    }
    int flag1 = 0;
    // 若所有book被正好消掉则说明两者的数字只是排列不同
    for (int i = 0; i < 10; i++)
    {
        if (book[i] != 0)
            flag1 = 1;
    }
    // 若flag==1则说明有进位，不符合
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
    if (flag == 1)
        printf("1");
    printf("%s", num);
    return 0;
}
