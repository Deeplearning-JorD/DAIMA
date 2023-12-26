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
/*
d[i] = min({|p[i] - p[j]| + |i - j|})
     = min({p[i] - p[j] + i - j, p[j] - p[i] + i - j,
        p[i] - p[j] + j - i, p[j] - p[i] + j - i})
     (i > j) p[i] + i - (p[j] + j),  i - p[i] + (p[j] - j)
     (j > i) p[i] - i - (p[j] - i),  - (p[i] + i) + (p[j] + j)
     (i > j) A[i] - A[j], - B[i] + B[j]
     (j > i) B[i] - B[j], - A[i] + A[j]
*/
const int P = 2e5 + 10, N = 6e5 + 10, INF = 1e9, up = 6e5;
struct node{
    int mx, mi;
}tr[2][N << 2];
void pushup(int p, int o){
    tr[o][p].mx = max(tr[o][p << 1].mx, tr[o][p << 1|1].mx);
    tr[o][p].mi = min(tr[o][p << 1].mi, tr[o][p << 1|1].mi);
}
void build(int l, int r, int p, int o){
    if(l == r){
        tr[o][p] = {- INF, INF};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1, o);
    build(mid + 1, r, p << 1|1, o);
    pushup(p, o);
}
void midofy(int pos, int l, int r, int p, int k, int o){
    if(l == r){
        tr[o][p] = {k, k};
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) midofy(pos, l, mid, p << 1, k, o);
    if(pos > mid) midofy(pos, mid + 1, r, p << 1|1, k, o);
    pushup(p, o);
    return;
}
node query(int cl, int cr, int l, int r, int p, int o){
    if(cl <= l && r <= cr){
        return tr[o][p];
    }
    int mid = l + r >> 1;
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1, o);
    if(cr <= mid) return query(cl, cr, l, mid, p << 1, o);
    node L = query(cl, cr, l, mid, p << 1, o);
    node R = query(cl, cr, mid + 1, r, p << 1|1, o);
    node res;
    res.mi = min(L.mi, R.mi);
    res.mx = max(L.mx, R.mx);
    return res;
}
void Solve(){
    int n;
    cin >> n;
    vector<int> p(n + 1), A(n + 1), B(n + 1);
    rep(i, 1, n){
        cin >> p[i];
        A[i] = p[i] + i;
        B[i] = p[i] - i + P;
    }
    build(0, n, 1, 0);
    build(0, n, 1, 1);
    vector<int> res(n + 1, 1e9);
    rep(i, 1, n){
        auto ji = query(0, p[i], 0, n, 1, 0);
        if(ji.mx != - INF)
        res[i] = min(res[i], A[i] - ji.mx);
        ji = query(p[i], up, 0, n, 1, 1);
        if(ji.mi != INF)
        res[i] = min(res[i], - B[i] + ji.mi);
        midofy(p[i], 0, n, 1, A[i], 0);
        midofy(p[i], 0, n, 1, B[i], 1);
    }
    build(0, n, 1, 0);
    build(0, n, 1, 1);
    per(i, n, 1){
        auto ji = query(0, p[i], 0, n, 1, 1);
        if(ji.mx != - INF)
        res[i] = min(res[i], B[i] - ji.mx);
        ji = query(p[i], up, 0, n, 1, 0);
        if(ji.mi != INF)
        res[i] = min(res[i], - A[i] + ji.mi);
        midofy(p[i], 0, n, 1, A[i], 0);
        midofy(p[i], 0, n, 1, B[i], 1);
    }
    rep(i, 1, n) cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}