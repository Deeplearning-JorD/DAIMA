/*
 * @Author: JorD
 * @Date: 2023-11-18 00:01:15
 * @LastEditTime: 2023-11-18 01:16:19
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
const int N = 2e5 + 10;
vector<vector<int>> son; 
#define ls tr[p].l
#define rs tr[p].r
struct Segtree{
    int l, r;
    int cnt;
}tr[N * 70];
int res[N], root[N], idx, n;
void pushup(int p){
    tr[p].cnt = tr[ls].cnt + tr[rs].cnt;
}
void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt = 1;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l);
    else modify(pos, mid + 1, r, tr[p].r);
    pushup(p);
}
void merge(int &x, int y, int l = 1, int r = n){
    if(!x||!y) x |= y;
    else if(l == r) tr[x].cnt += tr[y].cnt;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
int query(int cl, int cr, int l, int r, int p){
    if(!p) return 0;
    if(cl <= l && r <= cr){
        return tr[p].cnt;
    }
    int mid = l + r >> 1;
    if(cl > mid) return query(cl, cr, mid + 1, r, rs);
    if(cr <= mid) return query(cl, cr, l, mid, ls);
    return query(cl, cr, mid + 1, r, rs) + query(cl, cr, l, mid, ls);
}
pair<int,int> we[N];
vector<int> que[N];
void dfs(int now, int fa){
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        merge(root[now], root[x]);
    }
    for(auto i:que[now]){
        auto [l, r] = we[i];
        if(query(l, r, 1, n, root[now])) res[i] = 1;
        else res[i] = 0;
    }
}
void Solve(){
    int q; cin >> n >> q;
    son.resize(n + 1);
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    rep(i, 1, n){
        int x; cin >> x;
        modify(i, 1, n, root[x]);
    }
    // build(1, n, 1);
    rep(i, 1, q){
        int l, r, x; cin >> l >> r >> x;
        que[x].push_back(i);
        we[i] = {l, r};
    }
    dfs(1, 0);
    rep(i, 1, n){
        que[i].clear();
        root[i] = 0;
    }
    for(int i = 1;i <= idx;i ++){
        tr[i].l = 0;
        tr[i].r = 0;
    }
    son.clear();
    idx = 0;
    rep(i, 1, q)if(res[i]) cout << "YES\n";
    else cout << "NO\n";
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}