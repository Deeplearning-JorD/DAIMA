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
const int N = 1e6 + 10;
const double eps = 1e-7;
struct Segtree{
    int cnt, tag, val;
    double sum, mark;
}tr[N << 2];
void pushup(int p){
    tr[p].cnt = tr[p << 1].cnt + tr[p << 1|1].cnt;
    tr[p].val = tr[p << 1].val + tr[p << 1|1].val;
}
void pushdown(int p){
    tr[p << 1].val -= tr[p].tag * tr[p << 1].cnt;
    tr[p << 1|1].val -= tr[p].tag * tr[p << 1].cnt;
    if(tr[p << 1].val == 0) tr[p << 1].cnt = 0;
    if(tr[p << 1|1].val == 0) tr[p << 1|1].cnt = 0;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
}
void update(int cl, int cr, int l, int r, int p, double x){
    if(cl <= l && r <= cr){
        tr[p].sum += x;
        tr[p].val += (ll)x;
        if(tr[p].sum > eps){
            tr[p].cnt = 1;
        }else tr[p].cnt = 0;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, x);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, x);
    pushup(p);
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        tr[p].tag ++;
        tr[p].val -= tr[p].cnt;
        return tr[p].cnt;
    }
    pushdown(p);
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n, m;
    double k;
    cin >> n >> m >> k; 
    ll res = 0;
    rep(i, 1, m){
        int op; cin >> op;
        if(op == 1){
            int l, r; double x; cin >> l >> r >> x;
            update(l, r, 1, n, 1, x / k);
        }else{
            int l, r; cin >> l >> r;
            res += query(l, r, 1, n, 1);
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}