/*
 * @Author: JorD
 * @LastEditTime: 2023-08-27 17:30:29
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n; 
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> f[i][j];
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>> (2, vector<int> (3)));
    //[1]表示这个点被影响了几次
    int ans = 0;
    rep(i, 1, n){
        for(int j = 1;j <= n;j ++){
            int now = 0;
            now += dp[j][i&1][0] = dp[j+1][(i+1)&1][0];
            now += dp[j][i&1][2] = dp[j-1][(i+1)&1][2];
            now += dp[j][(i+1)&1][1];
            f[i][j] ^= now&1;
            dp[j][i&1][1] = now;
            if(f[i][j]&1){
                dp[j][i&1][0] ++;
                dp[j][i&1][1] ++;
                dp[j][i&1][2] ++;
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}