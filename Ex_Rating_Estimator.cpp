/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 12:41:59
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define int long long
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
const int N = 5e5 + 10, inf = 1e9;
int a[N], num[N];
int n, B, t;
struct Segtree{
    int mx = - inf, sum, mark;
}tr[N << 2];
int lastroot;
void pushdown(int l, int r, int p){
    int mid = l + r >> 1;
    tr[p << 1].sum += (mid - l + 1) * tr[p].mark;
    tr[p << 1|1].sum += (r - mid) * tr[p].mark;
    tr[p << 1].mx += tr[p].mark;
    tr[p << 1|1].mx += tr[p].mark;
    tr[p << 1].mark += tr[p].mark;
    tr[p << 1|1].mark += tr[p].mark;
    tr[p].mark = 0;
    return;
}
void pushup(int p){
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1|1].mx); 
    tr[p].sum = tr[p << 1].sum + tr[p << 1|1].sum;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p].mx = a[l];
        tr[p].sum = a[l];
        if(l == n) lastroot = p;
        return;    
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
    return;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].mark += k;
        tr[p].mx += k;
        tr[p].sum += k * (r - l + 1);
        return;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
double need;
int query(int pos, int l, int r, int p){
    if(l == r){
        return tr[p].mx;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    if(pos <= mid) return query(pos, l, mid, p << 1);
    else return query(pos, mid + 1, r, p << 1|1);
}
int find(int l, int r, int p){
    if(l == r){
        need = tr[p].sum;
        return l;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    if(tr[p << 1].mx >= 0) return find(l, mid, p << 1);
    return find(mid + 1, r, p << 1|1);
}
void Solve(){
    cin >> n >> B >> t;
    rep(i, 1, n){
        cin >> a[i];
        num[i] = a[i];
        a[i] -= B;
        a[i] += a[i - 1];
    }
    build(1, n, 1);
    while(t --){
        int id, x; cin >> id >> x;
        update(id, n, 1, n, 1, x - num[id]);
        num[id] = x;
        int idx = n;
        need = query(lastroot, 1, n, 1);
        if(tr[1].mx >= 0){
            idx = find(1, n, 1);
        }
        cout << SPO(15) << B + (need / idx) << endl;
    }
    return;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}