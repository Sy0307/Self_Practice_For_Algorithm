#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
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

int n, k;
bool check(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int col[10]={0}, row[10]={0};
void solve()
{
    cin >> n;
    cin >> k;
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    vector<pii> a(k + 1);
    fr(i, 1, k)
    {
        cin >> a[i].first >> a[i].second;
        int x = a[i].first;
        int y = a[i].second;
        col[x]++;
        row[y]++;
    }
    bool f = 0;
    fr(i, 1, k)
    {
        fr(j, 0, 3)
        {
            col[a[i].first]--;
            row[a[i].second]--;
            int x = a[i].first + dx[j];
            int y = a[i].second + dy[j];
            if (check(x, y))
            {
                if(col[x]==0&&row[y]==0)
                {
                    f=1;
                    break;
                }
            }
            col[a[i].first]++;
            row[a[i].second]++;
        }
    }
    if(f)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}