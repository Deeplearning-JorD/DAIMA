/*
 * @Author: JorD
 * @LastEditTime: 2023-04-05 16:00:01
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
const int N = 3e5 + 10, mod = 998244353;
ll tr[N << 2], tr1[N << 2];
int a[N];
int n, m;
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        tr1[p] = ((1ll * a[l] * a[l]) % mod + mod) % mod;
        return; 
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] | tr[p << 1|1];
    tr1[p] = ((tr1[p << 1] + tr1[p << 1|1]) % mod + mod) % mod;
    return;
}
void modify(int pos, int l, int r, int p, int x){
    if(l == r){
        tr[p] &= x;
        tr1[p] = (tr[p] * tr[p] % mod + mod) % mod;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, x);
    else modify(pos, mid + 1, r, p << 1|1, x);
    tr1[p] = (tr1[p << 1] + tr1[p << 1|1]) % mod;
    tr[p] = tr[p << 1] | tr[p << 1|1];
    return;
}
void query(int cl, int cr, int l, int r, int p, int x){
    int mid = l + r >> 1;
    if(l == r){
        modify(l, 1, n, 1, x);
        return;
    }
    if(cl <= l && r <= cr){
        if((tr[p << 1]&x) != tr[p << 1]) query(cl, cr, l, mid, p << 1, x);
        if((tr[p << 1|1]&x) != tr[p << 1|1]) query(cl, cr, mid + 1, r, p << 1|1, x);
        return;
    }
    if(cl <= mid) query(cl, cr, l, mid, p << 1, x);
    if(cr > mid) query(cl, cr, mid + 1, r, p << 1|1, x);
    return;
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr1[p] % mod;
    }
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);  
    if(cr > mid) res = (res + query(cl, cr, mid + 1, r, p << 1|1)) % mod;
    return res;
}
void Solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    cin >> m;
    while(m --){
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op == 1){
            cin >> x;
            query(l, r, 1, n, 1, x);
        }else{
            cout << (query(l, r, 1, n, 1)%mod + mod)%mod << endl;
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