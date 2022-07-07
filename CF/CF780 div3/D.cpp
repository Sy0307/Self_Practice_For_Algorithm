#include<bits/stdc++.h>
using namespace std;

#define fer(i,a,b) for(int i = a ; i <= b ; ++ i)
#define lb lower_bound
#define ub upper_bound
inline void de2(long long   a , long long  b) {cout << a << " " << b << "\n" ;}
#define cf int _; cin>> _; while(_--)
const int N = 1e6 + 10 , M = 3010 , mod = 1e9 + 7 ; // mod = 998244353 ;
int n , m ;
int a[N] ;
int s[N] ; // s[i]表示[1,i]中负数的个数
int ss[N] ; // ss[i]表示[1,i]中a[i]绝对值=2的个数
int res , ll , rr ;
 
void get(int l , int r)
{
    int x = s[r] - s[l - 1] ;
    int sum = ss[r] - ss[l - 1] ;
    if(sum > res && x % 2 == 0)
    {
        res = sum ;
        ll = l - 1 , rr = n - r ;
    }
}
 
signed main()
{
    cf
    {
        cin >> n ;
        vector<int> v ;
        fer(i,1,n) cin >> a[i] , s[i] = s[i - 1] + (a[i] < 0) , ss[i] = ss[i - 1] + (abs(a[i]) == 2) ;
        a[0] = 0 , a[n + 1] = 0 ;
        fer(i,0,n+1) 
            if(a[i] == 0)
                v.push_back(i) ;
                
        multiset<int> q ; // set里面放所有负数的下标
        fer(i,1,n)
            if(a[i] < 0)
                q.insert(i) ;
                
        res = -1e9 ;
        ll = 1 , rr = n - 1 ;
        for(int i = 0 ; i + 1 < (int)v.size() ; i ++)
        {
            int l = v[i] + 1 , r = v[i + 1] - 1 ;
            int x = s[r] - s[l - 1] ;
            if(x % 2 == 0)
            {
                get(l,r);
            }
            else
            {
                auto it = q.lb(l) ;
                get(*it + 1 , r) ;
                
                it = q.ub(r) ;
                -- it ;
                get(l , *it - 1) ;
            }
        }
        
        de2(ll , rr) ;
    }
    return 0 ;
}
