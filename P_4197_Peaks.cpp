/*
 * @Author: JorD
 * @LastEditTime: 2022-12-29 21:04:38
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 1e5 + 10, INF = 1e9;
int h[N];
struct Segtree{
    int l, r;
    int cnt;
}tr[N * 50];
struct node{
    int id, l, r;
    bool operator <(const node &ji) const{
        return ji.id > id;
    }
};
struct bei{
    int x, v, k, id;
    bool operator <(const bei &ji) const{
        return x < ji.x;
    }
};
int mp[N], root[N], idx, f[N];
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
void merge(int &x, int y, int l = 1, int r = INF){
    if(!x || !y) x |= y;
    else if(l == r) tr[x].cnt += tr[y].cnt;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
int query(int p, int l, int r, int lim){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(tr[tr[p].l].cnt < lim){
        return query(tr[p].r, mid + 1, r, lim - tr[tr[p].l].cnt);
    }
    return query(tr[p].l, l, mid, lim);
}
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, 1, n){
        cin >> h[i];
        f[i] = i;
        modify(h[i], 1, INF, root[i]);
    }
    vector<node> edge(m + 1);
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
    sort(all1(edge));
    vector<int> res(q + 1);
    vector<bei> ask(q + 1);
    rep(i, 1, q){
        int v, x, k;
        cin >> v >> x >> k;
        ask[i] = {x, v, k, i};
    }
    sort(all1(ask));
    int cnt = 1;
    rep(i, 1, q){
        auto [w, v, k, id] = ask[i];
        while(cnt <= m && edge[cnt].id <= w){
            int x = edge[cnt].l, y = edge[cnt].r;
            int fx = find(x), fy = find(y);
            cnt ++;
            if(fx == fy) continue;
            f[fy] = fx;
            merge(root[fx], root[fy]);
        }
        int now = tr[root[find(v)]].cnt;
        if(now < k) res[id] = -1;
        else
        res[id] = query(root[find(v)], 1, 1e9, now - k + 1);
    }
    rep(i, 1, q) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}