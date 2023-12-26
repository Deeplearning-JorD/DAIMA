/*
 * @Author: JorD
 * @LastEditTime: 2023-05-18 23:15:59
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
const int N = 5e5 + 10, inf = 2e9;
struct Segtree{
    int mxa, mxb, se, cnt;
    ll sum;
    int tag1, tag2, tag3, tag4;
}tr[N << 2];
inline void change(int k1, int k2, int k3, int k4, int p, int l, int r){
    tr[p].sum += 1ll * k1 * tr[p].cnt + 1ll * (r - l + 1 - tr[p].cnt) * k3;
    tr[p].mxb = max(tr[p].mxb, tr[p].mxa + k2);
    tr[p].mxa += k1;
    if(tr[p].se != - inf) tr[p].se += k3;
    tr[p].tag2 = max(tr[p].tag2, tr[p].tag1 + k2);
    tr[p].tag4 = max(tr[p].tag4, tr[p].tag3 + k4);
    tr[p].tag1 += k1;
    tr[p].tag3 += k3;
}
inline void pushdown(int p, int l, int r){
    int mid = l + r >> 1;
    int mx = max(tr[p << 1].mxa, tr[p << 1|1].mxa);
    if(mx == tr[p << 1].mxa) change(tr[p].tag1, tr[p].tag2, tr[p].tag3, tr[p].tag4, p << 1, l, mid);
    else change(tr[p].tag3, tr[p].tag4, tr[p].tag3, tr[p].tag4, p << 1, l, mid);
    if(mx == tr[p << 1|1].mxa) change(tr[p].tag1, tr[p].tag2, tr[p].tag3, tr[p].tag4, p << 1|1, mid + 1, r);
    else change(tr[p].tag3, tr[p].tag4, tr[p].tag3, tr[p].tag4, p << 1|1, mid + 1, r);
    tr[p].tag1 = tr[p].tag2 = tr[p].tag3 = tr[p].tag4 = 0; 
}
inline void pushup(int p){
    tr[p].sum = tr[p << 1].sum + tr[p << 1|1].sum;
    tr[p].mxa = max(tr[p << 1].mxa, tr[p << 1|1].mxa);
    tr[p].mxb = max(tr[p << 1].mxb, tr[p << 1|1].mxb);
    if(tr[p << 1].mxa == tr[p << 1|1].mxa){
        tr[p].se = max(tr[p << 1].se, tr[p << 1|1].se);
        tr[p].cnt = tr[p << 1].cnt + tr[p << 1|1].cnt;
    }else if(tr[p << 1].mxa > tr[p << 1|1].mxa){
        tr[p].se = max(tr[p << 1|1].mxa, tr[p << 1].se);
        tr[p].cnt = tr[p << 1].cnt;
    }else{
        tr[p].se = max(tr[p << 1].mxa, tr[p << 1|1].se);
        tr[p].cnt = tr[p << 1|1].cnt;
    }
}
inline void build(int l, int r, int p){
    if(l == r){
        int x; cin >> x;
        tr[p] = {x, x, -inf, 1, x, 0, 0, 0, 0};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
inline void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].tag1 += k;
        tr[p].tag3 += k;
        tr[p].tag2 = max(tr[p].tag2, tr[p].tag1);
        tr[p].tag4 = max(tr[p].tag4, tr[p].tag3);
        tr[p].sum += 1ll * (r - l + 1) * k;
        tr[p].mxa += k;
        if(tr[p].se != - inf) tr[p].se += k;
        tr[p].mxb = max(tr[p].mxb, tr[p].mxa);
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline void update_min(int cl, int cr, int l, int r, int p, int k){
    if(tr[p].mxa <= k) return; 
    if(cl <= l && r <= cr && k > tr[p].se){
        tr[p].sum += 1ll * tr[p].cnt * (k - tr[p].mxa);
        tr[p].tag1 += k - tr[p].mxa;
        tr[p].mxa = k;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) update_min(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update_min(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].sum;
    }
    pushdown(p, l, r);
    ll res = 0;
    int mid = l + r >> 1;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
inline int querya(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].mxa;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    int res = -inf;
    if(cl <= mid) res = querya(cl, cr, l, mid, p << 1);
    if(cr > mid) res = max(res, querya(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
inline int queryb(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].mxb;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    int res = -inf;
    if(cl <= mid) res = queryb(cl, cr, l, mid, p << 1);
    if(cr > mid) res = max(res, queryb(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    build(1, n, 1);
    while(m --){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            int k; cin >> k;
            update(l, r, 1, n, 1, k);
        }else if(op == 2){
            int k; cin >> k;
            update_min(l, r, 1, n, 1, k);
        }else if(op == 3){
            cout << query(l, r, 1, n, 1) << endl;
        }else if(op == 4){
            cout << querya(l, r, 1, n, 1) << endl;
        }else cout << queryb(l, r, 1, n, 1) << endl;
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