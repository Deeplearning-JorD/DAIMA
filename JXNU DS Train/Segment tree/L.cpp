/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 00:39:25
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
struct Segtree{
    int l, r;
    ll ans;
    int s, e;
}tr[N << 2];
int a[N];
void pushup(int l, int r, int p){
    int mid = l + r >> 1;
    tr[p].s = tr[p << 1].s;
    tr[p].e = tr[p << 1|1].e;
    if(tr[p << 1].e > tr[p << 1|1].s){
        tr[p].l = tr[p << 1].l;
        tr[p].r = tr[p << 1|1].r;
        tr[p].ans = tr[p << 1].ans + tr[p << 1|1].ans;
    }else{
        tr[p].ans = tr[p << 1].ans + tr[p << 1|1].ans + 1ll * tr[p << 1].r * tr[p << 1|1].l;
        if(mid - l + 1 == tr[p << 1].r) 
            tr[p].l = tr[p << 1].r + tr[p << 1|1].l;
        else tr[p].l = tr[p << 1].l;
        if(r - mid == tr[p << 1|1].l)
            tr[p].r = tr[p << 1|1].l + tr[p << 1].r;
        else tr[p].r = tr[p << 1|1].r;
    }
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {1, 1, 1, a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(l, r, p);
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = {1, 1, 1, k, k};
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    pushup(l, r, p);
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    else if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    auto L = query(cl, cr, l, mid, p << 1), R = query(cl, cr, mid + 1, r, p << 1|1);
    Segtree res;
    res.e = R.e;
    res.s = L.s;
    if(L.e > R.s){
        res.l = L.l;
        res.r = R.r;
        res.ans = L.ans + R.ans;
    }else{
        res.ans = L.ans + R.ans + 1ll * L.r * R.l;
        if(mid - l + 1 == L.r) 
            res.l = L.r + R.l;
        else res.l = L.l;
        if(r - mid == R.l)
            res.r = R.l + L.r;
        else res.r = R.r;
    }
    return res; 
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            modify(x, 1, n, 1, y);
        }else{
            cout << query(x, y, 1, n, 1).ans << endl;
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