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
const int N = 5e5 + 10;
vector<int> son[N];
int res[N];
struct edge{
    int op, v, x;
};
int w[N], id[N], siz[N], zson[N], depth[N];
int n, m, root = 1;
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
ll tr[N << 2], mark[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
    mark[p] = 0;
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
    mark[p] = 0;
    tr[p]=0;
    if(l == r){
        tr[p] = 0;
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
void update(int x, int k){
    // cout << 1 << ' ' << n << ' ' << id[x] << ' ' << id[x] + siz[x] - 1 << ' ' << 1 << ' ' << k << endl;
    update(1, n, id[x], id[x] + siz[x] - 1, 1, k);
}
ll query(int x){
    return query(1, n, id[x], id[x] + siz[x] - 1, 1);
}
void Solve(){
    int m; cin >> m;
    vector<edge> q(m + 1);
    n = 1;
    rep(i, 1, m){
        ll op, v, x;
        cin >> op >> v;
        if(op == 1){
            q[i] = {op, v, 0};
            n ++;
            // cout << v << ' ' << n << endl;
            son[v].push_back(n);
            son[n].push_back(v);
        }else{
            cin >> x;
            q[i] = {op, v, x};
        }
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    build(1, n, 1);
    // cout << n << endl;
    int nc = n;
    for(int i = m;i >= 1;i --){
        auto [op, v, x] = q[i];
        if(op == 2){
            // cout << v << ' ';
            // cout << id[v] << ' ' << siz[v] << endl; 
            update(v, x);
        }else{
            res[nc] = query(1,n,id[nc],id[nc],1);
            nc--;
        }
    }
    res[1] = query(1, n, id[1],id[1], 1);
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    rep(i, 0,2 *n){
        idx =0 ;
        fat[i]=0;
    siz[i] = 0;
    zson[i]=0;
    top[i]=0;
    mid[i]=0;
    son[i].clear();
    id[i]=0;
    depth[i]=0;
    w[i]=0;
    }
    // build(1, n, 1);
    return;
}
#undef int
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}