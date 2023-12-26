/*
 * @Author: JorD
 * @LastEditTime: 2023-07-19 01:29:45
 */
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
const ll inf = 2e18;
int a[N], n, m;
struct Segtr{
    ll sum;
    int cnt, tag, js;
}ftr[N << 2];
inline void fpushdown(int p){
    if(!ftr[p].js) return;
    ftr[p << 1].sum += 1ll * ftr[p].tag * ftr[p << 1].cnt;
    ftr[p << 1|1].sum += 1ll * ftr[p].tag * ftr[p << 1|1].cnt; 
    if(ftr[p].js & 1){
        ftr[p << 1].sum *= -1;
        ftr[p << 1|1].sum *= -1;
    }
    if(ftr[p << 1].js & 1) ftr[p << 1].tag -= ftr[p].tag;
    else ftr[p << 1].tag += ftr[p].tag;
    if(ftr[p << 1|1].js & 1) ftr[p << 1|1].tag -= ftr[p].tag;
    else ftr[p << 1|1].tag += ftr[p].tag;
    ftr[p << 1].js += ftr[p].js;
    ftr[p << 1|1].js += ftr[p].js;
    ftr[p].tag = 0;
    ftr[p].js = 0;
}
inline void fpushup(int p){
    ftr[p].cnt = ftr[p << 1].cnt + ftr[p << 1|1].cnt;
    ftr[p].sum = ftr[p << 1].sum + ftr[p << 1|1].sum;
}
// tag 是给儿子用的，sum保证不是被自己这一层更新，tag更新儿子的sum和tag
inline void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        ftr[p].cnt = 1;
        ftr[p].sum = k;
        return;
    }
    int mid = l + r >> 1;
    fpushdown(p);
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    fpushup(p);
}
inline void fupdate(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        ftr[p].js ++;
        ftr[p].sum -= 1ll * ftr[p].cnt * k;
        ftr[p].sum *= -1;
        if(ftr[p].js & 1) ftr[p].tag -= k;
        else ftr[p].tag += k;
        return;
    }
    fpushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) fupdate(cl, cr, l, mid, p << 1, k);
    if(cr > mid) fupdate(cl, cr, mid + 1, r, p << 1|1, k);
    fpushup(p);
}
inline ll fquery(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return ftr[p].sum;
    }
    int mid = l + r >> 1;
    fpushdown(p);
    ll res = 0;
    if(cl <= mid) res += fquery(cl, cr, l, mid, p << 1);
    if(cr > mid) res += fquery(cl, cr, mid + 1, r,p << 1|1);
    return res;
}
struct Segtree{
    int cnt, tag;
    ll sum, mi;
}tr[N << 2];
inline void pushup(int p){
    tr[p].sum = tr[p << 1].sum + tr[p << 1|1].sum;
    tr[p].cnt = tr[p << 1].cnt + tr[p << 1|1].cnt;
    tr[p].mi = min(tr[p << 1].mi, tr[p << 1|1].mi);
}
inline void pushdown(int p){
    if(!tr[p].tag) return;
    tr[p << 1].sum += 1ll * tr[p].tag * tr[p << 1].cnt;
    tr[p << 1|1].sum += 1ll * tr[p].tag * tr[p << 1|1].cnt;
    tr[p << 1].mi += tr[p].tag;
    tr[p << 1|1].mi += tr[p].tag;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
    return;
}
inline void build(int l, int r, int p){
    tr[p].tag = 0;
    ftr[p] = {0, 0, 0, 0};
    if(l == r){
        tr[p].cnt = 1;
        tr[p].mi = a[l];
        tr[p].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
inline void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].sum -= 1ll * tr[p].cnt * k;
        tr[p].tag -= k;
        tr[p].mi -= k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline void udown(int cl, int cr, int l, int r, int p, int k){
    if(tr[p].mi > k) return;
    if(l == r){
        modify(l, 1, n, 1, k - tr[p].sum);
        tr[p].cnt = 0;
        tr[p].sum = 0;
        tr[p].mi = inf;
        tr[p].tag = 0;
        return;
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) udown(cl, cr, l, mid, p << 1, k);
    if(cr > mid) udown(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].sum;
    }
    pushdown(p);
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op, l, r, x; 
        cin >> op >> l >> r;
        if(op == 1){
            cin >> x;
            fupdate(l, r, 1, n, 1, x);
            udown(l, r, 1, n, 1, x);
            update(l, r, 1, n, 1, x);
        }else{
            cout << (query(l, r, 1, n, 1) + fquery(l, r, 1, n, 1)) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t --)
    Solve();
    return 0;
}