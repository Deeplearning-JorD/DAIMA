/*
 * @Author: JorD
 * @LastEditTime: 2023-05-02 01:22:18
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
int dist[N];
int f[N][30];
void dfs(int now,int fa){
    dist[now]=dist[fa]+1;
    f[now][0]=fa;
    for(int i=1;i<=20;i++){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(auto x:son[now]){
        if(x==fa) continue;
        dfs(x,now);
    }
}
int LCA(int a,int b){
    if(dist[a]<dist[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        if(dist[f[a][i]]>=dist[b])
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
int get(int x, int y){
    int lca = LCA(x, y);
    int res = dist[x] + dist[y] - 2 * dist[lca];
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
    dfs(1, 0);
    int m;
    cin >> m;
    while(m --){
        int x, y, a, b, k;
        cin >> a >> b >> x >> y >> k;
        int need = get(x, y);
        int lca = LCA(a, b);
        int now = get(a, lca) + get(b, lca) + 1;
        if(need <= k && need % 2 == k % 2){
            cout << "YES\n";
            continue;
        }
        now = get(a, x) + get(b, y) + 1;
        if(now <= k && now % 2 == k % 2){
            cout << "YES\n";
            continue;
        }
        now = get(a, y) + get(b, x) + 1;
        if(now <= k && now % 2 == k % 2){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}