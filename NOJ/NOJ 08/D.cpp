#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using ll = long long;
    template <typename T>
    struct ST
    {
        ST(T Signal[], int n)
        {
            siz = n;
            maxv.resize(n + 1);
            minv.resize(n + 1);
            int t = __lg(n) + 1;
            for (int i = 0; i <= n; i++)
                maxv[i].resize(t), minv[i].resize(t);
            for (int i = 0; i <= n; i++)
                maxv[i][0] = minv[i][0] = Signal[i];
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

    bool SignalOverload(vector<int> &Signal)
    {
        int n = Signal.size();
        vector<int> left(n + 1, 0), right(n + 1, n + 1);
        stack<array<ll, 2>> st;
        for (int i = 1; i <= n; i++)
        {
            while (!st.empty() && st.top()[1] < Signal[i - 1])
                right[st.top()[0]] = i, st.pop();
            st.push({i, Signal[i - 1]});
        }
        while (!st.empty())
            st.pop();

        for (int i = n; i >= 1; i--)
        {
            while (!st.empty() && st.top()[1] < Signal[i - 1])
                left[st.top()[0]] = i, st.pop();
            st.push({i, Signal[i - 1]});
        }

        ll pre[n + 1];
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + Signal[i - 1];
        }
        ST<ll> s(pre, n);
        for (int i = 1; i <= n; i++)
        {
            ll p1 = s.getmin(left[i], i - 1), p2 = s.getmax(i, right[i] - 1);
            if (p2 - p1 > Signal[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};
vector<int> pre()
{
    int n;
    cin >> n;
    vector<int> Signal(n);
    for(int i=0;i<n;i++)
    {
        cin >> Signal[i];
    }
    return Signal;
}
int main()
{
    ios::sync_with_stdio(false);
    Solution S;
    int T;
    cin >> T;
    while (T--)
    {
        auto a = pre();
        S.SignalOverload(a) ? cout << "NO" : cout << "YES";
        cout<<endl;
    }
}