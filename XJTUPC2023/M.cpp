/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 18:02:54
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
const int N = 2e5 + 10;
vector<int> son[N];
int w[N], id[N], siz[N], zson[N], depth[N];
int n, m, root = 1;
ll mod;
int fat[N];
bool col[N], a[N];
int B[N], H[N];
void dfs1(int now, int fa){
    siz[now] = B[now] = 1;
    depth[now] = depth[fa] + 1;
    fat[now] = fa;
    for(auto x:son[now])if(x != fa){
        dfs1(x, now);
        siz[now] += siz[x];
        B[now] += B[x];
        if(siz[x] > siz[zson[now]])
            zson[now] = x;
    }
    return;
}
int top[N], idx, mid[N];
void dfs2(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    mid[idx] = now;
    if(!zson[now]) return;
    dfs2(zson[now], now, T);
    for(auto x:son[now]){
        if(x == fa||x == zson[now]) continue;
        dfs2(x, now, x);
    }
}
struct Segtree{
    int sum, tag;
}tr[N << 2];
void pushup(int p){
    tr[p].sum = tr[p << 1].sum | tr[p << 1|1].sum;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p].sum = 2;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
int query(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr) return tr[p].sum;
    int mid = l + r >> 1;
    if(cl > mid) return query(mid + 1, r, cl, cr, p << 1|1);
    if(cr <= mid) return query(l, mid, cl, cr, p << 1);
    return query(l, mid, cl, cr, p << 1) | query(mid + 1, r, cl, cr, p << 1|1);
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p].sum = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    tr[p].sum = tr[p << 1].sum | tr[p << 1|1].sum;
}
void Solve(){
    cin >> n;
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    build(1, n, 1);
    int ans = 0;
    rep(i, 1, n){
        int x; cin >> x;
        col[x] = 1;
        modify(id[x], 1, n, 1, 1);
        while(x){
            bool ff = false;
            int now = query(1, n, id[x], id[x] + siz[x] - 1, 1);
            if(a[x]){
                if(now == 1){
                    a[x] = 0;
                    ans --;
                    ff = true;
                }
            }else{
                if(now == 3){
                    a[x] = 1;
                    ff = true;
                    ans ++;
                }
            }
            if(ff || son[x].empty()) x = fat[x];
            else break;
        }
        cout << ans << ' ';
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