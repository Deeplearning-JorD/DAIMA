/*
 * @Author: JorD
 * @LastEditTime: 2023-04-11 00:05:42
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
const int M = 5e6 + 10;
int primes[M], cnt;
int ne[M];
bool st[M];
int a[N];
void get_eulers(){
    int n = 5e6;
    ne[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!st[i]){
            primes[cnt++] = i;
            ne[i] = i - 1; 
        }
        for (int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if (i % primes[j] == 0){
                ne[primes[j] * i] = ne[i] * primes[j]; 
                break;
            }
            ne[primes[j] * i] = ne[i] * (primes[j] - 1);
        }
    }
}
struct Segtree{
    int siz, mx, mii;
    ll w;
}tr[N << 2];
Segtree operator +(Segtree a, Segtree b){
    Segtree now;
    now.mx = max(a.mx, b.mx);
    int l = a.mii, r = b.mii;
    now.w = a.w + b.w;
    int z1 = a.siz, z2 = b.siz;
    while(l != r){
        if(l > r){
            swap(l, r);
            swap(z1, z2);
        }
        r = ne[r];
        now.w += z2;
    }
    now.siz = a.siz + b.siz;
    now.mii = l;
    return now;
}
inline void build(int l, int r, int p){
    if(l == r){
        tr[p].siz = 1;
        tr[p].mx = a[l];
        tr[p].mii = a[l];
        tr[p].w = 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
inline void update(int cl, int cr, int l, int r, int p){
    if(tr[p].mx == 1) return;
    if(l == r){
        int now = ne[tr[p].mx];
        tr[p].mx = now;
        tr[p].mii = now;
        tr[p].w = 0;
        return;
    }
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
inline Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    return query(cl, cr, l, mid, p << 1) + query(cl, cr, mid + 1, r, p << 1|1);
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
        }else{
            cout << query(l, r, 1, n, 1).w << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    get_eulers();
    Solve();
    return 0;
}