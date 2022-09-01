#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool right(int x, int y, int n, int m,int x1,int y1)
{
    return x >= 1 && x <= n && y >= 1 && y <= m&&x!=x1&&y!=y1;
}
bool check(int x, int y, vector<vector<int>> &mp)
{
    if (mp[x][y] == 1)
    {
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (right(nx, ny, mp.size()-1, mp[0].size()-1,x,y) && mp[nx][ny] < mp[x][y])
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    //   cout<<mp[0].size()<<endl;
    using pii = pair<int, int>;
    vector<pii> bad;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!check(i, j, mp))
            {
                bad.push_back(make_pair(i, j));
            }
        }
    //    cout<<i<<endl;
    }
    cout << bad.size() << endl;
    if (bad.size() == 0)
    {
        cout << "0" << endl;
        return;
    }
    else if (bad.size() > 4)
    {
        cout << 2 << endl;
        return;
    }
    int ans = 0;
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    vector<pii> tt;
    auto kk = bad[0];
    vis[kk.first][kk.second] = true;
    tt.push_back(kk);

    for (int i = 0; i < 4; i++)
    {
        int nx = kk.first + dx[i];
        int ny = kk.second + dy[i];
        if (right(nx, ny, n, m,kk.first,kk.second))
        {
            tt.push_back(make_pair(nx, ny));
            vis[nx][ny] = true;
        }
    }

    for (auto nowpos : tt)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j]&&nowpos.first+nowpos.second>=i+j)
                {
                    continue;
                }
                swap(mp[i][j], mp[nowpos.first][nowpos.second]);

                bool f = check(i, j, mp) && check(nowpos.first, nowpos.second, mp);
                for (auto b : bad)
                {
                    f &= check(b.first, b.second, mp);
                }
                if (!f)
                    continue;
                for (int c = 0; c < 4; c++)
                {
                    int nx = i + dx[c];
                    int ny = j + dy[c];
                    if (f && right(nx, ny, n, m,i,j) && !check(nx, ny, mp))
                    {
                        f = 0;
                    }
                    nx = nowpos.first + dx[c];
                    ny = nowpos.second + dy[c];
                    if (f && right(nx, ny, n, m,i,j) && !check(nx, ny, mp))
                    {
                        f = 0;
                    }
                }
                swap(mp[i][j], mp[nowpos.first][nowpos.second]);
                if (f)
                    ans++;
            }
        }
    }
    if (ans)
        cout << 1 << " " << ans << endl;
    else
        cout << 2 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}