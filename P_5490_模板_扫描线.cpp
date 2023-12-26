/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 20:54:39
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
const int N =2e5 + 10;
struct Segtree{
    ll sum, cnt, tag, val;
}tr[N << 4];
struct line{
    ll l, r, h, mark;
    bool operator <(const line &ji)const{
        if(h == ji.h) return mark > ji.mark;
        return h < ji.h;
    }
};
int X[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p].cnt = X[l + 1] - X[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p].cnt = tr[p << 1].cnt + tr[p << 1|1].cnt;
}
void pushup(int p){
    if(tr[p].sum) tr[p].val = tr[p].cnt;
    else tr[p].val = tr[p << 1].val + tr[p << 1|1].val;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].sum += k;
        pushup(p); 
        return;
    }
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
void Solve(){
    int n; cin >> n;
    vector<line> a(2 * n + 1);
    map<int,int> q;
    rep(i, 1, n){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        a[2*i - 1] = {sx, ex, sy, 1};
        a[2*i] = {sx, ex, ey, -1};
        q[sx] = 1;
        q[ex] = 1;
    }   
    sort(a.begin() + 1, a.end());
    int idx = 0;
    for(auto &[x, y] : q){
        X[++ idx] = x;  
        y = idx;
    }
    build(1, idx - 1, 1);
    ll res = 0; 
    for(int i = 1;i < 2 * n;i ++){
        auto [l, r, h, mark] = a[i]; 
        update(q[l], q[r] - 1, 1, idx - 1, 1, mark);
        res += 1ll * (a[i + 1].h - a[i].h) * tr[1].val;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}