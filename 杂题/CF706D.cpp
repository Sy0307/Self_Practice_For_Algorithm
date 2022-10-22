#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 20000000;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
// istream &operator>>(istream &in, vector<int> &v)
// {
//     for (auto &i : v)
//         in >> i;
//     return in;
// }
// ostream &operator<<(ostream &out, vector<int> &v)
// {
//     for (auto &i : v)
//         out << i << " ";
//     return out;
// }

int son[maxn][2], cnt[maxn], idx;
void del(int x)
{
    int p = 0;
    ford(i, 31, 0)
    {
        int u = x >> i & 1;
        // if (!son[p][u])
        //     return;
        p = son[p][u];
        cnt[p]--;
    }
}
int query(int x)
{
    int p = 0, ans = 0;
    ford(i, 31, 0)
    {
        int u = x >> i & 1;
        if (son[p][!u] && cnt[son[p][!u]])
        {
            ans = ans * 2 + 1;
            p = son[p][!u];
        }
        else
        {
            p = son[p][u];
            ans <<= 1;
        }
    }
    return ans;
}
void insert(int x)
{ // 插入字符串
    int p = 0;
    for (int i = 31; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}
void solve()
{
    int q;
    insert(0);
    cin >> q;
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            insert(x);
        }
        else if (c == '-')
        {
            del(x);
        }
        else
            cout << query(x) << endl;
    }
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