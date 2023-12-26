/*
 * @Author: JorD
 * @LastEditTime: 2023-03-01 23:58:38
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
int idx;
void Solve(){
    int n, k, x;
    cin >> n >> k >> x;
    idx ++;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll res = 0;
    if(k == 0){
        vector<ll> dp(n + 1, -1e18);
        for(int i = 1;i <= n;i ++){
            dp[i] = max(dp[i - 1] + a[i] - x, a[i] - x);
            res = max(res, dp[i]);
        }
        cout << res << endl;
        return;
    }
    if(x > 0){
        vector<ll> pre(n + 1, - 1e18);
        rep(i, 1, n) pre[i] = max(pre[i - 1] + a[i] - x, a[i] - x);
        for(int i = 1;i <= n - k + 1;i ++){
            vector<ll> dp(k + 1, -1e18);
            dp[0] = pre[i - 1];
            for(int j = 1;j <= k;j ++){
                dp[j] = max(dp[j - 1] + a[i + j - 1] + x, a[i + j - 1] + x);
                res = max(res, dp[j]);
            }
        }
        cout << res << endl;
    }else{
        for(int b = 0;b <= k;b ++){
            int l = b, r = n - (k - b) + 1;
            vector<ll> dp(n + 1, - 1e18);
            for(int i = 1;i <= n;i ++){
                if(i <= l || i >= r) dp[i] = max(dp[i - 1] + a[i] + x, a[i] + x);
                else dp[i] = max(dp[i - 1] + a[i] - x, a[i] - x);
                res = max(res, dp[i]);
            }
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}