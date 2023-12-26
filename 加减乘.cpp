/*
 * @Author: JorD
 * @LastEditTime: 2023-02-04 19:55:18
 */
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
ll n, x, y;
ll res = 1e18;
void dfs(ll now, ll w){
    if(now < 0) return;
    if(now > n){
        res = min(res, w + (now - n) * x);
        return;
    }
    if(now == n){
        res = min(res, w);
        return;
    }
    dfs(now + 1, w + x);
    // dfs(now * 2, w + y);
}
void Solve(){
    cin >> n >> x >> y;
    dfs(0, 0);
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