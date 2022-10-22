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

ull h1[maxn], h2[maxn], p[maxn], n;
const int P = 131;
char s[maxn];
void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h1[i] = h1[i - 1] * P + s[i];
        h2[i] = h2[i - 1] * P + s[n - i + 1];
        p[i] = p[i - 1] * P;
    }
}
// 计算子串 s[l ~ r] 的哈希值
ull hash1(int l, int r)
{
    if (l > r)
        return -1;
    return h1[r] - h1[l - 1] * p[r - l + 1];
}
ull hash2(int l, int r)
{
    if (l > r)
        return -1;
    return h2[r] - h2[l - 1] * p[r - l + 1];
}

void solve()
{
    cin >> (s + 1);
    n = strlen(s + 1);
    int l = 1, r = n;
    // cout<<l<<endl;
    // cout<<r<<endl;
    init();
    while (s[l] == s[r])
    {
        l++;
        r--;
        if (l >= r)
        {
            cout << "1 1" << endl;
            return;
        }
    }
    // cout<<l<<" "<<r<<endl;

    int k = r - l + 1;
    int x = (l + r) / 2;
    if (hash1(l, x) == hash1(x + 1, r)) // S为一个空串
    {
        cout << l << " " << x << "\n";
        return;
    }

    // BAA
    for (int i = l; i <= r; i++)//SAA
    {

        if (hash1(l, i) == hash2(r - i + l, r - l + l))
        {
            ;
            int m = (i + r) / 2;
            if (hash1(i + 1, m) == hash1(m + 1, r))
            {
                cout << l << " " << m << "\n";
                return ;
            }
        }
    }

    // AAB
    for (int i = r; i >= l; i--)
    {
        if (hash1(i, r) == hash2(l, r - i + l))
        {

            int m = (i + l) / 2;
            if (hash1(l, m - 1) == hash1(m, i - 1))
            {
                cout << m << " " << r << "\n";
                return;
            }
        }
    }

    // ABA
    for (int i = l; i <= (l + r) / 2; i++)
    {
        if (hash1(l, i) == hash1(r - i + l, r))
        {
            if (hash1(l + i, r - i) == hash2(i + l, r - i))
            {
                cout << l << ' ' << i << "\n";
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
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