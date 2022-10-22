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
#define endl '\n'
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

int p[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
void solve()
{
    int cnt = 0 ;
    for(int i=0;i<19;i++)
    {
        cout<<p[i]<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s=="yes")
        {
            cnt++;
        }
    }
    if(cnt>=2)
    {
        cout<<"composite"<<endl;
    }
    else
    {
        cout<<"prime"<<endl;
    }
    fflush(stdout);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}