#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define for (i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void resort(int &a,int &b,int &c)
{
    int tmp = max({a,b,c});
    int tmp2 = min({a,b,c});
    int tmp3 = a + b + c - tmp - tmp2;
    a = tmp;
    b = tmp3;
    c = tmp2;
}
int judge(int a,int b,int c)
{
    if(b>a+c||c>a+b||a>b+c)
        return 0;
    return true;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    resort(a,b,c);
    if(a==b&&c==1)
    {
        cout<<"Lose"<<endl;
        return;
    }
    if(b==c) cout<<""
    
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