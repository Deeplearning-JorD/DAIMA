/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 16:22:25
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
int root[105], res[N];
struct Segtree{
    int l, r, st;
}tr[N << 5];
int idx;
void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].st = 1;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l);
    else modify(pos, mid + 1, r, tr[p].r);
}
void merge(int &x, int y, int l, int r){
    if(!x || !y) x |= y;
    else if(l == r) tr[x].st |= tr[y].st;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
    }
}
void update(int cl, int cr, int l, int r, int &p, int &pp){
    if(!p) return;
    if(cl <= l && r <= cr){
        merge(pp, p, l, r);
        p = 0;
        return;
    }
    if(!pp) pp = ++ idx;
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, tr[p].l, tr[pp].l);
    if(cr > mid) update(cl, cr, mid + 1, r, tr[p].r, tr[pp].r);
}
void dfs(int p, int l, int r, int now){
    if(!p) return;
    if(l == r){
        res[l] = now;
        return;
    }
    int mid = l + r >> 1;
    dfs(tr[p].l, l, mid, now);
    dfs(tr[p].r, mid + 1, r, now);
}
void Solve(){
    int n; cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        modify(i, 1, n, root[x]);
    }
    int m; cin >> m;
    while(m --){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        if(x != y) update(l, r, 1, n, root[x], root[y]);
    }
    rep(i, 1, 100) dfs(root[i], 1, n, i);
    rep(i, 1, n) cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}