/*
 * @Author: JorD
 * @Date: 2023-10-15 20:18:42
 * @LastEditTime: 2023-10-17 00:00:34
 * 太爽了HHH
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
const int N = 6e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
int w[N];
vector<int> son[N];
int dfn[N], cnt, mp[N];
int fa[N][22], depth[N];
void dfs(int now){
    dfn[now] = ++ cnt;
    mp[cnt] = now;
    for(auto x:son[now]){
        depth[x] = depth[now] + 1;
        fa[x][0] = now;
        dfs(x);
    }
}
int lca(int x, int y){
    if(depth[x] > depth[y]) swap(x, y);
    for(int i = 20;i >= 0;i --)if(depth[fa[y][i]] >= depth[x]){
        y = fa[y][i];
    } 
    if(x == y) return x;
    for(int i = 20;i >= 0;i --)if(fa[x][i] != fa[y][i]){
        x = fa[x][i];
        y = fa[y][i];
    } 
    return fa[x][0];
}
const int inf = 1e9;
struct Segtree{
    int st, mi, mx, tag, l, r;
}tr[N << 2];
Segtree operator +(Segtree a, Segtree b){
    Segtree now = {a.st | b.st,inf,0,0,0,0};
    if(a.st >> 1 & 1){
        now.mi = min(now.mi, a.mi);
        now.mx = max(now.mx, a.mx);
    }
    if(b.st >> 1 & 1){
        now.mi = min(now.mi, b.mi);
        now.mx = max(now.mx, b.mx);
    }
    if(a.st && b.st){
        now.l = min(a.l, b.l);
        now.r = max(a.r, b.r);
    }else if(a.st){
        now.l = a.l;
        now.r = a.r;
    }else{
        now.l = b.l;
        now.r = b.r;
    }
    return now;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {1, inf, 0, 0, dfn[l], dfn[r]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void pushdown(int p){
    if(!tr[p].tag) return;
    tr[p << 1].tag = tr[p].tag;
    tr[p << 1|1].tag = tr[p].tag;
    tr[p << 1].st = tr[p].tag;
    tr[p << 1|1].st = tr[p].tag;
    if(tr[p].tag == 1){
        tr[p << 1].mi = inf;
        tr[p << 1].mx = 0;
        tr[p << 1|1].mi = inf;
        tr[p << 1|1].mx = 0;
    }else{
        tr[p << 1].mx = tr[p << 1].r;
        tr[p << 1].mi = tr[p << 1].l;
        tr[p << 1|1].mx = tr[p << 1|1].r;
        tr[p << 1|1].mi = tr[p << 1|1].l;
    }
    tr[p].tag = 0;
}
void update(int cl, int cr, int l, int r, int p, int x){
    if(cl <= l && r <= cr){
        tr[p].tag = x;
        tr[p].st = x;
        if(x == 1){
            tr[p].mi = inf;
            tr[p].mx = 0;
        }else{
            tr[p].mi = tr[p].l;
            tr[p].mx = tr[p].r;
        }
        return; 
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, x);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, x);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n << 1|1) f[i] = i;
    vector<array<int,3>> e(n - 1);
    for(auto &[c, x, y]:e) cin >> x >> y >> c;
    sort(e.begin(), e.end());
    int idx = n;
    for(auto [c, x, y] : e){
        x = find(x), y = find(y);
        if(x == y) continue;
        f[x] = f[y] = ++ idx;
        son[idx].push_back(x);
        son[idx].push_back(y);
        w[idx] = c;
    }
    dfs(idx);
    rep(i, 1, 20) rep(j, 1, idx)
    fa[j][i] = fa[fa[j][i - 1]][i - 1];
    build(1, idx, 1);
    while(m --){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            update(l, r, 1, idx, 1, 2);
        }else if(op == 2){
            int l, r; cin >> l >> r;
            update(l, r, 1, idx, 1, 1);
        }else{
            int x; cin >> x;
            if(tr[1].st >> 1 & 1){
                int mi = min(dfn[x], tr[1].mi), mx = max(dfn[x], tr[1].mx);
                int res = w[lca(mp[mi], mp[mx])];
                if(res == 0) res = -1;
                cout << res << endl;
            }
            else cout << -1 << endl;
        }
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