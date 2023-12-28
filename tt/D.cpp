#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 1e3 + 10;
long long f[N][N], dp[N][N][3];
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    memset(dp, 0xcf, sizeof dp);
    dp[1][1][0] = f[1][1];
    dp[1][1][1] = f[1][1];
    dp[1][1][2] = f[1][1];
    rep(j, 1, m){
        if(j != 1)
        rep(i, 1, n){
            ll mx = -1e9;
            rep(k, 0, 2) mx = max(dp[i][j - 1][k], mx);
            dp[i][j][0] = mx + f[i][j];
        }
        rep(i, 2, n){
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0]) + f[i][j];
        }
        if(j != 1)
        per(i, n - 1, 1){
            // cout << i << ' ' << j << ' ' << 2 << endl;
            // cout << dp[i + 1][j][2] << ' '  << dp[i + 1][j][0] << endl;
            dp[i][j][2] = max(dp[i + 1][j][2], dp[i + 1][j][0]) + f[i][j];
        }
        // rep(i, 1, n)
        // cout << dp[i][j][0] << ' ' << dp[i][j][1] << ' ' << dp[i][j][2] << endl;
    }
    cout << max({dp[n][m][0],dp[n][m][1], dp[n][m][2]}) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}