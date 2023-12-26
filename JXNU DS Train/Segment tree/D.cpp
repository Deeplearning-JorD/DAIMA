/*
 * @Author: JorD
 * @LastEditTime: 2022-12-20 15:53:03
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
int n, m;
int a[N];
ll tr[N << 2], mx[N << 2];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
    mx[p] = max(mx[p << 1], mx[p << 1|1]);
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        mx[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(mx[p] < k) return;
    if(l > cr || r < cl) return;
    if(l == r){
        tr[p] %= k;
        mx[p] %= k;
        return;
    }
    int mid = l + r >> 1;
    update(cl, cr, l, mid, p << 1, k);
    update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
void midofy(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = k;
        mx[p] = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) midofy(pos, l, mid, p << 1, k);
    if(pos > mid) midofy(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << endl;
        }else if(op == 2){
            int l, r, x;
            cin >> l >> r >> x;
            update(l, r, 1, n, 1, x);
        }else{
            int x, k;
            cin >> x >> k;
            midofy(x, 1, n, 1, k);
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