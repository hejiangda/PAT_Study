#include <iostream>

using namespace std;

int main()
{
    // 通过哈希表的方式把13个数字映射到0～C上，这样就可以直接根据除法得到的数字来输出了。
    char c[14] = {"0123456789ABC"};
    cout << "#";
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        cout << c[num / 13] << c[num % 13];
    }
    return 0;
}
