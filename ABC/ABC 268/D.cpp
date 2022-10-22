#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

int n, m;
string a[10];
set<string> mp;
bool f = 0;
bool vis[10] = {0};

string now = "";
int cnt = 0;
void dfs(int step)
{
    if (f || now.size() > 16)
        return;
    // cout<<now<<endl;
    if (step > n)
    {
        if (!mp.count(now)&&now.size()>=3)
        {
            cout << now << endl;
            f = 1;
        }
        return;
    }
    if (step != 1 && step <= n)
    {
        now += "_";
        dfs(step);
        now.pop_back();
    }
    if (now.back() == '_'||step==1)
    {
        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                vis[i] = 1;
                now += a[i];
               // cout<<step<<" "<<now<<endl;
                dfs(step + 1);
                for (int j = 0; j < a[i].size(); j++)
                    now.pop_back();
                vis[i] = 0;
            }
    }
};

void solve()
{
    cin >> n >> m;
    fr(i, 1, n)
    {
        cin >> a[i];
        cnt += a[i].size();
    }
    fr(i, 1, m)
    {
        string s;
        cin >> s;
        mp.insert(s);
    }
    dfs(1);
    if (!f)
    {
        cout << -1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}