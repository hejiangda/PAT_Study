#include <iostream>
#include <algorithm>
#include <vector>
// 题目大意:给定一棵二叉树的后序遍历和中序遍历,请你输出其层序遍历的序列。这里假设键值都是
// 互不相等的正整数。
// 分析:与后序中序转换为前序的代码相仿(无须构造二叉树再进行广度优先搜索~),只不过加一个
// 变量index,表示当前根结点在二叉树中所对应的下标(从0开始),所以进行一次输出先序的递归的
// 时候,把节点的index和value放进结构体里,再装进容vector里,这样在递归完成后,vector中按照
// index排序就是层序遍历的顺序~
// 如果你不知道如何将后序和中序转换为先序,请看: https://www.liuchuo.net/archives/2090
using namespace std;
struct node
{
    int index, value;
};
bool cmp(node a, node b)
{
    return a.index < b.index;
}
vector<int> post, in;
vector<node> ans;
//           后序根，   中序起始，中序结尾，  层序序号
void pre(int root, int start, int end, int index)
{
    if (start > end)
        return;
    // 从中序起点开始查找
    int i = start;
    // 在中序遍历的数组中找到对应的根
    while (i < end && in[i] != post[root])
        i++;
    // 将当前结点在层序遍历中的序号以及该结点的值保存到结果数组中
    ans.push_back({index, post[root]});
    // 先序遍历左子树，该结点的左子树根的序号为 2×index+1
    // 左子树在后序中的根结点为root – (end – i + 1)
    // i为左子树的结点个数，end-i即右子树的结点个数，+1则是把根结点也算到右子树中，相减后就得到了左子树的根的位置
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    // 先序遍历右子树，该结点的右子树根的序号为 2×index+2
    // 后序遍历中右子树的根为 root-1
    pre(root - 1, i + 1, end, 2 * index + 2);

}
int main()
{
    int n;
    cin >> n;
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    pre(n - 1, 0, n - 1, 0);
    sort(ans.begin(), ans.end(), cmp);
    // 之所以用栈保存后再排序输出，是因为树不是完全二叉树，
    // 不能以数组下标来标识树结点的方式，来达到顺序输出层序序列的效果
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << ans[i].value;
    }
    return 0;
}
