/*
 * @Author: JorD
 * @LastEditTime: 2022-12-18 04:14:08
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
const int N = 1e5 + 10;
int n;
int a[N];
int tr[32][N << 2], lazy[32][N << 2];
// tr[id][p]表示在二进制下的id位，p这个节点下有多少个1
// 所代表的的权值为 tr[id][p] * (1 << id)
void pushup(int id, int p){
    tr[id][p] = tr[id][p << 1] + tr[id][p << 1|1];
    return;
}
void pushdown(int id, int l, int r, int p){
    int mid = l + r >> 1;
    auto &L = tr[id][p << 1], &R = tr[id][p << 1|1];
    auto &lL = lazy[id][p << 1], &lR = lazy[id][p << 1|1];
    if(lazy[id][p] & (1 << id)){
        L = mid - l + 1 - L;
        R = r - mid - R;
        lL ^= lazy[id][p];
        lR ^= lazy[id][p]; 
        lazy[id][p] = 0;
    }
    return;
}
void build(int l, int r, int p, int id){
    if(l == r){
        tr[id][p] = (a[l] & (1 << id))?1:0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1, id);
    build(mid + 1, r, p << 1|1, id);
    pushup(id, p);
}
void update(int cl, int cr, int l, int r, int p, int k, int id){
    if(cl <= l && r <= cr){
        if(k & (1 << id)){
            tr[id][p] = r - l + 1 - tr[id][p];
            lazy[id][p] ^= k; 
        }
        return;
    }
    int mid = l + r >> 1;
    pushdown(id, l, r, p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k, id);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k, id);
    pushup(id, p);
}
ll query(int cl, int cr, int l, int r, int p, int id){
    if(cl <= l && r <= cr){
        return 1ll * tr[id][p] * (1ll << id); 
    }
    int mid = l + r >> 1;
    ll res = 0;
    pushdown(id, l, r, p);
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1, id);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1, id);
    return res;
}
void Solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, 30)
    build(1, n, 1, i);
    int m;
    cin >> m;
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            ll res = 0;
            rep(i, 0, 30){
                res += query(l, r, 1, n, 1, i);
            }
            cout << res << endl;
        }else{
            int l, r, x;
            cin >> l >> r >> x;
            rep(i, 0, 30) update(l, r, 1, n, 1, x, i);
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