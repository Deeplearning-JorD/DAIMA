/*
 * @Author: JorD
 * @LastEditTime: 2022-10-10 20:03:25
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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1, vector<ll> (n + 1, 1e9));
    vector<vector<ll>> w(n + 1, vector<ll> (n + 1, 2e9));
    rep(i, 1, n) g[i][i] = 0;
    rep(i, 1, m){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = 1;
        w[a][b] = w[b][a] = min(w[a][b], c);
    }
    rep(k, 1, n){
        rep(i, 1, n){
            rep(j, 1, n){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    ll res = 1e18;
    rep(j, 1, n){
        rep(i, 1, n){
            if(w[i][j] == 2e9) continue;
            ll t = w[i][j] * (g[1][i] + g[n][j] + 1);
            res = min(res, t);
            rep(k, 1, n){
                res = min(res, w[i][j] * (g[i][k] + g[k][1] + g[k][n] + 2ll));
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}