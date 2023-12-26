/*
 * @Author: JorD
 * @LastEditTime: 2023-03-01 17:17:00
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<ll> cold(k + 1), hot(k + 1);
    rep(i, 1, k) cin >> cold[i];
    rep(i, 1, k) cin >> hot[i];
    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, 1e18));
    // dp[i][j] 表示 第i个 物品放入其中一个序列后，另外一个序列的最后一个处理的物品是j的最小方案数
    dp[0][0] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= k;j ++){
            ll w;
            if(a[i] == a[i - 1]) w = hot[a[i]];
            else w = cold[a[i]];
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + w);
            if(a[i] == j) w = hot[a[i]];
            else w = cold[a[i]];
            dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + w); 
        }
    }
    ll res = 1e18;
    for(int i = 0;i <= k;i ++){
        res = min(res, dp[n][i]);
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