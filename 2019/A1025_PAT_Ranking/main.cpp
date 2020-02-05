#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 用结构体保存考生的数据
struct student
{
    // id 用 long long 存 long long 范围-(2^63) to (2^63)-1
    // 19位 可以表示18位以内任意数
    // int 范围 -2,147,483,648 to 2,147,483,647
    // 10位 可以表示任意9位以内数
    long long no;
    int score, finrank, loca, locarank;
};
// 比较函数，用三目运算符简化表达式
// 从大到小 return a>b
// 从小到大 return a<b
bool cmp1(student a, student b)
{
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main()
{
    int n, m;
    cin >> n;
    // 所有的考生
    // 首先按照每个考场把整场排名保存到fin中
    // 之后再对其排序得到全局排名
    vector<student> fin;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        vector<student> v(m);
        // 读入该场所有考生数据
        for (int j = 0; j < m; j++)
        {
            cin >> v[j].no >> v[j].score;
            v[j].loca = i;
        }
        // 该场考生按分数考号排序
        sort(v.begin(), v.end(), cmp1);
        // 第一名的本地排名设为1
        v[0].locarank = 1;
        fin.push_back(v[0]);
        // 剩下的m-1个考生依次计算排名（排名相同的名次一致，不同的为所在位置+1）
        for (int j = 1; j < m; j++)
        {
            v[j].locarank = (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : (j + 1);
            // 保存到总考生序列中
            fin.push_back(v[j]);
        }
    }
    // 对所有考生排序
    sort(fin.begin(), fin.end(), cmp1);
    fin[0].finrank = 1;
    for (int j = 1; j < fin.size(); j++)
        fin[j].finrank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finrank) : (j + 1);
    cout << fin.size() << endl;
    for (auto x : fin)
    {
        printf("%013lld %d %d %d\n", x.no, x.finrank, x.loca, x.locarank);
    }

    return 0;
}
