/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 13:15:41
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
int f(int x){
    return (x + 2) / 3;
}
int a[N];
struct Segtree{
    int sum, mx, val;
}tr[N << 2];
void pushup(int p){
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1|1].mx);
    tr[p].sum = tr[p << 1].sum + tr[p << 1|1].sum;
    tr[p].val = tr[p << 1].val + tr[p << 1|1].val;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p].mx = a[l];
        tr[p].sum = a[l];
        tr[p].val = a[l] < 100;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
int query0(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].val;
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query0(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query0(cl, cr, mid + 1, r, p << 1|1);
    return res; 
}
int query1(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].sum;
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query1(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query1(cl, cr, mid + 1, r, p << 1|1);
    return res; 
}
void update(int cl, int cr, int l, int r, int p){
    if(tr[p].mx < 10) return;
    if(l == r){
        int now = tr[p].sum - f(tr[p].sum);
        tr[p].mx = now;
        tr[p].sum = now;
        tr[p].val = now < 100;
        return;
    }
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1);
    pushup(p);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            update(l, r, 1, n, 1);
        }else if(op == 2){
            cout << query0(l, r, 1, n, 1) << endl;
        }else{ 
            cout << query1(l, r, 1, n, 1) << endl;
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