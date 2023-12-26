/*
 * @Author: JorD
 * @LastEditTime: 2023-03-22 14:40:33
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
#define ls tr[p].l
#define rs tr[p].r
const int N = 2e5 + 10;
struct Segtree{
    int l, r;
    ll mx, mi;
}tr[N * 40];
int idx = 0;
void build(int &p){
    p = ++ idx;
    tr[p].mx = - 1e18;
    tr[p].mi = 1e18;
    return;
}
void pushup(int p){
    if(!tr[p].l) build(tr[p].l);
    if(!tr[p].r) build(tr[p].r);
    tr[p].mx = max(tr[ls].mx, tr[rs].mx);
    tr[p].mi = min(tr[ls].mi, tr[rs].mi);
    return;
}
void modify(int pos, int l, int r, int &p, ll k){
    if(!p) build(p);
    if(l == r){
        tr[p].mi = min(tr[p].mi, k);
        tr[p].mx = max(tr[p].mx, k);
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l, k);
    else modify(pos, mid + 1, r, tr[p].r, k);
    pushup(p);
}
pair<ll, ll> query(int cl, int cr, int l, int r, int p){
    if(!p) return {1e18, - 1e18};
    if(cl <= l && r <= cr){
        return {tr[p].mi, tr[p].mx};
    }
    int mid = l + r >> 1;
    ll L = 1e18, R = - 1e18;
    if(cl <= mid){
        auto t = query(cl, cr, l, mid, tr[p].l);
        L = min(L, t.first);
        R = max(R, t.second);
    }
    if(cr > mid){
        auto t = query(cl, cr, mid + 1, r, tr[p].r);
        L = min(L, t.first);
        R = max(R, t.second);    
    }
    return {L, R};
}
int root;
void Solve(){
    int n;
    cin >> n;
    ll mx = 1e18, my = -1e18;
    vector<pair<ll,ll>> a(n + 1);
    rep(i, 1, n){
        ll x, y;
        cin >> x >> y;
        modify(x, -1e9, 1e9, root, y);
        a[i] = {x, y};
        mx = min(mx, x);
        my = max(my, x);
    }
    int q;
    cin >> q;
    while(q --){
        int l, r;
        cin >> l >> r;
        if(a[l].first > a[r].first){
            cout << 0 << endl;
        }else{
            auto t = query(a[l].first, a[r].first, -1e9, 1e9, root);
            cout << (a[r].first - a[l].first) * (t.second - t.first) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}