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
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 1e17));
    rep(i, 1, n) f[i][i] = 0;
    rep(i, 1, m){
        ll x, y, z;
        cin >> x >> y >> z;
        f[y][x] = f[x][y] = min(f[x][y], z);
    }
    auto ff = f;
    ll res = 1e18;
    rep(k, 1, n)
    rep(i, 1, n)
    rep(j, 1, n){
        if(i != k && k != j && i != j)
        res = min(res, 0ll + f[i][j] + ff[i][k] + ff[k][j]);
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    if(res > 1e9) cout << "No solution.\n";
    else cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}