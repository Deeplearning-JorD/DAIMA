/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 17:38:26
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
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<vector<ll>> pre(n + 1, vector<ll> (2));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n){
        if(i & 1){
            pre[i][1] = pre[i - 1][1] + a[i];
            pre[i][0] = pre[i - 1][0];
        }else{
            pre[i][1] = pre[i - 1][1];
            pre[i][0] = pre[i - 1][0] + a[i];
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll> (2));
    // dp[i][0/1]表示第i位为翻转位时，且起始翻转位的坐标为偶/奇数时的最大代价
    ll res = pre[n][1];
    rep(i, 1, n){
        if(i & 1){
            dp[i][1] = max(dp[i - 1][1], pre[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
            res = max(res, dp[i][0] + pre[n][1] - pre[i][1]);
        }else{  
            dp[i][0] = max(dp[i - 1][0] + a[i], pre[i - 1][1] + a[i]);
            dp[i][1] = dp[i - 1][1] + a[i];
            res = max(res, dp[i][1] + pre[n][1] - pre[i][1]);
        }
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