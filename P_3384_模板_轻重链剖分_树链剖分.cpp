/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 00:28:38
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
const int N = 1e6 + 10;
vector<int> son[N];
int w[N], id[N], siz[N], zson[N], depth[N];
int n, m, root;
ll mod;
int fat[N];
void dfs1(int now, int fa){
    int mx = 0;
    siz[now] = 1;
    depth[now] = depth[fa] + 1;
    fat[now] = fa;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if(siz[x] > mx){
            mx = siz[x];
            zson[now] = x;
        }
    }
    return;
}
int top[N], idx, mid[N];
void dfs2(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    mid[idx] = now;
    if(!zson[now]) return;
    dfs2(zson[now], now, T);
    for(auto x:son[now]){
        if(x == fa||x == zson[now]) continue;
        dfs2(x, now, x);
    }
}
int tr[N << 2], mark[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
    tr[p] %= mod;
}
void pushdown(int p, int l, int r){
    int mid = l + r >> 1;
    tr[p << 1] += mark[p] * (mid - l + 1);
    tr[p << 1|1] += mark[p] * (r - mid);
    mark[p << 1] += mark[p];
    mark[p << 1|1] += mark[p];
    mark[p] = 0;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = w[mid[l]] % mod;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void update(int l, int r, int cl, int cr, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] += k * (r - l + 1);
        mark[p] += k;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) update(l, mid, cl, cr, p << 1, k);
    if(cr > mid) update(mid + 1, r, cl, cr, p << 1|1, k);
    pushup(p);
}
ll query(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr){
        return tr[p]; 
    }
    int mid = l + r >> 1;
    ll res = 0;
    pushdown(p, l, r);
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1);
    // pushup(p);
    return res;
}
void update(int x, int y, int k){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        update(1, n, id[top[x]], id[x], 1, k);
        x = fat[top[x]]; // 跳LCA
    }
    if(depth[x] < depth[y]) swap(x, y);
    update(1, n, id[y], id[x], 1, k);
}
ll query(int x, int y){
    ll res = 0;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        res += query(1, n, id[top[x]], id[x], 1);
        res %= mod;
        x = fat[top[x]]; // 跳LCA
    }
    if(depth[x] < depth[y]) swap(x, y);
    res += query(1, n, id[y], id[x], 1);
    res %= mod;
    return res;
}
void update(int x, int k){
    update(1, n, id[x], id[x] + siz[x] - 1, 1, k);
}
ll query(int x){
    return query(1, n, id[x], id[x] + siz[x] - 1, 1) % mod;
}
void Solve(){
    cin >> n >> m >> root >> mod;
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs1(root, 0);
    dfs2(root, 0, root);
    build(1, n, 1);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int x, y, z;
            cin >> x >> y >> z;
            update(x, y, z);
        }else if(op == 2){
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }else if(op == 3){
            int x, y;
            cin >> x >> y;
            update(x, y);
        }else{
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}