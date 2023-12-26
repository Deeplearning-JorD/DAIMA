/*
 * @Author: JorD
 * @LastEditTime: 2022-12-20 20:10:50
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
ll d[N], h[N];
int n, m;
struct Segtree{
    ll sum, l, r;
}tr[N << 2];
void pushup(int l, int r, Segtree &u, Segtree &L, Segtree &R){
    int mid = l + r >> 1;
    u.sum = max({L.sum, R.sum, L.l + R.r});
    u.l = max(L.l, R.l);
    u.r = max(L.r, R.r);
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {h[l], h[l] - d[l - 1], h[l] + d[l - 1]};
        return;
    }    
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(l, r, tr[p], tr[p << 1], tr[p << 1|1]);
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    Segtree L, R, res;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    L = query(cl, cr, l, mid, p << 1);
    R = query(cl, cr, mid + 1, r, p << 1|1);
    pushup(l, r, res, L, R);
    return res;
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> d[i];
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n){
        d[i + n] = d[i];
        h[i + n] = h[i];
    }
    rep(i, 1, n * 2){
        d[i] += d[i - 1];
        h[i] *= 2;    
    }
    build(1, n * 2, 1);
    while(m --){
        int x, y;
        cin >> x >> y;
        if(x <= y){
            cout << query(y + 1, x + n - 1, 1, n * 2, 1).sum << endl;
        }else{
            cout << query(y + 1, x - 1, 1, n * 2, 1).sum << endl;
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