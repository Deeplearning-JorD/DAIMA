/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 14:28:24
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
    vector<ll> w(n + 1), v(n + 1);
    rep(i, 1, n) cin >> v[i] >> w[i];
    auto DP = [&](int k){
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
        ll res = 0;
        rep(i, 1, n){
            if(i == k){
                rep(j, 1, m) dp[i][j] = dp[i - 1][j];
                continue;
            }
            rep(j, 1, m){
                dp[i][j] = dp[i - 1][j];
                if(v[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
                res = max(dp[i][j], res);
            }
        }
        return res;
    };
    ll mx = DP(0);
    rep(i, 1, n){
        if(DP(i) < mx){
            cout << 0 << endl;
            continue;
        }
        ll last = w[i];
        ll l = 1, r = 1e11;
        while(l < r){
            ll mid = l + r >> 1;
            w[i] = last + mid;
            if(DP(0) > DP(i)) r = mid;
            else l = mid + 1;
        }
        w[i] = last;
        cout << r << endl;
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