/*
 * @Author: JorD
 * @LastEditTime: 2022-12-28 16:21:13
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
const int N = 1e5 + 10;
struct Segtree{
    int l, r;
    pair<int,int> val;
}tr[N * 70];
int res[N], root[N], idx;
pair<int,int> max(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first) return a;
    if(a.first == b.first) return a.second < b.second ? a : b;
    return b;
}
void pushup(int p){
    tr[p].val = max(tr[tr[p].l].val, tr[tr[p].r].val);
}
void modify(int pos, int l, int r, int &p, int k){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].val.first += k;
        tr[p].val.second = pos;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l, k);
    else modify(pos, mid + 1, r, tr[p].r, k);
    pushup(p);
}
void merge(int &x, int y, int l = 1, int r = N){
    if(!x||!y) x |= y;
    else if(l == r) tr[x].val.first += tr[y].val.first;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
vector<int> son[N];
int f[N][20], depth[N];
void dfs1(int now, int fa){
    f[now][0] = fa;
    depth[now] = depth[fa] + 1;
    for(int i = 1;i <= 17;i ++)
        f[now][i] = f[f[now][i - 1]][i - 1];
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
    }
}
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = 17;i >= 0;i --)
        if(depth[f[a][i]] >= depth[b]) a = f[a][i];
    if(a == b) return a;
    for(int i = 17;i >= 0;i --){
        if(f[a][i] == f[b][i]) continue;
        a = f[a][i];
        b = f[b][i];
    }
    return f[a][0];
}
void dfs(int now, int fa){
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        merge(root[now], root[x]);
    }
    res[now] = tr[root[now]].val.second;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs1(1, 0);
    while(m --){
        int l, r, z;
        cin >> l >> r >> z;
        int fa = lca(l, r);
        modify(z, 1, N, root[l], 1);
        modify(z, 1, N, root[r], 1);
        modify(z, 1, N, root[fa], -1);
        modify(z, 1, N, root[f[fa][0]], -1);
    }
    dfs(1, 0);
    rep(i, 1, n) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}