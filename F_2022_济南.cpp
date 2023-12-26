/*
 * @Author: JorD
 * @Date: 2023-11-07 18:11:49
 * @LastEditTime: 2023-11-09 02:06:05
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
#define int long long
const int N = 510, mod = 998244353;
vector<int> son[N];
int fac[N], depth[N], siz[N], d[N], w[N];
int res[N][N];
int n;
void dfs1(int now, int fa){
    w[now] = 1;
    siz[now] = 1;
    depth[now] = depth[fa] + 1;
    for(auto x : son[now])if(x != fa){
        dfs1(x, now);
        siz[now] += siz[x];
        d[now] ++;
        w[now] = 1ll * w[now] * w[x] % mod;
    }
    w[now] = 1ll * w[now] * fac[d[now]] % mod;
    // w[now] 表示以now为根的子树有多少种不同的dfs序
}
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll inv(ll x){
    return fpow(x, mod - 2, mod);
}
ll dp[N][N];
// dp[i][j] 表示除去以i为根的子树，order为j的方案数
void dfs(int now, int fa){
    ll mul = 1;
    vector<vector<int>> ap(d[now] + 1, vector<int> (siz[now] + 1));
    //ap[i][j]表示选了i个大小为j的方案数
    ap[0][1] = 1;
    for(auto x:son[now])if(x != fa){
        mul = mul * w[x] % mod;
        for(int i = d[now];i >= 1;i --){
            for(int j = siz[now];j >= siz[x];j --){
                ap[i][j] += ap[i - 1][j - siz[x]];
                ap[i][j] %= mod;
            }
        }
    }
    for(auto x:son[now])if(x != fa){
        for(int i = 1;i <= d[now];i ++){
            for(int j = siz[x];j <= siz[now];j ++){
                ap[i][j] = ap[i][j] - ap[i - 1][j - siz[x]] + mod;
                ap[i][j] %= mod;
            }
        }
        mul = mul * inv(w[x]) % mod;
        vector<int> c(siz[now] + 1);
        for(int i = 0;i <= d[now] - 1;i ++){
            for(int j = 0;j <= siz[now];j ++){
                //考虑清楚ap[i][j]所代表的含义，是方案数，每一个方案，都可以对应成固定的序列，然后进行排列
                c[j] += (fac[i] * fac[d[now] - 1 - i]) % mod * ap[i][j] % mod;
                c[j] %= mod;
            }
        }
        for(int j = 1;j <= siz[now];j ++){
            for(int i = j;i <= n;i ++){
                dp[x][i] += dp[now][i - j] * c[j] % mod * mul % mod;
                dp[x][i] %= mod;
            }
        }
        mul = mul * w[x] % mod;
        for(int i = d[now];i >= 1;i --){
            for(int j = siz[now];j >= siz[x];j --){
                ap[i][j] += ap[i - 1][j - siz[x]];
                ap[i][j] %= mod;
            }
        }
    }
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
    }
}
void Solve(){
    cin >> n;
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    fac[0] = 1;
    rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
    depth[0] = -1;
    dp[1][1] = 1;
    dfs1(1, 0);
    dfs(1, 0);
    rep(i, 1, n){
        rep(j, 1, n) cout << dp[i][j] * w[i] % mod << ' ';
        cout << endl;
    }
    return;
}
#undef int
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}