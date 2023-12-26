/*
 * @Author: JorD
 * @LastEditTime: 2023-03-01 20:54:45
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
const int N = 3e5 + 10;
const ll INF = 1e15;
ll a[N], hot[N], cold[N];
ll tr[N << 2], mark[N << 2];
void pushdown(int l, int r, int p){
    if(!mark[p]) return;
    tr[p << 1] += mark[p];
    tr[p << 1|1] += mark[p];
    mark[p << 1] += mark[p];
    mark[p << 1|1] += mark[p];
    mark[p] = 0;
    return;
}
void build(int l, int r, int p){
    mark[p] = 0;
    if(l == r){
        tr[p] = INF;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
void update(int cl, int cr, int l, int r, int p, ll k){
    if(cl > cr) return;
    if(cl <= l && r <= cr){
        tr[p] += k;
        mark[p] += k;
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
    return;
}
void update1(int l, int r, int pos, int p, ll k){
    if(l == r){
        tr[p] = min(tr[p], k);
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(pos <= mid) update1(l, mid, pos, p << 1, k);
    else update1(mid + 1, r, pos, p << 1|1, k);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
    return;
}
void modify(int l, int r, int pos, int p, ll k){
    if(l == r){
        tr[p] = k;
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(pos <= mid) modify(l, mid, pos, p << 1, k);
    else modify(mid + 1, r, pos, p << 1|1, k);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
    return;
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl > cr) return INF;
    if(cl <= l && r <= cr){
        return tr[p];
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    ll res = INF;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);
    if(cr > mid) res = min(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res; 
}
void Solve(){
    ll n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, k) cin >> cold[i];
    rep(i, 1, k) cin >> hot[i];
    build(1, k, 1);
    modify(1,k,a[1],1,cold[a[1]]);
    for(int i = 2;i <= n;i ++){
        if(a[i] == a[i - 1]){
            update(1, k, 1, k, 1, hot[a[i]]);
            update1(1, k, a[i - 1], 1, query(1, k, 1, k, 1));
            continue;
        }
        ll last = query(a[i], a[i], 1, k, 1);
        update(1, a[i] - 1, 1, k, 1, cold[a[i]]);
        update(a[i] + 1, k, 1, k, 1, cold[a[i]]);
        update(a[i], a[i], 1, k, 1, hot[a[i]]);
        update1(1, k, a[i - 1], 1, query(1, k, 1, k, 1));
        modify(1, k, a[i], 1, last + cold[a[i]]);
    }
    cout << tr[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}
