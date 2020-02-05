#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
// n个结点，maxheight记录深搜得到的最大高度
int n, maxheight = 0;
// v是邻接表，用来存储图
vector<vector<int>>v;
// 判断结点有无访问过
bool visit[10010];
// set可以去重，因此两次dfs得到的相同的结点只会保存一次
set<int> s;
// temp用来保存高度最高的根
vector<int> temp;
void dfs(int node, int height)
{
    // 当前结点的高度最高
    if (height > maxheight)
    {
        // 清空temp，以前的结点都作废
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    }
    // 当前的结点和当前最高的树一样高
    else if (height == maxheight)
    {
        // 添加进temp
        temp.push_back(node);
    }
    visit[node] = true;
    // 深度遍历
    for (int i = 0; i < v[node].size(); i++)
    {
        if (visit[v[node][i]] == false)
            // 该结点的子树的高度为自己高度加1
            dfs(v[node][i], height + 1);
    }
}
int main()
{
    cin >> n;
    // 图结点从1开始
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    // 将边存储在邻接表中
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // 遍历图，数出图的连通分量数
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i, 1);
            // 先从一个结点dfs后保留最高高度拥有的结点们
            if (i == 1)
            {
                // s中存放最高的根结点
                // s1放第一个最高根
                if (temp.size() != 0)
                    s1 = temp[0];
                for (int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            // 连通分量数
            cnt++;
        }
    }
    if (cnt >= 2)
    {
        cout << "Error: " << cnt << " components";
    }
    else
    {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        // 第二次遍历，以某个最高根开始
        dfs(s1, 1);
        // 这次得到的最高根和第一次得到的最高根的并集为答案
        // set可以去重！
        for (int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);
        for (auto it = s.begin(); it != s.end(); it++)
            cout << *it << endl;
    }
    return 0;
}
