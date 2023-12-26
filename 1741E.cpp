/*
 * @Author: JorD
 * @LastEditTime: 2022-10-12 01:07:34
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
    vector<int> a(n + 1);
    vector<int> dp(n + 2);
    vector<int> vis(n + 2), ky(n + 2);
    rep(i, 1, n) cin >> a[i];
    dp[0] = 1;
    rep(i, 1, n){
        if(i - a[i] >= 1){
            dp[i] |= dp[i - a[i] - 1]|vis[i - a[i] - 1];
        }
        if(i + a[i] <= n){
            ky[i + a[i] + 1] |= ky[i]|dp[i - 1];
            if(ky[i]||dp[i - 1]) vis[i + a[i]] = 1;
        }
    }
    // rep(i, 1, n){
    //     if(i - a[i] >= 1) dp[i] |= dp[i - a[i] - 1];
    //     if(i + a[i] <= n) 
    //         dp[i + a[i]] |= dp[i - 1];
    // }
    if(dp[n]||ky[n + 1]) cout << "YES\n";
    else cout << "NO\n";
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