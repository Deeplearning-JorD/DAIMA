#pragma GCC optimize(2)
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
const int N = 5e5 + 10;
struct Segtree{
    int r0, r1, p0, s0, p1, s1, tag;
    int l, r;
}tr[N << 2];
void pushdown(int p){
    if(!tr[p].tag) return;
    auto &l = tr[p << 1], &r = tr[p << 1|1];
    l.tag ^= tr[p].tag;
    r.tag ^= tr[p].tag;
    swap(l.p0, l.p1);
    swap(l.s0, l.s1);
    swap(l.r0, l.r1);
    swap(r.p0, r.p1);
    swap(r.s0, r.s1);
    swap(r.r0, r.r1);
    tr[p].tag = 0;
}
Segtree operator +(Segtree a, Segtree b){
    Segtree now;
    now.r1 = max({a.r1, b.r1, a.s1 + b.p1});
    now.r0 = max({a.r0, b.r0, a.s0 + b.p0});
    if(a.r - a.l + 1 == a.p0) now.p0 = a.p0 + b.p0;
    else now.p0 = a.p0;
    if(b.r - b.l + 1 == b.s0) now.s0 = a.s0 + b.s0;
    else now.s0 = b.s0;
    if(a.r - a.l + 1 == a.p1) now.p1 = a.p1 + b.p1;
    else now.p1 = a.p1;
    if(b.r - b.l + 1 == b.s1) now.s1 = a.s1 + b.s1;
    else now.s1 = b.s1;
    now.tag = 0;
    now.l = a.l;
    now.r = b.r;
    return now;
}
string s;
void build(int l, int r, int p){
    if(l == r){
        if(s[l] == '1') tr[p] = {0, 1, 0, 0, 1, 1, 0, l, r};
        else tr[p] = {1, 0, 1, 1, 0, 0, 0, l, r};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void update(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        tr[p].tag ^= 1;
        swap(tr[p].s0, tr[p].s1);
        swap(tr[p].p0, tr[p].p1);
        swap(tr[p].r0, tr[p].r1);
        return;
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    return query(cl, cr, l, mid, p << 1) + query(cl, cr, mid + 1, r, p << 1|1);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    build(1, n, 1);
    while(m --){
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) update(l, r, 1, n, 1);
        else cout << query(l, r, 1, n, 1).r1 << endl;
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