#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ST
{
    ST(T a[], int n)
    {
        siz = n;
        maxv.resize(n + 1);
        minv.resize(n + 1);
        int t = __lg(n) + 1;
        for (int i = 0; i <= n; i++)
            maxv[i].resize(t), minv[i].resize(t);
        for (int i = 0; i <= n; i++)
            maxv[i][0] = minv[i][0] = a[i];
        for (int j = 1; j < t; j++)
        {
            for (int i = 0; i <= n - (1 << j) + 1; i++)
            {
                maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
                minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T getmax(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
    }
    T getmin(int l, int r)
    {
        int k = __lg(r - l + 1);
        return min(minv[l][k], minv[r - (1 << k) + 1][k]);
    }

private:
    int siz = 0;
    vector<vector<T>> maxv, minv;
};

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //   cout<<1<<endl;
    //
    vector<ll> l(n + 1, 0);
    vector<ll> r(n + 1, n + 1);
    stack<pair<ll, ll>> st;

    for (int i = 1; i <= n; i++)
    {
        while (st.size() && st.top().second < a[i])
        {
            r[st.top().first] = i;
            st.pop();
        }
        st.push(make_pair(i, a[i]));
    }

    while (st.size())
        st.pop();

    for (int i = n; i >= 1; i--)
    {
        while (st.size() && st.top().second < a[i])
        {
            l[st.top().first] = i;
            st.pop();
        }
        st.push(make_pair(i, a[i]));
    }

    ll pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ST<ll> stt(pre, n);

    for (int i = 1; i <= n; i++)
    {
        ll k1 = stt.getmin(l[i], i - 1);
        ll k2 = stt.getmax(i, r[i] - 1);
        if (k2 - k1 > a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    //
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}