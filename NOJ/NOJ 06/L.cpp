#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll d,k;
    cin>>d>>k;
    ll step = 0;
    for(ll x = 0;x<=d;x+=k)
    {
        ll y = sqrt(d*d - x*x);
        step = max(step, y/k+x/k);
    }
    if(!(step&1))
    {
        cout<<"Utkarsh"<<endl;
    }
    else
        cout<<"Ashish"<<endl;
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
    return 0;
}