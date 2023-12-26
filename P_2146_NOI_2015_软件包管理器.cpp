/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 20:02:26
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
const int N = 1e6 + 10;
vector<int> son[N];
int n;
int depth[N], fat[N], zson[N], siz[N];
void dfs1(int now, int fa){
    fat[now] = fa;
    depth[now] = depth[fa] + 1;
    siz[now] = 1;
    int mx = 0;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if(mx < siz[x]){
            zson[now] = x;
            mx = siz[x];
        }
    }
}
int top[N], id[N], idx;
void dfs2(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    if(!zson[now]) return;
    dfs2(zson[now], now, T);
    for(auto x:son[now]){
        if(x == fa||x == zson[now]) continue;
        dfs2(x, now, x);
    }   
}
int tr[N << 2], lazy[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void pushdown(int p, int l, int r){
    int mid = l + r >> 1;
    if(lazy[p] == 1){
        tr[p << 1] = mid - l + 1;
        tr[p << 1|1] = r - mid;
        lazy[p << 1] = lazy[p];
        lazy[p << 1|1] = lazy[p];
    }else if(lazy[p] == 2){
        tr[p << 1] = 0;
        tr[p << 1|1] = 0;
        lazy[p << 1] = lazy[p];
        lazy[p << 1|1] = lazy[p];
    }
    lazy[p] = 0;
}
int update(int l, int r, int cl, int cr, int p, int k){
    int res = 0;
    if(cl <= l&&r <= cr){
        if(k){
            res += r - l + 1 - tr[p];
            tr[p] = r - l + 1;
            lazy[p] = 1;
        }else{
            res += tr[p];
            tr[p] = 0;
            lazy[p] = 2;
        }
        return res;
    }
    int mid = l + r >> 1;
    pushdown(p, l, r);
    if(cl <= mid) res += update(l, mid, cl, cr, p << 1, k);
    if(cr > mid) res += update(mid + 1, r, cl, cr, p << 1|1, k);
    pushup(p);
    return res;
}
int query(int l, int r, int cl, int cr,int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    pushdown(p, l, r);
    int res = 0, mid = l + r >> 1;
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
int install(int x){
    int res = 0;
    while(!query(1 , n, id[top[x]], id[top[x]], 1) && x >= 0){
        res += update(1, n, id[top[x]], id[x] ,1, 1);
        x = fat[top[x]];
    }
    if(x >= 0){
        int r = id[x], l = id[top[x]];
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(!query(1, n, id[top[x]], mid, 1)) l = mid;
            else r = mid - 1;
        }
        res += update(1, n, l, id[x], 1, 1);
    }
    return res;
}
int uninstall(int x){ 
    return update(1, n, id[x], id[x] + siz[x] - 1, 1, 0);
}
void Solve(){
    cin >> n;
    rep(i, 1, n - 1){
        int fa;
        cin >> fa;
        son[fa].push_back(i);
    }
    dfs1(0, -1);
    dfs2(0, -1, 0);
    int m;
    cin >> m;
    while(m --){
        string s;
        int x;
        cin >> s >> x;
        if(s == "install"){
            cout << install(x) << endl;
        }else{ 
            cout << uninstall(x) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}