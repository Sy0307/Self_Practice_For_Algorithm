#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s = "";
    for (int i = 0; i < m; i++)
    {
        s += 'B';
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x = a[i] - 1;
        int y = m-a[i];
        if(x>y) swap(x,y);
        if (s[x] == 'B')
        {
            s[x] = 'A';
        }
        else if(s[y]=='B')
        {
            s[y] = 'A';
        }
    }
    cout<<s<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}