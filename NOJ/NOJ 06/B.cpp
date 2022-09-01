#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define WIN cout<<"Adrien"<<endl;
#define LOSE cout<<"Austin"<<endl;

void solve()
{
    int n,k;
    cin>>n>>k;
    if(n==0)
    {
        LOSE return;
    }
    else if(k==1)
    {
        if(n&1)
        {
            WIN return;
        }
        else
        {
            LOSE return;
        }
    }else WIN
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
 //   cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}