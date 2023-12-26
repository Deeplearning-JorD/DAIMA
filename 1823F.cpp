/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 00:27:49
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
const int N = 2e5 + 10, mod = 998244353;
vector<int> son[N];
int depth[N];
int f[N][30];
void dfs(int now,int fa){
    depth[now]=depth[fa]+1;
    f[now][0]=fa;
    for(int i=1;i<=20;i++){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(auto x:son[now]){
        if(x==fa) continue;
        dfs(x,now);
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        if(depth[f[a][i]]>=depth[b])
            a=f[a][i];
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(f[a][i]==f[b][i]) continue;
        a=f[a][i];
        b=f[b][i];
    }
    return f[a][0];
}
int in[N];
void Solve(){
    int n, s, t;
    cin >> n >> s >> t;
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
        in[x] ++;
        in[y] ++;
    }
    dfs(t, 0);
    rep(i, 1, n){
        if(i == t) cout << 1 << ' ';
        else{
            ll res = 1ll * in[i] * (depth[lca(s, i)] - 1) % mod;
            cout << res << ' ';
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