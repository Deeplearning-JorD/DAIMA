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
const int N = 3e5 + 10;
struct Segtree{
    int l, r;
    int ans, lans, rans, up, down;
    ll lv, rv, tag;
    friend Segtree operator +(Segtree L, Segtree R){
        Segtree now;
        if(L.down == L.r - L.l + 1 && L.rv > R.lv) now.down = L.down + R.down;
        else now.down = L.down;
        if(R.up == R.r - R.l + 1 && L.rv < R.lv) now.up = R.up + L.up;
        else now.up = R.up;
        now.l = L.l; now.r = R.r;
        now.lv = L.lv; now.rv = R.rv; 
        if(L.up == L.r - L.l + 1 && L.rv > R.lv)
            now.lans = L.lans + R.down;
        else if(L.up == L.r - L.l + 1 && L.rv < R.lv)
            now.lans = L.lans + R.lans;
        else if(L.lans == L.r - L.l + 1 && L.rv > R.lv)
            now.lans = L.lans + R.down;
        else now.lans = L.lans;
        if(R.down == R.r - R.l + 1 && L.rv > R.lv)
            now.rans = R.rans + L.rans;
        else if(R.down == R.r - R.l + 1 && L.rv < R.lv)
            now.rans = R.rans + L.up;
        else if(R.rans == R.r - R.l + 1 && L.rv < R.lv)
            now.rans = R.rans + L.up;
        else now.rans = R.rans; 
        now.ans = max(L.ans, R.ans);
        if(L.rv < R.lv) now.ans = max(now.ans, L.up + R.lans);
        if(L.rv > R.lv) now.ans = max(now.ans, R.down + L.rans);
        now.tag = 0;
        return now;
    }
}tr[N << 2];
void pushdown(int p){
    tr[p << 1].lv += tr[p].tag;
    tr[p << 1].rv += tr[p].tag;
    tr[p << 1|1].lv += tr[p].tag;
    tr[p << 1|1].rv += tr[p].tag;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
}
int a[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {l, r, 1, 1, 1, 1, 1, a[l], a[l], 0};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void update(int cl, int cr, int l, int r, int p, ll k){
    if(cl <= l && r <= cr){
        tr[p].lv += k, tr[p].rv += k, tr[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    int m;      
    cin >> m;
    while(m --){
        ll l, r, k;
        cin >> l >> r >> k;
        update(l, r, 1, n, 1, k);
        cout << tr[1].ans << endl;
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