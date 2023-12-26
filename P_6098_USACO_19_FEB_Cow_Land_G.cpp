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
int w[N];
vector<int> son[N];
int fat[N], zson[N], siz[N], depth[N];
void dfs(int now, int fa){
    siz[now] = 1;
    fat[now] = fa;
    depth[now] = depth[fa] + 1;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
        if(siz[zson[now]] < siz[x]) zson[now] = x;
    }
}
int top[N], id[N], mp[N], idx;
void dfs1(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    mp[idx] = now;
    if(!zson[now]) return;
    dfs1(zson[now], now, T);
    for(auto x:son[now])if(x != fa && x != zson[now]){
        dfs1(x, now, x);
    }
}
inline int LCA(int x, int y){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        x = fat[top[x]];
    }
    if(depth[x] > depth[y]) swap(x, y);
    return x;
}
int tr[N << 2];
inline void build(int l, int r, int p){
    if(l == r){
        tr[p] = w[mp[l]];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] ^ tr[p << 1|1];
}
inline void modify(int pos, int l, int r, int p){
    if(l == r){
        tr[p] = w[mp[l]];
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1);
    else modify(pos, mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] ^ tr[p << 1|1];
}
int n, q;
inline int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    int L = query(cl, cr, l, mid, p << 1), R = query(cl, cr, mid + 1, r, p << 1|1);
    return L ^ R;
}
inline int calc(int x, int fa){
    int res = 0;
    while(top[x] != top[fa]){
        res ^= query(id[top[x]], id[x], 1, n, 1);
        x = fat[top[x]];
    }
    res ^= query(id[fa], id[x], 1, n, 1);
    return res;
}
void Solve(){
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    build(1, n, 1);
    while(q --){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            w[l] = r;
            modify(id[l], 1, n, 1);
        }else{
            int lca = LCA(l, r);
            int res = calc(l, lca) ^ calc(r, lca) ^ w[lca];
            cout << res << endl;
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