#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
vector<int> dx;
vector<int> dy;
bool vis[101][101];

int kx[]={1,-1,1,-1};
int ky[]={1,-1,-1,1};
void pre()
{
    for(int i=0;i<=50;i++)
        for(int j=0;j<=50;j++)
        {
            if(i==0&&j==0) continue;
            int z = (i*i+j*j);
            if(sqrt(z)*sqrt(z)==z)
            {
                dx.push_back(i);
                dy.push_back(j);
            }
        }
    for(int i=1;i<=50;i++)
    {
        dx.push_back(i);
        dy.push_back(0);
        dx.push_back(0);
        dy.push_back(i);
    }
}
void make()
{
    memset(vis,0,sizeof(vis));
    int x1, y1;
    cin >> x1 >> y1;
    queue<PII> q;
    int ans = 0;
    q.push({0, 0});
    vis[0][0] = 1;
    if (x1 == 0 && y1 == 0)
    {
        cout << 0 << endl;
        return;
    }
    while (q.size())
    {
        int nn = q.size();
        ans++;
        for (int j = 1; j <= nn; j++)
        {
            auto now = q.front();
            q.pop();
            for (int k = 0; k < dx.size(); k++)
            {
                for(int p=0;p<4;p++)
                {
                    int mx = dx[k]*p + now.first;
                    int my = dy[k]*p + now.second;
                    if (mx>=0&&my>=0&& mx <= 50 && my <= 50 && !vis[mx][my])
                    {
                        vis[mx][my] = 1;
                        q.push({mx, my});
                    }
                    if (mx == x1 && my == y1)
                    {
                        cout << ans << endl;
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int x1, y1;
    cin >> n;
    pre();
    int sz = sizeof(dx) / sizeof(int);
    for (int i = 1; i <= n; i++)
    {
        make();
    }
    return 0;
}