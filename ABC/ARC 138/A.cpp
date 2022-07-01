#include<bits/stdc++.h>
using namespace std;

int read(){                        //读入优化，可以照着这个模板来写，这个还算写的比较好看。 
    int re=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ 
        re=re*10+ch-'0'; 
        ch=getchar();
    }
    return re;
}
struct node{
    int pos;
    int val;

    bool operator< (const node& a)
    {
        return a.val>val;
    }
}a[400010];
bool vis[400010];
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        a[i].val = read();
        
    }
    int ans = INT_MAX;
    for(int i=k+1;i<=n;i++)
    {
        bool f = 1;
        for(int j=k; f&&j>=1;j--)
        if(a[i].val>a[j].val)
        {
            ans = min(ans,i - j);
            f = 0;
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}