/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 20:53:24
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
const ll INF = 1e18;
ll tr[N << 2], lazy[N], mark[N];
ll a[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
    lazy[p] = mark[p] = INF;
} 
void pushdown(int p, int l, int r){
    int mid = l + r >> 1;
    if(mark[p] != INF){
        tr[p << 1] += mark[p] * (mid - l + 1);
        tr[p << 1|1] += mark[p] * (mid - r);
        if(mark[p << 1] == INF) mark[p << 1] = mark[p];
        else mark[p << 1] += mark[p];
        if(mark[p << 1|1] == INF) mark[p << 1|1] = mark[p];
        else mark[p << 1|1] += mark[p];
        mark[p] = INF;
    }
    if(lazy[p] != INF){
        tr[p << 1] = lazy[p] * (mid - l + 1);
        tr[p << 1|1] = lazy[p] * (r - mid);
        lazy[p << 1] = lazy[p << 1|1] = lazy[p];
        lazy[p] = INF;
    }
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        lazy[p] = INF;
        mark[p] = INF;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void update(int l, int r, int cl, int cr, int p, ll k, ll kk){
    if(cl <= l && r <= cr){
        if(k == INF){
            tr[p] += (r - l + 1) * kk;
            if(mark[p] == INF) mark[p] = kk;
            else mark[p] += kk;
        }
        if(kk == INF){
            tr[p] = k * (r - l + 1);
            lazy[p] = k;
        }
        return;
    }
    int mid = l + r >> 1;
    pushdown(p, l, r);
    if(cl <= mid) update(l, mid, cl, cr, p << 1, k, kk);
    if(cr > mid) update(mid + 1, r, cl, cr, p << 1|1, k, kk);
    pushup(p);
}
ll query(int l, int r, int id, int p){
    if(l == r && id == r){
        return tr[p];
    }
    int mid = l + r >> 1;
    pushdown(p, l, r);
    ll res = 0;
    if(id <= mid) res += query(l, mid, id, p << 1);
    if(id > mid) res += query(mid + 1, r, id, p << 1|1);
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    int t; cin >> t;
    while(t --){
        int op;
        cin >> op;
        if(op == 1){
            ll x; cin >> x;
            update(1, n, 1, n, 1, x, INF);
        }else if(op == 2){
            ll id, x;
            cin >> id >> x;
            update(1, n, id, id, 1, INF, x);
        }else{
            ll id; cin >> id;
            cout << query(1, n, id, 1) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t
    Solve();
    return 0;
}