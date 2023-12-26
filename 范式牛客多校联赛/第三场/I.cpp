/*
 * @Author: JorD
 * @LastEditTime: 2023-07-30 16:36:45
 * 跳跳树
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
const int N = 5e5 + 10;
ll w[N];
vector<ll> son[N];
int fa[21][N]; // fa[i][j] j 的 2^i 的祖先
ll pre[21][N]; // pre[i][j] j 到 j 的 2^i 祖先的&值
int ch[21][N]; // ch[i][j] j 换了 2^i 次颜色能到达的点
int depth[N];
void dfs(int now, int fat){
    depth[now] = depth[fat] + 1;
    fa[0][now] = fat;
    pre[0][now] = w[now] & w[fat];
    for(int i = 1;i <= 20;i ++){
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
        pre[i][now] = pre[i - 1][fa[i - 1][now]] & pre[i - 1][now];
    }
    for(auto x : son[now])if(x != fat){
        dfs(x, now);
    }
}
int lca(int x, int y){
    if(depth[x] > depth[y]) swap(x, y);
    for(int i = 20;i >= 0;i --)
        if(depth[fa[i][y]] >= depth[x]) 
            y = fa[i][y];
    if(x == y) return x;
    for(int i = 20;i >= 0;i --)if(fa[i][x] != fa[i][y]){
        x = fa[i][x];
        y = fa[i][y];
    }
    return fa[0][x];
}
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }   
    dfs(1, 0);
    for(int i = 1;i <= n;i ++){
        int now = i;
        ll val = 1ll << 61;
        val --;
        for(int j = 20;j >= 0;j --){
            if((pre[j][now] & val) == 0) continue;
            val &= pre[j][now];
            now = fa[j][now];
        }
        ch[0][i] = now;
    }
    ch[0][1] = 0;
    for(int i = 1;i <= 20;i ++){
        for(int j = 1;j <= n;j ++){
            ch[i][j] = ch[i - 1][ch[i - 1][j]];
        }
    }
    while(m --){
        int u, v; cin >> u >> v;
        int LCA = lca(u, v);
        ll res = depth[u] + depth[v] - 2 * depth[LCA];
        for(int i = 20;i >= 0;i --){
            if(depth[ch[i][u]] > depth[LCA] && u != ch[i][u]){
                res += 1 << i;
                u = ch[i][u];
            }
            if(depth[ch[i][v]] > depth[LCA] && v != ch[i][v]){
                res += 1 << i;
                v = ch[i][v];
            }
        }
        ll l = 1ll << 61, r = 1ll << 61; l --, r --;
        for(int i = 20;i >= 0;i --){
            if(depth[fa[i][u]] >= depth[LCA]){
                r &= pre[i][u];
                if(!r) break;
                u = fa[i][u];
            }
            if(depth[fa[i][v]] >= depth[LCA]){
                l &= pre[i][v];
                if(!l) break;
                v = fa[i][v];
            }
        }
        if((l & r) == 0) res += 2;
        else res ++;
        res --;
        if(u != LCA || v != LCA) res = -1;
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}