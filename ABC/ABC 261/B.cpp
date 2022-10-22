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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int mp[1010][10100];
void solve()
{
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        fr(j, 1, n)
        {
            char c;
            cin >> c;
            if (c == '-')
                continue;
            else if(c=='D') mp[i][j] = 0;
            else if(c=='W') mp[i][j] =1;
            else if(c=='L') mp[i][j] =-1;
        }
    }
    fr(i,1,n)
    {
        fr(j,1,n)
        {
            if(mp[i][j]!=-mp[j][i])
            {
                cout<<"incorrect"<<endl;
                return;
            }
        }
    }
    cout<<"correct"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}