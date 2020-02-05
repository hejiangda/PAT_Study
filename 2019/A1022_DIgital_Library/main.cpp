#include <iostream>
#include <map>
#include <set>

using namespace std;
// 通过map将标题、作者等与书的id号关联起来，通过set可以去重，把每个类目符合的id保存
map<string, set<int> >title, author, key, pub, year;
// 通过map和set来查询
void query(map<string, set<int> >& m, string& str)
{
    // 若没有找到，若在容器中find没有找到则默认返回end迭代器
    if (m.find(str) != m.end())
    {
        // 容器遍历的标准写法
        for (auto it = m[str].begin(); it != m[str].end(); it++)
            // 打印出该字符串对应的所有书的id
            printf("%07d\n", *it);
    }
    else
    {
        cout << "Not Found\n";
    }
}
int main()
{
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &id);
        // c++中读取整行字符串给string
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while (cin >> tkey)
        {
            key[tkey].insert(id);
            // 通过判断有无读到\n来判断是否把关键字读完
            char c = getchar();
            if (c == '\n')
                break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << endl;
        switch (num)
        {
            case 1 :
                query(title, temp);
                break;
            case 2:
                query(author, temp);
                break;
            case 3:
                query(key, temp);
                break;
            case 4:
                query(pub, temp);
                break;
            case 5:
                query(year, temp);
                break;
        }
    }
    return 0;
}
