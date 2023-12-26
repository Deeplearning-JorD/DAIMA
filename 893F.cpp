/*
 * @Author: JorD
 * @LastEditTime: 2023-01-19 06:03:54
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
const int N = 1e5 + 10, inf = 1e5;
struct Segtree{
    int l, r, val;
}tr[N * 23];
int c[N], mp[N], id[N], cnt;
vector<int> son[N];
int depth[N], siz[N], mx;
void dfs(int now, int fa){
    depth[now] = depth[fa] + 1;
    mx = max(depth[now], mx);
    siz[now] = 1;
    id[now] = ++ cnt;
    mp[cnt] = now;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
    }
}
inline void pushup(int p){
    tr[p].val = min(tr[tr[p].l].val, tr[tr[p].r].val);
}
int root[N], idx;
inline void update(int l, int r, int &clone, int p, int k){
    clone = ++ idx;
    tr[clone] = tr[p];
    if(l == r){
        tr[clone].val = c[mp[k]];
        return;
    }
    int mid = l + r >> 1;
    if(k <= mid) update(l, mid, tr[clone].l, tr[p].l, k);
    else update(mid + 1, r, tr[clone].r, tr[p].r, k);
    pushup(clone);
}
inline int query(int cl, int cr, int l, int r, int p){
    if(!p) return 2e9;
    if(cl <= l && r <= cr){
        return tr[p].val;
    }
    int mid = l + r >> 1;
    int res = 2e9;
    if(cl <= mid) res = min(res, query(cl, cr, l, mid, tr[p].l));
    if(cr > mid) res = min(res, query(cl, cr, mid + 1, r, tr[p].r));
    return res;
}
void Solve(){
    //就算是深度相同也要先重新建点，不然就会修改到历史版本
    int n, rt;
    cin >> n >> rt;
    rep(i, 1, n) cin >> c[i];
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(rt, 0);
    queue<int> q;
    q.push(rt);
    tr[0].val = 2e9;
    while(q.size()){
        auto t = q.front(); q.pop();
        if(!root[depth[t]]) update(1, n, root[depth[t]], root[depth[t] - 1], id[t]);
        else update(1, n, root[depth[t]], root[depth[t]], id[t]);
        for(auto x:son[t])if(depth[x] > depth[t]){
            q.push(x);
        }
    }
    int m;
    cin >> m;
    int res = 0;
    while(m --){
        int u, k;
        cin >> u >> k;
        u = (u + res) % n + 1;
        k = (k + res) % n;
        res = query(id[u], id[u] + siz[u] - 1, 1, n, root[min(depth[u] + k, mx)]);  
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