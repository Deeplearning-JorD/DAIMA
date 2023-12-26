/*
 * @Author: JorD
 * @LastEditTime: 2023-05-09 18:48:49
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
const int mod = 571373;
struct Matrix{
    int M[2][2];
    inline int* operator [] (const int i){ return M[i]; }
    Matrix(){
        M[0][0] = 1;
        M[0][1] = 0;
        M[1][0] = 0;
        M[1][1] = 1;
    }
    void add(int x){
        M[0][0] = 1;
        M[0][1] = x;
    }
    void mul(int x){
        M[0][0] = x;
    }
    void init(ll a,ll b){
        M[0][0] = a;
        M[1][0] = b;
        M[1][1] = 0;
    }
    void zero(){
        M[0][0] = 0;
        M[1][1] = 0;
    }
    int get(){
        return M[0][0];
    }
    void clear(){
        M[0][0] = 1;
        M[0][1] = 0;
        M[1][0] = 0;
        M[1][1] = 1;
    }
};
inline Matrix operator *(Matrix L, Matrix R){
    Matrix res;
    res.zero();
    for(int i = 0;i < 2;i ++){
        for(int k = 0;k < 2;k ++){
            ll x = L.M[i][k]%mod;
            for(int j = 0;j < 2;j ++){
                res.M[i][j]+=x*R.M[k][j]%mod;
                res.M[i][j]%=mod;
            }
        }
    }
    return res;
}
inline Matrix operator +(Matrix L, Matrix R){
    for(int i = 0;i < 2;i ++){
        for(int j = 0;j < 1;j ++){
            L.M[i][j] += R.M[i][j];
            L.M[i][j] %= mod;
        }
    }
    return L;
}
struct Segtree{
    Matrix w, tag;
    // w[0][0] 代表区间值
    // w[1][0] 代表区间长度
}tr[N << 2];
int a[N];
inline void build(int l, int r, int p){
    if(l == r){
        tr[p].w.init(a[l], 1);
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p].w = tr[p << 1].w + tr[p << 1|1].w;
}
Matrix zero;
inline void pushdown(int p){
    tr[p << 1].w = tr[p].tag * tr[p << 1].w;
    tr[p << 1|1].w = tr[p].tag * tr[p << 1|1].w;
    tr[p << 1].tag = tr[p].tag * tr[p << 1].tag;
    tr[p << 1|1].tag = tr[p].tag * tr[p << 1|1].tag;
    tr[p].tag.clear();
}
inline void update(int cl, int cr, int l, int r, int p, int op, int k){
    if(cl <= l && r <= cr){
        Matrix now;
        if(op == 1) now.mul(k);
        else now.add(k);
        tr[p].w = now * tr[p].w;
        tr[p].tag = now * tr[p].tag;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, op, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, op, k);
    tr[p].w = tr[p << 1].w + tr[p << 1|1].w;
}
inline int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].w[0][0];
    }
    pushdown(p);
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);
    if(cr > mid) res = (res + query(cl, cr, mid + 1, r, p << 1|1));
    return res % mod;
}
void Solve(){
    int n, m, p;
    cin >> n >> m >> p;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, k;
            cin >> l >> r >> k;
            update(l, r, 1, n, 1, 1, k);
        }else if(op == 2){
            int l, r, k;
            cin >> l >> r >> k;
            update(l, r, 1, n, 1, 2, k);
        }else{
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << endl;
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