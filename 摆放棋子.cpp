/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 19:45:52
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
const ll MOD = 1e8;
ll dp[5][210][50][210];
void Solve(){
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    //黑白、放了几个。
    // dp[1][1][1][1] = 1;
    // dp[0][1][1][1] = 1;
    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;
    rep(i, 1, n1 + n2){
        for(int j = max(0ll, i - k2 - 1);j < i - 1;j ++){
            for(int k = 0;k <= k1;k ++){
                for(int use = 0;use < n1;use ++){
                    dp[0][i][1][use + 1] += dp[0][j][k][use];
                    dp[0][i][1][use + 1] %= MOD;
                }
            }
        }
        for(int k = 0;k < k1;k ++){
            for(int use = 0;use < n1;use ++){
                dp[0][i][k + 1][use + 1] += dp[0][i - 1][k][use];
                dp[0][i][k + 1][use + 1] %= MOD;
            }
        }
        for(int j = max(0ll, i - k1 - 1);j < i - 1;j ++){
            for(int k = 0;k <= k2;k ++){
                for(int use = 0;use < n2;use ++){
                    dp[1][i][1][use + 1] += dp[1][j][k][use];
                    dp[1][i][1][use + 1] %= MOD;
                }
            }
        }
        for(int k = 0;k < k2;k ++){
            for(int use = 0;use < n2;use ++){
                dp[1][i][k + 1][use + 1] += dp[1][i - 1][k][use];
                dp[1][i][k + 1][use + 1] %= MOD;
            }
        }
        // cout << dp[1][2][1][1] << ' ' << dp[0][2][1][1] << endl;
    }
    ll res = 0;
    for(int i = 1;i <= k1;i ++){
        res += dp[0][n1 + n2][i][n1];
        res %= MOD;
    }
    for(int i = 1;i <= k2;i ++){
        res += dp[1][n1 + n2][i][n2];
        res %= MOD;
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