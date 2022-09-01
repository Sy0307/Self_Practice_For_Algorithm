#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        int tmp;
        cin >> x;
        for (int i = 1; i <= x / 2; i++)
        {
            cin >> tmp;
            s1 += tmp;
        }
        if (x & 1)
        {
            cin>>tmp;
            a.push_back(-tmp);
        }
        for (int i = 1; i <= x / 2; i++)
        {
            cin >> tmp;
            s2 += tmp;
        }
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (auto now:a)
    {
        if(cnt&1)
        {
            s1+=-now;
        }
        else s2+=-now;
        cnt++;
    }
    cout<<s1<<" "<<s2<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}