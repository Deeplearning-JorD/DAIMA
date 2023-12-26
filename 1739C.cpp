/*
 * @Author: JorD
 * @LastEditTime: 2022-09-30 19:31:09
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
const int mod = 998244353;
ll qsm(ll a,ll k){
    ll res=1;
    for(;k;k>>=1){
        if(k&1) res=res*a%mod;
        a=a*(ll)a%mod;
    }
    return res;
}
ll get(int m, int n){
    ll sum = 1;
    if(m == 0) return 1;
    rep(i, 1, n) sum = (sum * i) % mod;
    ll sum1 = 1;
    rep(i, 1, m) sum1 = (sum1 * i) % mod;
    ll sum2 = 1;
    rep(i, 1, n - m) sum2 = (sum2 * i) % mod;
    sum1 = sum1 * sum2 % mod;
    sum = (sum * qsm(sum1, mod - 2)) % mod;
    return sum;
}
ll dp[100][2];
void Solve(){
    int n;
    cin >> n;
    cout << dp[n][0] << ' ' << dp[n][1] << ' ' << 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    dp[2][0] = 1;
    dp[2][1] = 0;
    for(int i = 4; i <= 60;i += 2){
        dp[i][0] = get(i/2 - 1, i - 1) + dp[i - 2][1];
        dp[i][0] %= mod;
        dp[i][1] = get(i/2, i) - 1 - dp[i][0]; 
        dp[i][1] %= mod;
        dp[i][1] += mod;
        dp[i][1] %= mod;
    }
    while(t --)
    Solve();
    return 0;
}