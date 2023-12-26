/*
 * @Author: JorD
 * @LastEditTime: 2023-04-26 21:11:03
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
const int N = 3e5 + 10, mod = 998244353;
// 下标很容易搞错
vector<int> son[N];
int siz[N], zson[N], fat[N];
ll depth[N];
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void dfs(int now, int fa){ 
    fat[now] = fa;
    siz[now] = 1;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
        if(siz[zson[now]] < siz[x]){
            zson[now] = x;
        }
    }
}
int top[N], id[N], idx;
void dfs1(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    depth[id[now]] = depth[id[fa]] + 1; 
    if(!zson[now]) return;
    dfs1(zson[now], now, T);
    for(auto x:son[now])if(x != zson[now] && x != fa){
        dfs1(x, now, x);
    }
}
ll pre[55][N];
int lca(int x, int y){
    while(top[x] != top[y]){
        if(depth[id[top[x]]] < depth[id[top[y]]]) swap(x, y);
        x = fat[top[x]];
    }
    if(depth[id[x]] > depth[id[y]]) swap(x, y);
    return x;
}
ll calc(int now, int fa, int k){
    ll res = 0;
    while(top[now] != top[fa]){
        int l = id[top[now]], r = id[now];
        res = (res + pre[k][r] - pre[k][max(0, l - 1)]) % mod;    
        now = fat[top[now]];
    }  
    res = (res + pre[k][id[now]] - pre[k][max(0, id[fa] - 1)]) % mod;
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    depth[0] = -1;
    dfs(1, 0);
    dfs1(1, 0, 1);
    for(int i = 1;i <= 50;i ++){
        for(int j = 1;j <= n;j ++){
            pre[i][j] = (pre[i][j - 1] + fpow(depth[j], i, mod)) % mod;
        }
    }
    int m;
    cin >> m;
    while(m --){
        int l, r, k;
        cin >> l >> r >> k;
        int T = lca(l, r);
        ll res = (calc(l, T, k) + calc(r, T, k)) % mod;
        res = ((res - fpow(depth[id[T]], k, mod)) % mod + mod) % mod;
        cout << res << endl;
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