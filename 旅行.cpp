/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 19:56:46
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
const int N = 3e5 + 10;
vector<pair<ll, ll>> son[N];
ll w[N];
int n;
map<pair<ll,ll>, bool> st;
bool vis[N];
ll res = 0;
vector<int> ve;
void dfs(int now, int fa, ll sum){
    vis[now] = true;
    ve.push_back(now);
    res = max(res, sum + w[now]);
    for(auto x:son[now]){
        if(x.first == fa) continue;
        if(st[{now, x.first}]) continue;
        if(sum + w[now] - x.second < 0) continue;
        if(vis[x.first]) continue;
        st[{now, x.first}] = true;
        res = max(res, sum + w[now] - x.second + w[x.first]);
        dfs(x.first, now, sum + w[now] - x.second);
    }
}
void Solve(){
    cin >> n;
    rep(i, 1, n) cin >> w[i]; 
    rep(i, 2, n){
        ll u, v, p;
        cin >> u >> v >> p;
        son[u].push_back({v, p});
        son[v].push_back({u, p});
    }
    rep(i, 1, n){
        res = max(res, w[i]);
        dfs(i, 0, 0);
        for(auto x:ve){
            vis[x] = false;
        }
        ve.clear();
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}