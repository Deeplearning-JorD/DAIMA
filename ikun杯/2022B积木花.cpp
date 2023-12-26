/*
 * @Author: JorD
 * @LastEditTime: 2023-03-28 11:06:19
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
const int N = 10000010, mod = 1e9 + 7;
int dp[N][3];
void Solve(){
    int n; cin >> n;
    dp[0][0] = 1;
    for(int i = 0;i <= n;i ++){
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][0]) % mod;
        dp[i + 2][0] = (dp[i + 2][0] + dp[i][0]) % mod;
        dp[i + 2][1] = (dp[i + 2][1] + dp[i][0]) % mod;
        dp[i + 2][2] = (dp[i + 2][2] + dp[i][0]) % mod;
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % mod;
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][2]) % mod;
        dp[i + 1][1] = (dp[i + 1][1] + dp[i][1]) % mod;
        dp[i + 1][2] = (dp[i + 1][2] + dp[i][2]) % mod;       
    }
    cout << dp[n][0] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}