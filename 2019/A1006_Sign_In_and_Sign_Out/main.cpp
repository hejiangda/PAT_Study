// 题目目大大意:给出n个人的id、sign in时间、sign out时间,求最早进来的人和最早出去的人的ID~
// 一道求最大值最小值的题目
#include <iostream>
#include <climits>

using namespace std;
int main(){
    int n,minn = INT_MAX,maxn=INT_MIN;
    scanf("%d",&n);
    string unlocked,locked;
    for (int i=0;i<n;i++) {
        string t;
        cin >> t;
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2*3600+m2*60+s2;
        if(tempIn<minn){
            minn = tempIn;
            unlocked=t;
        }
        if(tempOut>maxn){
            maxn=tempOut;
            locked=t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
