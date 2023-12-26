/*
 * @Author: JorD
 * @LastEditTime: 2022-08-20 15:47:31
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
const int MOD = 1e9 + 7, N = 1e5 + 10;
ll f[N];
int js;
int qsm(int a,int b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % MOD;
        a = (ll) a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll res = 1;
void Solve(){
    int n;
    cin >> n;
    vector<vector<int>> son(n+1);
    rep(i, 2, n){
        int x; cin >> x;
        son[x].push_back(i);
    }
    vector<int> num(n+1);
    vector<ll> dp(n+1, 1);
    function<void(int)> dfs = [&](int now){
        for(auto x:son[now]){
            dfs(x);
            num[now] += num[x];
            dp[now] = dp[now] * dp[x] % MOD * qsm(f[num[x]], MOD - 2) % MOD;
        }
        dp[now] = dp[now] * f[num[now]] % MOD;
        num[now] += 1;
    };
    dfs(1);
    res = res * dp[1] % MOD * qsm(f[num[1]], MOD - 2) % MOD;
    rep(i, 1, n) res = res * (++js) % MOD;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    f[0] = 1;
    rep(i, 1, 1e5) f[i] = f[i-1] * i % MOD;
    int t; cin>>t;
    while(t --)
    Solve();
    cout << res;
    return 0;
}