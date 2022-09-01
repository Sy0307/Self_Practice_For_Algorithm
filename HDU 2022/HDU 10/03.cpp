#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll a[maxn], b[maxn], c[maxn], d[maxn];
// ll gethigh(int index, ll a[])
// {
//     if (a[index] > a[index - 1] && a[index] > a[index + 1])
//         return a[index];
//     return max(a[index + 1], a[index - 1]) + 1;
// }
// ll getlow(int index, ll a[])
// {
//     if (a[index] < a[index - 1] && a[index] < a[index + 1])
//         return a[index];
//     return min(a[index + 1], a[index - 1]) - 1;
// }
void solve()
{
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
        c[i] = d[i] = b[i] = a[i];
    }
    ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    bool f = 1;
    for (int i = 2; i <= n; i++, f = !f)
    {
        if (f)
        {
            int tmp = a[i - 1] + 1;
            if (a[i] > a[i - 1])
                continue;
            t1 += abs(tmp - a[i]);
            a[i] = tmp;
        }
        else
        {
            int tmp = a[i - 1] - 1;
            if (a[i] < a[i - 1])
                continue;
            t1 += abs(tmp - a[i]);
            a[i] = tmp;
        }
    }
    //   cout << t1 << endl;
    f = 0;
    for (int i = 2; i <= n; i++, f = !f)
    {
        //    cout<<t2<<endl;
        if (!f)
        {
            int tmp = b[i - 1] + 1;
            if (b[i] > b[i - 1])
                continue;
            t2 += abs(tmp - b[i]);
            b[i] = tmp;
        }
        else
        {
            if (b[i] < b[i - 1])
                continue;
            int tmp = b[i - 1] - 1;
            t2 += abs(tmp - b[i]);
            b[i] = tmp;
        }
    }
    // f = 1;
    // for (int i = n - 1; i >= 1; i--, f = !f)
    // {
    //     //    cout<<t2<<endl;
    //     if (!f)
    //     {
    //         int tmp = c[i + 1] + 1;
    //         if (c[i] > c[i + 1])
    //             continue;
    //         t3 += abs(tmp - c[i]);
    //         c[i] = tmp;
    //     }
    //     else
    //     {
    //         if (c[i] < c[i + 1])
    //             continue;
    //         int tmp = c[i + 1] - 1;
    //         t3 += abs(tmp - c[i]);
    //         c[i] = tmp;
    //     }
    // }
    // f = 0;
    // for (int i = n - 1; i >= 1; i--, f = !f)
    // {
    //     //    cout<<t2<<endl;
    //     if (!f)
    //     {
    //         int tmp = d[i + 1] + 1;
    //         if (d[i] > d[i + 1])
    //             continue;
    //         t4 += abs(tmp - d[i]);
    //         d[i] = tmp;
    //     }
    //     else
    //     {
    //         if (d[i] < d[i + 1])
    //             continue;
    //         int tmp = d[i + 1] - 1;
    //         t4 += abs(tmp - d[i]);
    //         d[i] = tmp;
    //     }
    // }

    //  cout<<t1<<" "<<t2<<endl;
  //  cout << t3 << " " << t4 << endl;

    cout << min({t1, t2}) << endl;
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