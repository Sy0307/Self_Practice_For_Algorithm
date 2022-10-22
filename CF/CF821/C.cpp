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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> odd;
    vector<int> even;
    fr(i, 1, n)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    cout << n - 1 << endl;
    if (!(a[1] & 1))
    {
        swap(odd, even);
    }
    for (int i = odd.size() - 2; i >= 0; i--)
    {
        cout << odd[i] << " " << odd.back() << endl;
    }
    for (auto &now : even)
    {
        cout << 1 << " " << now << endl;
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