/*
 * @Author: JorD
 * @Date: 2023-11-24 23:35:58
 * @LastEditTime: 2023-11-24 23:49:36
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
const int N = 3e5 + 10;
struct Segtree{
    int mx, tag;
}tr[N << 2];
void build(int l, int r, int p){
    tr[p] = {0, 0};
    if(l == r) return;
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
}
void pushdown(int p){
    tr[p << 1].mx = max(tr[p << 1].mx, tr[p].tag);
    tr[p << 1].tag = max(tr[p << 1].tag, tr[p].tag);
    tr[p << 1|1].mx = max(tr[p << 1|1].mx, tr[p].tag);
    tr[p << 1|1].tag = max(tr[p << 1|1].tag, tr[p].tag);
    tr[p].tag = 0;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl > cr)  return ;
    if(cl <= l && r <= cr){
        tr[p].tag = max(tr[p].tag, k);
        tr[p].mx = max(tr[p].mx, k);
        return;
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1|1].mx);
}
int query(int pos, int l, int r, int p){
    if(l == r) return tr[p].mx;
    pushdown(p);
    int mid = l + r >> 1;
    if(pos <= mid) return query(pos, l, mid, p << 1);
    return query(pos, mid + 1, r, p << 1|1);
}
void Solve(){
    int n; cin >> n;
    build(1, n, 1);
    rep(i, 1, n){
        int x; cin >> x;
        update(1, i - 1, 1, n, 1, x + i - 1);
        update(i, i, 1, n, 1, x);
        update(i + 1, n, 1, n, 1, x + n - i);
    }
    int res = 2e9;
    rep(i, 1, n) res = min(res, query(i, 1, n, 1));
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}