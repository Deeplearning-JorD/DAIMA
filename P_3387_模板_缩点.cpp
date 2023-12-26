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
const int N = 1e4 + 10;
int dfn[N], low[N], idx, cnt, scc_cnt;
int sta[N], in[N], id[N];
ll a[N];
ll val[N];
int n, m;
vector<int> son[N];
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ cnt] = now; in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]) low[now] = min(low[now], dfn[x]);
    }
    if(dfn[now] == low[now]){
        scc_cnt ++;
        int y;
        do{ 
            y = sta[cnt --];
            id[y] = scc_cnt;
            in[y] = 0;
            val[scc_cnt] += a[y];
        }while(y != now);
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
    }
    rep(i, 1, n)if(!dfn[i])tarjan(i);
    vector<vector<int>> zson(scc_cnt + 1);
    rep(i, 1, n)in[i] = 0;
    rep(i, 1, n){
        for(auto x:son[i]){
            if(id[x] == id[i]) continue;
            zson[id[i]].push_back(id[x]);
            in[id[x]] ++;
        }
    }
    queue<int> q;
    ll res = 0;
    vector<ll> dp(scc_cnt + 1);
    rep(i, 1, scc_cnt)if(!in[i]){
        q.push(i);
        dp[i] = val[i];
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        res = max(res, dp[t]);
        for(auto x:zson[t]){
            dp[x] = max(dp[x], dp[t] + val[x]);
            if(-- in[x] == 0) q.push(x);
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}