/*
 * @Author: JorD
 * @LastEditTime: 2022-12-01 01:24:29
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
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1, vector<ll> (n + 1, 1e18));
    rep(i, 1, n) g[i][i] = 0;
    rep(i, 1, m){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 1e18));
    f[1][0] = 0;
    rep(j, 1, n)
    rep(i, 2, n)
    rep(k, 1, n)
    f[i][j] = min(f[k][j - 1] + g[k][i], f[i][j]);
    int _;  cin >> _;
    while(_ --){
        int T;
        cin >> T;
        ll res = 1e18;
        vector<ll> pre(n);
        rep(i, 1, n - 1) cin >> pre[i];
        rep(i, 1, n - 1) pre[i] += pre[i - 1];
        rep(i, 1, n - 1) res = min(res, pre[i] + f[T][i]);
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}