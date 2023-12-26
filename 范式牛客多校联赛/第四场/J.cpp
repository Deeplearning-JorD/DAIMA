/*
 * @Author: JorD
 * @LastEditTime: 2023-07-28 20:05:58
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
const int N = 10020 + 10, H = 5010, mod = 998244353;
int dp[5010][N];
void Solve(){   
    // dp[i][j]表示以第i个数结尾的最小后缀和为j的方案数
    // dp[i][min(k, j + k)] += dp[i - 1][j]
    int n, m; cin >> n >> m;
    rep(i, - m, m) dp[1][i + H] = 1;
    for(int i = 2;i <= n;i ++){
        int sum = 0;
        for(int j = m, k = - m;k < 0;k ++,j --){
            sum = (sum + dp[i - 1][j + H]) % mod;
            dp[i][k + H] = sum;
        }
        for(int j = 0, k = m;k >= 0;k --, j --){
            sum = (sum + dp[i - 1][j + H]) % mod;
            dp[i][k + H] = sum;
        }
    }
    int res = 0;
    for(int j = - m;j <= m;j ++){
        res = (res + dp[n][j + H]) % mod;
    }
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