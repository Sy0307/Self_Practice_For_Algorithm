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

void solve()
{
    int cnt = 0;
    vector<int> ans;
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    s = "?" + s;
    fr(i, 1, n)
    {
        if (s[i] == '0')
        {
            cnt++;
            if (cnt == b)
            {
                ans.push_back(i);
                cnt = 0;
            }
        }
        else
            cnt = 0;
    }
    int tot = ans.size() - a + 1;
    cout<<tot<<endl;
    fr(i, 0, tot-1)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}