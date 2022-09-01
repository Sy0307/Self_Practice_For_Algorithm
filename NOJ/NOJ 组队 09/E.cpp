#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    priority_queue<int> qa, qb;
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        qa.push(x);
    }
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        qb.push(x);
    }

    while(qa.size())
    {
        int t1 = qa.top();
        int t2 = qb.top();
        if(t1==t2) 
        {
            qa.pop();
            qb.pop();
        }
        else
        if(t1<t2)
        {
            qb.pop();
            qb.push(t2/2);
        }
        else
        {
            if(t1&1)
            {
                cout<<"NO"<<endl;
                return ;
            }
            qa.pop();
            qa.push(t1/2);
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}