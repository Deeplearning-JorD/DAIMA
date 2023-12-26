/*
 * @Author: JorD
 * @LastEditTime: 2023-02-04 00:45:47
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
    vector<vector<ll>> dp(n + 1, vector<ll> (4, -1e18));
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    dp[2][0] = a[1] + a[2];
    dp[2][3] = - a[1] - a[2];
    rep(i, 3, n){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][3], dp[i - 1][1]) + 2 * a[i - 1] - a[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + a[i];
        dp[i][3] = max(dp[i - 1][0], dp[i - 1][2]) - 2 * a[i - 1] - a[i];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}