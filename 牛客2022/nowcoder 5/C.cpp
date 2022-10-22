#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void solve()
{
    int n;
    cin >> n;
    vector<int> t(n, 0);
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < 3 * n; i++)
    {
        int index;
        string s;
        cin >> index >> s;
        if (index >= n)
            continue;
        t[index]++;
        if (s[0] == 'Y')
        {
            b[index]++;
        }
        else
            a[index]++;
    }
    bool error = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 0 || (a[i] > 1 && b[i] > 1))
        {
            cout << -1 << endl;
            return;
        }
        else if ((a[i] == 1 && b[i] > 1) || (b[i] == 1 && a[i] > 1))
        {
            error = 1;
        }
    }
    if(!error)
    {
        for(int i=0;i<n;i++)
        {
            if(t[i]==1)
            {
                cout<<-1<<endl;
                return ;
            }
        }
    }
    if (error)
    {
        int time = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]&&b[i])
            {
                time++;
            }
        }
        if(time>=2)
        {
            cout<<-1<<endl;
            return ;
        }
    }
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] > a[i])
            {
                cout << 1;
            }
            else
                cout << 0;
        }
    }
    cout << endl;
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