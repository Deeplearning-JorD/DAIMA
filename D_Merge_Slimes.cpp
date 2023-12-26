/*
 * @Author: JorD
 * @LastEditTime: 2023-10-07 20:52:57
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n; cin >> n;
    ll res = 0;
    vector<ll> a(n + 1), b(n + 1);
    map<ll,ll> q, st;
    vector<pair<ll,ll>> s;
    rep(i, 1, n){
        int x, y; cin >> x >> y;
        q[x] = y;
    }    
    for(auto [x, y] : q) s.push_back({x, y});
    reverse(s.begin(), s.end());
    function<ll(ll)> dfs = [&](ll x) -> long long{
        st[x] = 1;
        if(x == 0) return 0;
        ll now = q[x];
        if(x % 2 == 0) now += dfs(x / 2);
        res += now % 2;
        now /= 2;
        return now;
    };
    for(auto [x, y] : s)if(!st[x]){
        ll now = dfs(x);
        while(now){
            res += now % 2;
            now /= 2;
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}