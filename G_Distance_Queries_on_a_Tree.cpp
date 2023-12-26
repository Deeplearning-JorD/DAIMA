/*
 * @Author: JorD
 * @LastEditTime: 2023-03-21 00:45:34
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
const int N = 2e5 + 10;
ll tr[N << 2];
vector<pair<int,int>> son[N];
int depth[N], zson[N], siz[N], fat[N], w[N], n, fw[N];
map<pair<int,int>,int> q;
void dfs(int now, int fa){
    depth[now] = depth[fa] + 1;
    siz[now] = 1;
    fat[now] = fa; 
    for(auto [x, y]:son[now])if(x != fa){
        fw[q[{now, x}]] = x;
        w[x] = y;
        dfs(x, now);
        siz[now] += siz[x];
        if(siz[x] > siz[zson[now]]) zson[now] = x;
    }
}
int id[N], fid[N], top[N], idx;
void dfs1(int now, int fa, int T){
    id[now] = ++ idx;
    fid[idx] = now;
    top[now] = T;
    if(zson[now]) dfs1(zson[now], now, T);
    for(auto [x, y]:son[now])if(x != fa && x != zson[now]){
        dfs1(x, now, x);
    }
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = w[fid[l]];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);  
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
ll query(int u, int v){
    ll res = 0;
    while(top[u] != top[v]){
        if(depth[top[u]] < depth[top[v]]) swap(u, v);
        int x = u;
        res += query(id[top[u]], id[u], 1, n, 1);
        u = fat[top[u]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    res += query(id[u], id[v], 1, n, 1);
    res -= query(id[u], id[u], 1, n, 1);
    return res;
}
void Solve(){
    cin >> n;
    rep(i, 1, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        son[u].push_back({v, w});
        son[v].push_back({u, w});
        q[{u, v}] = i;
        q[{v, u}] = i;
    }   
    int m;
    cin >> m;
    dfs(1, 0);
    dfs1(1, 0, 1);
    build(1, n, 1);
    while(m --){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            modify(id[fw[l]], 1, n, 1, r);
        }else{
            cout << query(l, r) << endl;
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