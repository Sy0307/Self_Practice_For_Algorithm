#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int,int>;

int main() 
{

    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i ++) cin >> a[i].first;
    for (int i = 0; i < n; i ++) cin >> a[i].second;
    for (int i = 0; i < m; i ++) cin >> b[i].first;
    for (int i = 0; i < m; i ++) cin >> b[i].second;

    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());

    multiset<int> S;
    for (int i = 0, j = 0; i < n; i ++)
    {
    while (j < m and b[j].first >= a[i].first) S.insert(b[j].second), j ++;
    auto it = S.lower_bound(a[i].second);
        if (it == S.end()) 
        {
        cout<<"No"<<endl;
        return 0;
        }
    S.erase(it);
    }
    cout << "Yes\n";
}