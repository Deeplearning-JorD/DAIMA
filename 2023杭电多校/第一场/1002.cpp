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
    int n; cin >> n;
    vector<ll> w(n + 1, 1);
    rep(i, 1, n) cin >> w[i];
    vector<vector<int>> son(n + 1);
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<vector<ll>> dp(n + 1, vector<ll> (3, 2e18));
    // dp[i][0] 表示以i为根的子树i放置了路由器的最小代价
    // dp[i][1] 表示以i为根的子树i没有放路由器的最小代价
    // dp[i][2] 表示以i为根的子树i没有放路由器但是子树全覆盖的最小代价
    function<void(int,int)> dfs = [&](int now, int fa){
        bool er = true;
        bool ff = false;
        ll sum = 0, ans = 0, ss = 0, mx = 2e18;
        for(auto x:son[now])if(x != fa){
            er = false; 
            dfs(x, now);
            ans += min(dp[x][0], dp[x][1]);
            mx = min(mx, dp[x][0] - dp[x][1]);
            if(dp[x][0] <= dp[x][1]){
                ff = true;
            }
            ss += min({dp[x][0], dp[x][1], dp[x][2]});
        }
        dp[now][2] = ans;
        if(!ff) ans += mx; 
        if(er){
            dp[now][0] = w[now];
        }else{
            dp[now][0] = ss + w[now];
            dp[now][1] = ans;
        }
    };
    dfs(1, 0);
    cout << min(dp[1][0],dp[1][1]) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}