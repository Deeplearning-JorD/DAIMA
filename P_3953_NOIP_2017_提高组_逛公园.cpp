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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m, k, p;
    scanf("%d%d%d%d", &n,&m,&k,&p);
    vector<vector<pair<int,int>>> son(n + 1);
    vector<vector<pair<int,int>>> zson(n + 1);
    rep(i, 1, m){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        son[a].push_back({b, c});
        zson[b].push_back({a, c});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    q.push({0, 1});
    while(q.size()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > o + w){
                dist[x] = o + w;
                q.push({dist[x], x}); 
            }
        }
    }
    bool fail = false;
    vector<vector<bool>> st(n + 1, vector<bool> (k + 1));
    vector<vector<int>> dp(n + 1, vector<int> (k + 1));
    // dp[i][j]表示从1到i多走了为j的路径数量
    function<int(int,int)> dfs = [&](int now, int k){
        if(k < 0) return 0;
        if(st[now][k]){
            fail = true;
            return 0;
        }
        if(dp[now][k]) return dp[now][k];
        st[now][k] = true;
        int res = 0;
        for(auto [x, w]:zson[now]){
            res += dfs(x, dist[now] - dist[x] - w + k) % p;
            res %= p;
            if(fail) return 0; 
        }
        st[now][k] = false;
        dp[now][k] = res;
        return dp[now][k];
    };
    dfs(1, 0);
    dp[1][0] = 1;
    int res = 0;
    rep(i, 0, k){
        res += dfs(n, i);
        res %= p;
        if(fail){
            printf("-1\n");
            return;
        }
    } 
    printf("%d\n", res);
    return;
}
int main(){
    int t; scanf("%d", &t); while(t --)
    Solve();
    return 0;
}