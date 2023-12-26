/*
 * @Author: JorD
 * @LastEditTime: 2023-04-25 21:05:10
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
const int N = 510;
int dp[N][N];
int a[N];
// dp[i][j][k]表示考虑前i个程序员一共打了j行代码bug数为k的方案数
void Solve(){
    int n, m, b, mm;
    cin >> n >> m >> b >> mm;
    const int mod = mm;
    rep(i, 1, n) cin >> a[i];
    dp[0][0] = 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            for(int k = a[i];k <= b;k ++){
                if(j >= 1 && k >= a[i])
                dp[j][k] += dp[j - 1][k - a[i]];
                dp[j][k] %= mod;
            }
        }
    }
    int res = 0;
    for(int k = 0;k <= b;k ++){
        res = (res + dp[m][k]) % mod;
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