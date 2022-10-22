#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y;
    int limitx, limity;
};
int lx, ly, n, m, r, c;
bool vis[2010][2010];
int main()
{
    ios::sync_with_stdio(false);
    queue<Node> q;
    cin >> n >> m >> r >> c >> lx >> ly;
    q.push(Node({r, c, 0, 0}));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                vis[i][j] = 1;
            else
                vis[i][j] = 0;
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    auto check = [&](int xx, int yy)
    {
        if (xx <= n && xx > 0 && yy > 0 && yy <= m)
        {
            return true;
        }
        return false;
    };
    while (q.size())
    {
        auto now = q.front();
        q.pop();
        int x = now.x;
        int y = now.y;
        //    cout<<x<<" "<<y<<endl;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        ans++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && !vis[nx][ny])
            {
                if (i == 0)
                {
                    if (now.limitx < lx)
                        q.push(Node({nx, ny, now.limitx + 1, now.limity}));
                }
                else if (i == 1)
                {
                    if (now.limity < ly)
                        q.push(Node({nx, ny, now.limitx, now.limity + 1}));
                }
                else
                {
                    q.push(Node({nx, ny, now.limitx, now.limity}));
                }
            }
        }
    }
    cout << ans << endl;
}