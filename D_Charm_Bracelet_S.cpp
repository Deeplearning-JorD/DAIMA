/*
 * @Author: JorD
 * @LastEditTime: 2023-04-18 19:45:36
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
    vector<int> w(n + 1), d(n + 1);
    rep(i, 1, n){
        cin >> w[i] >> d[i];
    }
    vector<vector<int>> dp(2, vector<int> (m + 1));
    // dp[i][j]表示考虑前i个物品，体积为j时的最大价值
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if(j >= w[i])
            dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1)&1][j - w[i]] + d[i]);
        }
    }
    int res = 0;
    rep(i, 0, m) res = max(res, dp[n & 1][i]);
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