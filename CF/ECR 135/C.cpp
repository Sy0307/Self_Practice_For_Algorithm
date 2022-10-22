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

priority_queue<int, vector<int>, less<int>> p, q;
int make(int x)
{
    int ans = 0;
    while (x)
    {
        x /= 10;
        ans++;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    while (p.size())
        p.pop();
    while (q.size())
        q.pop();
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        p.push(x);
    }
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    while (p.size())
    {
        int x = p.top();
        int y = q.top();
        if (x == y)
        {
            p.pop();
            q.pop();
        }
        else if (x > y)
        {
            p.pop();
            int tmp = make(x);
            p.push(tmp);
            ans++;
        }
        else
        {
            ans++;
            q.pop();
            int tmp = make(y);
            q.push(tmp);
        }
    }
    cout<<ans<<endl;
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