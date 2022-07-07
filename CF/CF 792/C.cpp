#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    int c = -1;
    int d = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                if(c==-1)
                {
                    c = j;
                }
                else if(d==-1)
                {
                    d = j;
                }
            }
        }
    if(c==d) c = d = 0;
    else
    {
        for(int i=0;i<n;i++)
        {
            swap(a[i][c],a[i][d]);
        }
    }
    bool f = 1;
    for(int i=0;i<n;i++)
    {
        if(!is_sorted(a[i].begin(),a[i].end()))
        {
            f = 0;
            break;
        }
    }
    if(f)
    {
        cout<<c+1<<" "<<d+1<<endl;
    }
    else cout<<-1<<endl;
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