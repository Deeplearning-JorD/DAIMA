/*
 * @Author: JorD
 * @Date: 2023-11-29 21:16:46
 * @LastEditTime: 2023-11-29 22:38:58
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 2e5 + 10;
vector<vector<int>> son;
int a[N];
int idx, top, scc_cnt;
int dfn[N], low[N], sta[N], in[N];
ll id[N], w[N], cnt[N];
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ top] = now, in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]) low[now] = min(low[now], dfn[x]);
    }
    if(low[now] == dfn[now]){
        int y;
        scc_cnt ++;
        do{
            y = sta[top --];
            in[y] = 0;
            id[y] = scc_cnt;
            w[scc_cnt] += a[y];
            cnt[scc_cnt] ++;
        }while(y != now);
    }
}
void Solve(){
    int n, m; cin >> n >> m;
    son.clear(); son.resize(n + 1);
    idx = 0, scc_cnt = 0, top = 0;
    rep(i, 1, n){
        dfn[i] = 0; w[i] = 0; cnt[i] = 0; id[i] = 0;
        cin >> a[i];
    }
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
    }
    rep(i, 1, n)if(!dfn[i])tarjan(i);
    vector<pair<int,ll>> dp(scc_cnt + 1); 
    vector<vector<int>> ls(scc_cnt + 1);
    rep(i, 1, n){
        for(auto x:son[i])if(id[x] != id[i])
            ls[id[i]].push_back(id[x]);
    }
    int mx = 0;
    for(int i = 1;i <= scc_cnt;i ++){
        dp[i] = {cnt[i], w[i]};
        for(auto x:ls[i]){
            pair<int,ll> t = {dp[x].first + cnt[i], dp[x].second + w[i]};
            if(t.first > dp[i].first) dp[i] = t;
            else if(t.first == dp[i].first) dp[i].second = min(dp[i].second, t.second);
        }
        mx = max(mx, dp[i].first);
    }
    ll mxx = 2e18;
    rep(i, 1, scc_cnt)if(mx == dp[i].first && mxx > dp[i].second){
        mxx = dp[i].second;
    }
    cout << mx << ' ' << mxx << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}