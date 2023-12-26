/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 13:44:36
 * how to Get
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    multiset<int> s;
    rep(i, 1, n){
        int m; cin >> m;
        a[i].resize(m);
        for(auto &x:a[i]) cin >> x;
        sort(a[i].begin(), a[i].end(), greater<>());
        q.push({a[i].back(), i});
        s.insert(a[i].back());
    }
    int res = 2e9;
    while(1){
        auto [x, i] = q.top(); q.pop();
        res = min(res, (*s.rbegin()) - x);
        s.erase(s.find(x));
        if(a[i].empty()) break;
        int y = a[i].back();
        a[i].pop_back();
        q.push({y, i});
        s.insert(y);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}