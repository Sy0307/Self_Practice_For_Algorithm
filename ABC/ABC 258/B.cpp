#include <bits/stdc++.h>
using namespace std;

int n;
string ans = "";
string now = "";
char mp[20][20];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
bool vis[20][20];
using pii = pair<int, int>;
pii correction(int x, int y)
{
    pii tmp;
    tmp.first = (x + n) % (n);
    tmp.second = (y + n) % (n);
    return tmp;
}
void dfs(int x, int y, int step, int k)
{
    if (step == n)
    {
        ans = max(ans, now);
        return;
    }
    if(vis[x][y]) return;
    vis[x][y] = 1;
    int nx = x + dx[k];
    int ny = y + dy[k];
    auto nex = correction(nx, ny);
    nx = nex.first;
    ny = nex.second;
    now.push_back(mp[x][y]);
    //   cout << now << endl;

    dfs(nx, ny, step + 1, k);
    now.pop_back();
    vis[x][y] = 0;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }
    //  cout<<1<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //    cout<<i<<" "<<j<<endl;
            //    cout<<1<<endl;
            now = "";
            for (int k = 0; k < 8; k++)
                dfs(i, j, 0, k);
        }
    }
    cout << ans << endl;
}