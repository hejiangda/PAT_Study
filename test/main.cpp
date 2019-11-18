// n windows n lines
// m customers a line
// yellow line
// nm+1 ... wait in a line behind
// customer choose shortest line & smallest number
// customer i take ti minutes
// first n customers are served at 8.am

// given processing time pre customer
// tell the exact time a customer has done

// input: n,m,k,q
// n window num
// m max capacity pre line inside yellow line
// k customers number
// q customer queries

// The customers are numbered from 1 to K.

// output: for q customers print finished time
// HH:MM
// customers who cannot be served before 17. output Sorry
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct window
{
    queue<int> q;
    int firstTime;
    int lastTime;
    window()
    {
        firstTime = 0;
        lastTime = 0;
    }
};
int cusTime[1010];
bool sorry[1010];
int cusQuit[1010];
window win[25];

int main()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        cin >> cusTime[i];
    }
    int index = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (index <= k)
            {
                win[j].q.push(index);
                if (win[j].lastTime >= 9 * 60)
                {
                    sorry[index] = true;
                }
                win[j].lastTime += cusTime[index];
                cusQuit[index] = win[j].lastTime;
                if (i == 1)
                {
                    win[j].firstTime += cusTime[index];
                }
            }
            index++;
        }
    }
    for (int i = index; i <= k; i++)
    {
        int minn = 1;
        for (int j = 2; j <= n; j++)
        {
            if (win[j].firstTime < win[minn].firstTime)
            {
                minn = j;
            }
        }
        win[minn].q.pop();
        win[minn].firstTime += cusTime[win[minn].q.front()];
        win[minn].q.push(i);
        if (win[minn].lastTime >= 9 * 60)
        {
            sorry[i] = true;
        }
        win[minn].lastTime += cusTime[i];
        cusQuit[i] = win[minn].lastTime;
    }
    for (int i = 0; i < q; i++)
    {
        int tmp;
        cin >> tmp;
        int minutes = cusQuit[tmp];
        if (sorry[tmp])
        {
            cout << "Sorry\n";
        }
        else
        {
            printf("%02d:%02d\n", (minutes + 8 * 60) / 60, (minutes + 8 * 60) % 60);
        }
    }
    return 0;
}
