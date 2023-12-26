/*
 * @Author: JorD
 * @LastEditTime: 2022-12-30 18:16:39
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
vector<int> son[N];
ll res[N];
int root[N], idx;
struct Segtree{
    int l, r, mx;
    ll cnt;
}tr[N * 30];
void pushup(int p){
    if(tr[tr[p].l].mx == tr[tr[p].r].mx){
        tr[p].mx = tr[tr[p].l].mx;
        tr[p].cnt = tr[tr[p].l].cnt + tr[tr[p].r].cnt;
    }else if(tr[tr[p].l].mx > tr[tr[p].r].mx){
        tr[p].mx = tr[tr[p].l].mx;
        tr[p].cnt = tr[tr[p].l].cnt;
    }else{
        tr[p].mx = tr[tr[p].r].mx;
        tr[p].cnt = tr[tr[p].r].cnt;
    }
}
void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt = pos;
        tr[p].mx = 1;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l);
    else modify(pos, mid + 1, r, tr[p].r);
    pushup(p);
}
void merge(int &x, int y, int l = 1, int r = MAXN){
    if(!x || !y) x |= y;
    else if(l == r){
        tr[x].mx += tr[y].mx;
    }else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
void dfs(int now, int fa){
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        merge(root[now], root[x]);
    }
    res[now] = tr[root[now]].cnt;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        modify(x, 1, MAXN, root[i]);
    }
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
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