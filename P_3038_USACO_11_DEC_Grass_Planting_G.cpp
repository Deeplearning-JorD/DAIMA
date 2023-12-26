/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 14:46:52
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
int n, m;
int depth[N], zson[N], fat[N], siz[N];
void dfs1(int now, int fa){
    int mx = 0;
    siz[now] = 1;
    fat[now] = fa;
    depth[now] = depth[fa] + 1;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if(mx < siz[x]){
            mx = siz[x];
            zson[now] = x;
        }  
    }
}
int top[N], idx, id[N];
void dfs2(int now, int fa, int T){
    id[now] = ++ idx;
    top[now] = T;
    if(!zson[now]) return;
    dfs2(zson[now], now, T);
    for(auto x:son[now]){
        if(x == fa||x == zson[now]) continue;
        dfs2(x, now, x);
    }
}
int tr[N << 2], lazy[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void pushdown(int p, int l, int r){
    int mid = l + r >> 1;
    tr[p << 1] += lazy[p] * (mid - l + 1);
    tr[p << 1|1] += lazy[p] * (r - mid);
    lazy[p << 1] += lazy[p];
    lazy[p << 1|1] += lazy[p];
    lazy[p] = 0;
}
void update(int l, int r, int cl, int cr, int p, int k){
    if(l > r) return;
    if(cl <= l&&r <= cr){
        tr[p] += k * (r - l + 1);
        lazy[p] += k;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) update(l, mid, cl, cr, p << 1, k);
    if(cr > mid) update(mid + 1, r, cl, cr, p << 1|1, k);
    pushup(p);
}  
int query(int l, int r, int cl, int cr, int p){
    if(l > r) return 0;
    if(cl <= l&&r <= cr){
        return tr[p];
    }   
    int res = 0, mid = l + r >> 1;
    pushdown(p, l, r);
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
void update(int x, int y){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        update(1, n, id[top[x]], id[x], 1, 1);
        x = fat[top[x]];
    }
    if(depth[x] < depth[y]) swap(x, y);
    update(1, n, id[y] + 1, id[x], 1, 1);
}
int query(int x, int y){
    int res = 0;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        res += query(1, n, id[top[x]], id[x], 1);
        x = fat[top[x]];
    }
    if(depth[x] < depth[y]) swap(x, y);
    res += query(1, n, id[y] + 1, id[x], 1);
    return res;
}
void Solve(){
    cin >> n >> m;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    while(m --){
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'P'){
            update(x, y);
        }else{
            cout << query(x, y) << endl;
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