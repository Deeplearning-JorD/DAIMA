/*
 * @Author: JorD
 * @LastEditTime: 2022-12-30 00:15:10
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
const int N = 1e5 + 10, MAXN = 1e5;
int rk[N], mp[N], f[N];
struct Segtree{
    int l, r, cnt;
}tr[N * 70];
int root[N], idx;
void pushup(int p){
    tr[p].cnt = tr[tr[p].l].cnt + tr[tr[p].r].cnt;
}
void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt ++;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l);
    else modify(pos, mid + 1, r, tr[p].r);
    pushup(p);
}
void merge(int &x, int y, int l = 1, int r = MAXN){
    if(!x || !y) x |= y;
    else if(l == r) tr[x].cnt += tr[y].cnt;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
int query(int p, int l, int r, int k){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(tr[tr[p].l].cnt < k) 
    return query(tr[p].r, mid + 1, r, k - tr[tr[p].l].cnt);
    return query(tr[p].l, l, mid, k);
}
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        cin >> rk[i];
        mp[rk[i]] = i;
        f[i] = i;
        modify(rk[i], 1, MAXN, root[i]);
    }
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        int fx = find(x), fy = find(y);
        f[fy] = fx;
        merge(root[fx], root[fy]);
    }
    int t;
    cin >> t;
    while(t --){
        char op;
        int x, y;
        cin >> op >> x >> y;
        int fx = find(x), fy = find(y);
        if(op == 'B'){
            if(fx == fy) continue;
            f[fy] = fx;
            merge(root[fx], root[fy]);
        }else{
            if(tr[root[fx]].cnt < y) cout << -1 << endl;
            else cout << mp[query(root[fx], 1, MAXN, y)] << endl;
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