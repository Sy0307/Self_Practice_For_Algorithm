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
    string s;
    cin >> s;
    int n = s.size();
    s = "?" + s;
    cout << abs(s[1] - s[n]) << " ";

    if (s[1] < s[n])
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        fr(i, 2, n - 1)
        {
            if (s[i] >= s[1] && s[i] <= s[n])
            {
                pq.push({s[i], i});
            }
        }
        cout << pq.size() + 2 << endl;
        cout << 1 << " ";
        while (pq.size())
        {
            cout << pq.top().second << " ";
            pq.pop();
        }
        cout << n << endl;
    }
    else
    {
        priority_queue<pii> pq;
        fr(i, 2, n - 1)
        {
            if (s[i] >= s[n] && s[i] <= s[1])
            {
                pq.push({s[i] - 'a', i});
            }
        }
        cout << pq.size() + 2 << endl;
        cout << 1 << " ";
        while (pq.size())
        {
            cout << pq.top().second << " ";
            pq.pop();
        }
        cout << n << endl;
    }
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