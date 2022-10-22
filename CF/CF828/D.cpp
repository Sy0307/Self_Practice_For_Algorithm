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

int get(int x)
{
    int ans = 0;
    while (x % 2 == 0)
    {
        x /= 2;
        ans++;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    int cnt = 0;
    vector<int> t;
    fr(i, 1, n )
    {
        cnt += get(a[i]);
        if (i%2==0)
            t.push_back(get(i));
    }
    sort(t.begin(), t.end());
    int k = t.size();
    int ans = 0 ;
    while(cnt<n&&k)
    {
        cnt+=t.back();
        t.pop_back();
        k--;
        ans++;
    }
    if(cnt<n)
    {
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;
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