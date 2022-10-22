#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <time.h>
#include <map>
#include <algorithm>
#include <fstream>
//#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500000 + 100;
const int INF = 0x7fffffff;
const ll mod = 1e9+7;
const ll mod1 = 998244353;
const ll base = 137;
const double Pi = acos(-1.0);
const int G = 3;
int a[maxn];
int n,m;
int q[maxn];
int uu[maxn];
struct node
{
    int l,r;
    int mx;
    int has;
    int lz;
}tree[maxn*4];
void build(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].lz=0;
    if(l==r)
    {
        tree[i].mx=a[l];
        tree[i].has=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
    tree[i].has=(1ll*tree[i*2].has*q[tree[i*2+1].r-tree[i*2+1].l+1]%mod+tree[i*2+1].has)%mod;
}
void pushdown(int i)
{
    tree[i*2].mx+=tree[i].lz;
    tree[i*2].has=(1ll*tree[i*2].has+1ll*uu[tree[i*2].r-tree[i*2].l+1]*tree[i].lz%mod)%mod;
    tree[i*2+1].mx+=tree[i].lz;
    tree[i*2+1].has=(1ll*tree[i*2+1].has+1ll*uu[tree[i*2+1].r-tree[i*2+1].l+1]*tree[i].lz%mod)%mod;
    tree[i*2].lz+=tree[i].lz;
    tree[i*2+1].lz+=tree[i].lz;
    tree[i].lz=0;
}
void update(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].mx++;
        tree[i].lz++;
        tree[i].has=(1ll*tree[i].has+uu[tree[i].r-tree[i].l+1])%mod;
        return;
    }
    pushdown(i);
    if(tree[i*2].r>=l) update(i*2,l,r);
    if(tree[i*2+1].l<=r) update(i*2+1,l,r);
    tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
    tree[i].has=(1ll*tree[i*2].has*q[tree[i*2+1].r-tree[i*2+1].l+1]%mod+tree[i*2+1].has)%mod;
}
int query(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        return tree[i].has;
    }
    pushdown(i);
    int s=0;
    if(tree[i*2].r>=l) s+=query(i*2,l,r);
    if(tree[i*2+1].l<=r) s=(1ll*s*q[max(0,min(r,tree[i*2+1].r)-tree[i*2+1].l+1)]%mod+query(i*2+1,l,r))%mod;
    return s;
}
void check(int i)
{
  //  if(tree[i].mx<65536) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].mx%=65536;
        tree[i].has=tree[i].mx;
        return;
    }
    pushdown(i);
    if(tree[i*2].mx>=65536) check(i*2);
    if(tree[i*2+1].mx>=65536) check(i*2+1);
    tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
    tree[i].has=(1ll*tree[i*2].has*q[tree[i*2+1].r-tree[i*2+1].l+1]%mod+tree[i*2+1].has)%mod;
}
int main()
{
    scanf("%d%d",&n,&m);
    q[0]=1;
    for(int i=1;i<=n+10;i++)
    {
        q[i]=1ll*q[i-1]*base%mod;
    }
    uu[1]=1;
    for(int i=2;i<=n+10;i++)
    {
        uu[i]=(1ll*uu[i-1]*base+1)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            update(1,l,r);
            check(1);
        }
        else
        {
            int l,r,len;
            scanf("%d%d%d",&l,&r,&len);
            if(query(1,l,l+len-1)==query(1,r,r+len-1))
            {
                puts("yes");
            }
            else puts("no");
        }
    }
  //  system("pause");
}
