/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 22:03:40
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> son(n + 1);    
    for(int i = 1;i <= m;i ++){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    //dp[i][st] 表示i这个点杀了st状态下的人 所花费的最小时间。
    //1 << 8 * 2e4
    int e, T;
    cin >> e >> T;
    vector<vector<vector<int>>> pos(k + 1, vector<vector<int>> (n + 1));
    for(int i = 1;i <= e;i ++){
        int p, x, y;
        cin >> p >> x >> y;
        pos[p][x].push_back(y);
    }
    for(int i = 1;i <= k;i ++){
        for(int j = 1;j <= n;j ++){
            sort(all(pos[i][j]));
        }
    }
    int ay, yy;
    cin >> ay >> yy;
    auto work = [&](int be) -> vector<int>{
        vector<vector<int>> dp(1 << k, vector<int> (n + 1, 1e9));
        dp[0][be] = 0; 
        for(int st = 0;st < 1 << k;st ++){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            for(int i = 1;i <= n;i ++ ){
                if(dp[st][i] != 1e9){
                    q.emplace(dp[st][i], i);
                }
            }
            while(!q.empty()){
                auto [val, now] = q.top(); q.pop();
                for(auto [x, y]:son[now]){
                    if(dp[st][x] > dp[st][now] + y){
                        dp[st][x] = dp[st][now] + y;
                        q.emplace(dp[st][x], x);
                    }
                }
            }
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= k;j ++){
                    if(st & 1 << (j - 1)) continue;
                    auto p = lower_bound(pos[j][i].begin(), pos[j][i].end(), dp[st][i]);
                    if(p != pos[j][i].end())
                    dp[st|(1 << (j - 1))][i] = min(dp[st|(1 << (j - 1))][i], *p); 
                }
            }
        }
        vector<int> f(1 << k, 1e9);
        for(int i = 0;i < 1 << k;i ++){
            for(int j = 1;j <= n;j ++){
                f[i] = min(f[i], dp[i][j]);
            }
        }
        return f;
    };
    auto a = work(ay), b = work(yy);
    int res = 1e9;
    for(int i = 0;i < 1 << k;i ++){
        res = min(res, max(a[i], b[(1 << k) - 1 - i]));
    }
    if(res > T) cout << -1 << endl;
    else cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}