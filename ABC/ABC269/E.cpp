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
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

int n;
void solve()
{
    cin>>n;
    int l = 0 , r = n;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        cout<<"? "<<"1 "<<mid<<" "<<"1 "<<n<<endl;
        int x;
        cin>>x;
        if(x==mid)
        {
            l = mid;
        }
        else r = mid;
    }
    int x = l;

    l = 0 , r = n;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        cout<<"? "<<"1 "<<n<<" "<<1<<" "<<mid<<endl;
        int y;
        cin>>y;
        if(y==mid)
        {
            l = mid;
        }
        else r = mid;
    }
    int y = l;
    cout<<"! "<<x+1<<" "<<y+1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}