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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> son(n + 1);
    vector<vector<pair<int,int>>> zson(n + 1);
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        zson[b].push_back({a, c});
    }
    int S, F;
    cin >> S >> F;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(n + 1, 1e9);
    dist[S] = 0;
    q.push({0, S});
    while(q.size()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > o + w){
                dist[x] = o + w;
                q.push({dist[x], x}); 
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (2));
    // dp[i][j]表示从1到i多走了为j的路径数量
    function<int(int,int)> dfs = [&](int now, int k){
        if(k < 0) return 0;
        if(dp[now][k]) return dp[now][k];
        for(auto [x, w]:zson[now]){
            dp[now][k] += dfs(x, dist[now] - dist[x] - w + k);
        }
        return dp[now][k];
    };
    dp[S][0] = 1;
    cout << dfs(F, 0) + dfs(F, 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}