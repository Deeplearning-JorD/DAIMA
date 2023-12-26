/*
 * @Author: JorD
 * @LastEditTime: 2022-10-15 10:33:19
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
int get(int x){
    int res = 0;
    while(x){
        res += x & 1;
        x >>= 1;
    }
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    int t, k;
    cin >> t;
    vector<int> h(t + 1);
    rep(i, 1, t) cin >> h[i];
    cin >> k;
    vector<int> p(k + 1);
    rep(i, 1, k) cin >> p[i];
    vector<vector<int>> f(n + 1, vector<int> (1 << k));
    vector<pair<ll,ll>> q;
    vector<bool> vis(n + 1);
    q.push_back({1, 0});
    f[1][0] = 1;
    vis[1] = true;
    while(q.size()){
        set<pair<ll,ll>> now;
        for(auto [x, y]:q){
            for(auto u:son[x]){
                if(vis[u]) continue;
                int state = y;
                for(int i = 1;i <= k;i ++ )if(u == h[p[i]]){
                    state |= (1 << (i - 1));
                }
                f[u][state] |= f[x][y];
                now.insert({u, state});
            }
        }
        q.clear();
        for(auto [x, y]:now){
            q.push_back({x, y});
            vis[x] = true;
        }
    }
    rep(i, 1, k) h[p[i]] = -1;
    vector<int> dp(1 << k);
    dp[0] = 1;
    rep(i, 1, t){
        if(h[i] == -1) continue;
        int x = h[i];
        for(int i = (1 << k) - 1;i >= 0;i --){
            for(int j = 0;j < (1 << k);j ++){
                if(!f[x][j]) continue;
                for(int ji = j^i;ji <= i;ji ++){
                    if((ji|j) == i){
                        dp[i] |= dp[ji];
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i = 0;i < (1 << k);i ++)if(dp[i]){
        res = max(res, get(i));
    }
    cout << k - res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}