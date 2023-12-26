/*
 * @Author: JorD
 * @LastEditTime: 2023-02-01 04:58:07
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
const int N = 1e3 + 10;
vector<int> pre[N], last[N];
int res[N];
bool vis[N];
int dfs(int now){
    if(vis[now]) return 0;
    int num = 1;
    vis[now] = true;
    for(auto x:pre[now]){
        num += dfs(x);
    }
    return num;
}   
int dfs1(int now){  
    if(vis[now]) return 0;
    int num = 1;
    vis[now] = true;
    for(auto x:last[now]){
        num += dfs1(x);
    }
    return num;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        pre[y].push_back(x);
        last[x].push_back(y);
    }
    memset(res, -1, sizeof res);
    for(int i = 1;i <= n;i ++){
        memset(vis, false, sizeof vis);
        int l = dfs(i) - 1;
        memset(vis, false, sizeof vis);
        int r = dfs1(i) - 1;
        if(l + r == n - 1) res[l + 1] = i; 
    }
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