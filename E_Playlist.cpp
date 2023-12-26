/*
 * @Author: JorD
 * @LastEditTime: 2023-10-08 17:04:18
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
const int mod = 998244353;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n, x;
    cin >> n >> x;
    vector<int> t(n + 1);
    rep(i, 1, n) cin >> t[i];
    vector<ll> dp(x + 1);1
    dp[0] = 1;
    ll p = fpow(n, mod - 2, mod);
    rep(i, 1, x){
        rep(j, 1, n)if(i - t[j] >= 0){
            dp[i] += dp[i - t[j]] * p % mod;
            dp[i] %= mod; 
        }
    }
    ll res = 0;
    for(int i = x;i >= 0;i --){
        if(i + t[1] >= x + 1){
            res = (res + dp[i] * p % mod) % mod;
        }
    }
    cout << res;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}