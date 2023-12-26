/*
 * @Author: JorD
 * @LastEditTime: 2022-12-28 21:03:29
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
const int N = 1e5 + 10, MAXN = 32768;
struct Segtree{
    int l, r, cnt;
}tr[N * 40];
int root[N], idx;
int n;
inline void pushup(int p){
    tr[p].cnt = tr[tr[p].l].cnt + tr[tr[p].r].cnt;
}
inline int query(int p, int l = 1, int r = MAXN){
    int mid = l + r >> 1;
    if(l == r) return r;
    if(tr[tr[p].r].cnt) return query(tr[p].r, mid + 1, r);
    return query(tr[p].l, l, mid);
}
bool check(int pos, int l, int r, int p){
    if(!p) return false;
    if(l == r) return tr[p].cnt;
    int mid = l + r >> 1;
    if(pos <= mid) return check(pos, l, mid, tr[p].l);
    else return check(pos, mid + 1, r, tr[p].r);
}
inline void modify(int pos, int l, int r, int &p, int k){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt += k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l, k);
    else modify(pos, mid + 1, r, tr[p].r, k);
    pushup(p);
}
inline void merge(int &x, int y, int l = 1, int r = MAXN){
    if(!x || !y) x |= y;
    else if(l == r) tr[x].cnt += tr[y].cnt;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
int f[N];
inline int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    rep(i, 1, n){
        int x; scanf("%d", &x);
        modify(x, 1, MAXN, root[i], 1);
        f[i] = i;
    }   
    int m;
    scanf("%d",&m);
    while(m --){
        int x, y;
        scanf("%d%d",&x,&y);
        int fx = find(x), fy = find(y);
        if(fx == fy){
            puts("-1");
            continue;
        }
        int gx = query(root[fx]), gy = query(root[fy]);
        modify(gx, 1, MAXN, root[fx], -1);
        modify(gy, 1, MAXN, root[fy], -1);
        modify(gx / 2, 1, MAXN, root[fx], 1);
        modify(gy / 2, 1, MAXN, root[fy], 1);
        merge(root[fx], root[fy]);
        f[fy] = fx;
        printf("%d\n", query(root[fx]));
    }
    return;
}
int main(){
    while(scanf("%d", &n) != EOF){
        idx = 0;
        Solve();
        rep(i, 1, n) root[i] = 0;
        rep(i, 1, idx) tr[i] = {0, 0, 0}; 
    }
    return 0;
}