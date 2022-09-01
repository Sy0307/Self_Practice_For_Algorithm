#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> x(n);
    x[0] = 1;
    for(int i=n;i>=2;i-=2)
    {
        x[i-1] = i-1;
        x[i-2] = i;
    }
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}