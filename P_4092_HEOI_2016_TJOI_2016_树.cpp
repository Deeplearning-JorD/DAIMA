/*
 * @Author: JorD
 * @LastEditTime: 2023-04-29 01:43:52
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
const int N = 2e5 + 10, inf = 1e9;
vector<int> son[N];
int siz[N], id[N], mp[N], idx;
void dfs(int now, int fa){
    id[now] = ++ idx;
    mp[idx] = now;
    siz[now] = 1;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
    }
}
struct Segtree{
    int mi, mx, tag;
}tr[N << 2];
void pushdown(int p){
    int& k = tr[p].tag;
    if(!k) return;
    tr[p << 1].mi = max(tr[p << 1].mi, k);
    tr[p << 1|1].mi = max(tr[p << 1|1].mi, k);
    tr[p << 1].mx = max(tr[p << 1].mx, k);
    tr[p << 1|1].mx = max(tr[p << 1|1].mx, k);
    tr[p << 1].tag = max(tr[p << 1].tag, k);
    tr[p << 1|1].tag = max(tr[p << 1|1].tag, k);
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].mi = max(tr[p].mi, k);
        tr[p].mx = max(tr[p].mx, k);
        tr[p].tag = max(tr[p].tag, k);
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p].mi = min(tr[p << 1].mi, tr[p << 1|1].mi);
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1|1].mx);
}
int query(int pos, int l, int r, int p){
    if(l == r) return mp[tr[p].mx];
    pushdown(p);
    int mid = l + r >> 1;
    if(pos <= mid) return query(pos, l, mid, p << 1);
    return query(pos, mid + 1, r, p << 1|1);
}
int n, m;
int st[N];
void add(int x){
    if(st[id[x]]) return;
    st[id[x]] = 1;
    update(id[x], id[x] + siz[x] - 1, 1, n, 1, id[x]);
}
void Solve(){
    cin >> n >> m;
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    add(1);
    while(m --){
        char op; 
        int x;
        cin >> op >> x;
        if(op == 'C'){
            add(x);
        }else{
            cout << query(id[x], 1, n, 1) << endl;
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