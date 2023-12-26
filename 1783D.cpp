/*
 * @Author: JorD
 * @LastEditTime: 2023-01-12 21:58:40
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
const int mod = 998244353, N = 310, M = 300 * 300 * 2, D = 300 * 300;
int n, a[N];
int dp[N][M + 10];
void Solve(){
    //每一次选择都唯一确定了序列，所以说不管我们怎么操作，他都可以辨认出不同的序列
    //我们可以直接通过最后一位是什么来进行计数。
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    dp[2][a[2] + D] = 1;
    for(int i = 2;i <= n - 1;i ++){
        for(int j = 0;j <= 2 * D;j ++){
            // j - D;
            if(j != D){
                dp[i + 1][a[i + 1] + (j - D) + D] = (dp[i][j] + dp[i + 1][a[i + 1] + (j - D) + D]) % mod;
                dp[i + 1][a[i + 1] - (j - D) + D] = (dp[i][j] + dp[i + 1][a[i + 1] - (j - D) + D]) % mod; 
            }else dp[i + 1][a[i + 1] - (j - D) + D] = (dp[i + 1][a[i + 1] - (j - D) + D] + dp[i][j]) % mod;
        }    
    }
    int res = 0;
    for(int i = 0;i <= 2 * D;i ++){res += dp[n][i];res %= mod;}
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}