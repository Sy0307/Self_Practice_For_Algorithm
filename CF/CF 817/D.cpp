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

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    priority_queue<int> q;
    string s;
    cin >> s;
    s = '0' + s;
    fr(i, 1, n)
    {
        if (s[i] == 'L')
        {
            ans += i - 1;
        }
        else
        {
            ans += n - i;
        }
    }
    fr(i, 1, n)
    {
        if (s[i] == 'L')
        {
            q.push(max(0, n - i - i + 1));
        }
        else
        {
            q.push(max(0, i - 1 - n + i));
        }
    }
    fr(i, 1, n)
    {
        ans += q.top();
        cout << ans << " ";
        q.pop();
    }
    cout << endl;
}
int main()
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