/*
 * @Author: JorD
 * @Date: 2023-11-22 20:08:00
 * @LastEditTime: 2023-11-22 23:18:30
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 1e5 + 10, mod = 998244353;
ll dp[N], fz[N];
int mid[N];
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll fac[N], inv[N];
ll C(int n, int m){
   return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
vector<int> son[N];
void dfs(int now, int fa){
    dp[now] = 1;
    ll mus = 1, cnt = 0, mul = 1, can = 0;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        if(!mid[x]) cnt ++;
        mul = mul * dp[x] % mod;
    }
    if(cnt % 2 == 0){
        dp[now] = fz[cnt] * mul % mod;
    }else{
        mid[now] = 1;
        dp[now] = fz[cnt - 1] * cnt % mod * mul % mod;
    }
}
void Solve(){
    int n; cin >> n;
    for(int i = 2;i <= n;i ++){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    cout << dp[1]; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    fac[0] = 1; inv[0] = 1;
    for(int i = 1;i < N;i ++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * fpow(i, mod - 2, mod) % mod;
    }
    ll up = 1, down = 1;
    fz[0] = 1;
    for(int i = 2;i < N;i += 2){
        up = up * C(i, 2) % mod;
        down = fpow(fac[i / 2], mod - 2, mod) % mod;
        fz[i] = up * down % mod;
    }
    Solve();
    return 0;
}