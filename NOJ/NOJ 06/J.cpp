#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define WIN cout<<"First"<<endl;
#define LOSE cout<<"Second"<<endl;

void solve()
{
    int n ; 
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        WIN 
        return;
    }
    else
    {
        int cnt = 1;
        while(a[cnt] ==1&&cnt<n)
        {
            cnt++;
        }
        if(cnt&1)
        {
            WIN
            return;
        }
        else
        {
            LOSE
            return;
        }
    }
    
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