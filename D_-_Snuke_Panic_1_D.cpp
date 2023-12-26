/*
 * @Author: JorD
 * @LastEditTime: 2022-09-09 20:16:29
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    map<ll,pair<ll,ll>> q;
    vector<vector<ll>> f(1e5 + 1, vector<ll> (7, -1e18));
    rep(i, 1, n){
        ll t, x, y;
        cin >> t >> x >> y;
        q[t] = {x + 1, y};
    }
    f[0][1] = 0;
    rep(i, 1, 1e5){
        rep(j, 1, 5)
            f[i][j] = max({f[i - 1][j], f[i - 1][j - 1], f[i - 1][j + 1]});
        f[i][q[i].first] += q[i].second;
    }
    ll res = -1e18;
    rep(i, 1, 5)
        res = max(res, f[1e5][i]);
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}