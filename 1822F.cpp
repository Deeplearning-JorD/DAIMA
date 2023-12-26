/*
 * @Author: JorD
 * @LastEditTime: 2023-04-25 20:27:38
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
void Solve(){
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<ll> dist(n + 1), up(n + 1), depth(n + 1), len(n + 1);
    vector<ll> l(n + 1), r(n + 1);
    function<void(int,int)> dfs = [&](int now, int fa){
        depth[now] = depth[fa] + c;
        for(auto x:son[now])if(x != fa){
            dfs(x, now);
            len[now] = max(len[now], len[x] + k);
            if(len[x] + k >= r[now]){
                l[now] = r[now];
                r[now] = len[x] + k;
            }else if(len[x] + k > l[now]) l[now] = len[x] + k;
        }
    };
    function<void(int,int)> dp = [&](int now, int fa){
        dist[now] = max(r[now], up[now]);
        for(auto x:son[now])if(x != fa){
            if(len[x] + k == r[now]){
                up[x] = max(up[now] + k, l[now] + k);
            }else up[x] = max(up[now] + k, r[now] + k);
            dp(x, now);
        }
    };
    depth[0] = -c;
    dfs(1, 0);
    dp(1, 0);
    ll res = 0;
    for(int i = 1;i <= n;i ++){
        res = max(res, dist[i] - depth[i]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}