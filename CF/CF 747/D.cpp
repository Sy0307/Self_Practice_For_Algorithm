#include <bits/stdc++.h>
#define k1 "imposter"
using namespace std;
const int maxn = 700005;
int co[maxn];
bool diff;
vector<int> v[maxn];
int t[2], n, m;

void dfs(int now)
{
    for (auto it : v[now])
    {
        if (co[it] == co[now])
        {
            diff = 0;
            return;
        }

        if (co[it] != -1)
            continue;
        co[it] = 1 - co[now];
        if (it <= n)
            t[co[it]]++;
        dfs(it);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
    {
        co[i] = -1;
        v[i].clear();
    }
    diff = 1;
    int cnt = n;
    int a, b;
    string s;
    while (m--)
    {
        cin >> a >> b;
        cin >> s;
        if (s == "imposter")
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        else
        {
            v[a].push_back(++cnt);
            v[cnt].push_back(a);
            v[b].push_back(cnt);
            v[cnt].push_back(b);
        }
    }
    //   cout<<1<<endl;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (co[i] != -1)
            continue;
        co[i] = 0;
        t[0] = 1;
        t[1] = 0;

        dfs(i);
        ans += max(t[0], t[1]);
    }
    if (!diff)
        ans = -1;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}