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

ll sum[maxn], x[maxn];
string s[maxn];
int p[maxn];
void solve()
{
    int n;
    cin>>n;
    fr(i, 1, n)
    {
        cin >> s[i];
        fr(j, 0, s[i].size() - 1)
        {
            if (s[i][j] == 'X')
            {
                x[i]++;
            }
            else
            {
                sum[i] += s[i][j] - '0';
            }
        }
        p[i] = i;
    }
    sort(p + 1, p + 1 + n, [](int a, int b)
         { return x[a] * sum[b] > x[b] * sum[a]; });
    ll num = 0;
    ll ans = 0;

    ford(i, n, 1)
    {
        string t = s[p[i]];
        reverse(t.begin(), t.end());
        for (int j = 0; t[j]; j++)
        {
            if (t[j] == 'X')
            {
                ans += num;
            }
            else
                num += t[j] - '0';
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}