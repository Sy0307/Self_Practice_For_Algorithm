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


void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if(!x&&!y) 
    {
        cout<<-1<<endl;
        return ;
    }
    if (x && y)
    {
        cout << -1 << endl;
        return;
    }
    else if (x)
    {
        if ((n - 1) % x)
        {
            cout << -1 << endl;
            return;
        }
    }
    else
    {
        if ((n - 1) % y)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> a(n + 1);
    int k = max(x, y);
    int idx = 2;
    int win = 1;
    int cnt = 0;
    while (idx <= n)
    {
        a[idx] = win;
        cnt++;
        if (cnt == k)
        {
            cnt = 0;
            win = idx+1;
        }
        idx++;
    }
    //   cout<<"??"<<endl;
    fr(i, 2, n)
    {
        cout << a[i] << " ";
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