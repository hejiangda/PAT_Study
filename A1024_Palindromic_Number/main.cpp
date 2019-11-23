#include <iostream>
#include <algorithm>
using namespace std;
string s;
// 两个位数一样的顺序相反的数字相加
void add(string t)
{
    int len = s.length(), carry = 0;
    // s[0]是字符串的第一个字符
    // 相加的顺序是从最前到最后（左边最先加）
    // 因为两个加数的顺序是相反的，所以可以这样加
    for (int i = 0; i < len; i++)
    {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        // 进位
        if (s[i] > '9')
        {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if (carry)
        s += '1';
    // 逆转回正确的顺序
    reverse(s.begin(), s.end());
}
int main()
{
    int cnt, i;
    cin >> s >> cnt;
    for (i = 0; i <= cnt; i++)
    {
        string t = s;
        // 临时字符串逆转
        reverse(t.begin(), t.end());
        if (s == t || i == cnt)
            break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}
