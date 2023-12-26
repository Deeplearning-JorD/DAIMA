/*
 * @Author: JorD
 * @LastEditTime: 2022-12-11 01:34:20
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
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<pair<ll,ll>> b(n + 1);
    rep(i, 1, n){
        b[i] = {a[i], a[i] % d};
    }
    vector<vector<ll>> dp(k + 1, vector<ll> (d + 1, 0));
    // dp[i][j][k] 表示第i位，选了j个数，现在是%d是k的情况下的最大值。
    for(int i = 1;i <= n;i ++){
        auto [x, y] = b[i];
        // dp[1][y] = max(x, dp[1][y]);
        for(int j = k;j >= 1;j --){
            for(int k = 0;k < d;k ++){
                dp[j][(y + k) % d] = max(dp[j][(y + k) % d], dp[j - 1][k] + x);
            }
        }
    }
    ll res = -1;
    res = max(res, dp[k][0]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}