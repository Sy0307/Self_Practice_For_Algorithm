#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll tot = 0;
void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> qmax;
    priority_queue<int, vector<int>, less<int>> qmin;
    int mid = 1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        tot += x;
        if (x > mid)
        {
            qmax.push(x);
            if (qmax.size() - qmin.size() == 2)
            {
                qmin.push(mid);
                mid = qmax.top();
                qmax.pop();
            }
        }
        else
        {
            qmin.push(x);
            if (qmin.size() - qmax.size() == 2)
            {
                qmax.push(mid);
                mid = qmin.top();
                qmin.pop();
            }
        }
        // if ((qmax.size() - qmin.size()) > 1)
        // {
        //     if (qmax.size() > qmin.size())
        //     {
        //         qmin.push(qmax.top());
        //         qmax.pop();
        //     }
        //     else
        //     {
        //         qmax.push(qmin.top());
        //         qmin.pop();
        //     }
        // }
        if (i & 1)
        {
            if (qmax.size() > qmin.size())
            {
                mid = qmax.top();
            }
            else
            {
                mid = qmin.top();
            }
        }
        else
        {
            mid = qmin.top();
        }
       // cout << mid << endl;
        ll tmp = tot / i;
        cout << mid - tmp  << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}