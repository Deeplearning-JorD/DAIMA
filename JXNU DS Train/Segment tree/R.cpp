/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 05:04:43
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10, M = 3e5 + 10, inf = 3e5;
int num[N],sum[M];
int tr[M << 2], mark[M << 2];
int n, t, res;
void pushdown(int p, int l, int r){
    if(!mark[p]) return;
    int mid = l + r >> 1;
    tr[p << 1] += mark[p] * (mid - l + 1);
    mark[p << 1] += mark[p];
    tr[p << 1|1] += mark[p] * (r - mid);
    mark[p << 1|1] += mark[p];
    mark[p] = 0;
}
void build(int p, int l, int r){
    if(l == r){
        tr[p] = sum[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void update(int l, int r, int cl, int cr, int p, ll x){
    if(cl > cr) return;
    if(cl <= l&&r <= cr){
        mark[p] += x;
        tr[p] += x * (r - l + 1);
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(mid >= cl) update(l, mid, cl, cr, p << 1, x);
    if(mid < cr) update(mid + 1, r, cl, cr, p << 1|1, x);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
int findmax(int l, int r, int p){
    if(l == r) return l;
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(tr[p << 1|1]) return findmax(mid + 1, r, p << 1|1);
    return findmax(l, mid, p << 1);
}
int find0(int l, int r, int cl, int cr, int p){
    if(l == r) return tr[p]?-1:l;
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= l && r <= cr){
        if(tr[p] == r - l + 1) return -1;
        int res = find0(l, mid, cl, cr, p << 1);
        if(res == -1) return find0(mid + 1, r, cl, cr, p << 1|1);;
        return res;
    }
    if(cl > mid) return find0(mid + 1, r, cl, cr, p << 1|1);
    if(cr <= mid) return find0(l, mid, cl, cr, p << 1);
    int res = find0(l, mid, cl, cr, p << 1);
    if(res == -1) return find0(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
int find1(int l, int r, int cl, int cr, int p){
    if(l == r) return tr[p]?l:-1;
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= l && r <= cr){
        if(!tr[p]) return -1;
        int res = find1(l, mid, cl, cr, p << 1);
        if(res == -1) return find1(mid + 1, r, cl, cr, p << 1|1);;
        return res;
    }
    if(cl > mid) return find1(mid + 1, r, cl, cr, p << 1|1);
    if(cr <= mid) return find1(l, mid, cl, cr, p << 1);
    int res = find1(l, mid, cl, cr, p << 1);
    if(res == -1) return find1(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> t;
    rep(i, 1, n){
        cin >> num[i];
        sum[num[i]] ++;
    }
    rep(i, 1, inf){
        if(sum[i]) res = i;
        sum[i + 1] += sum[i] >> 1;
        sum[i] &= 1;
    }
    build(1, 1, 3e5);
    while(t --){
        int x, y;
        cin >> x >> y;
        int p = find1(1, inf, num[x], inf, 1);
        update(1, 3e5, num[x], p - 1, 1, 1);
        update(1, 3e5, p, p, 1, -1);
        num[x] = y;
        p = find0(1, inf, num[x], inf, 1);
        update(1, 3e5, num[x], p - 1, 1, -1);
        update(1, 3e5, p, p, 1, 1);
        cout << findmax(1, inf, 1) << endl;
    }
    return 0;
}