/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 12:52:05
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
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> son(n + 1);
    vector<ll> s(n + 1);
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    rep(i, 1, n) cin >> s[i];
    ll res = 0;
    vector<vector<ll>> dp(n + 1, vector<ll> (2));
    // dp[i][0]表示以i为根的子树不多分配1的情况下最大的价值
    // dp[i][1]表示以i为根的子树多分配了1的情况下的最大价值
    function<void(int,ll)> dfs = [&](int now, ll p){
        //加上本身的价值
        dp[now][0] = p * s[now];
        dp[now][1] = p * s[now] + s[now];
        if(!siz(son[now])) return;
        vector<pair<ll,ll>> need;
        for(auto x:son[now]){
            dfs(x, p / siz(son[now]));
            need.push_back({dp[x][0], dp[x][1]});
            dp[now][0] += dp[x][0];
            dp[now][1] += dp[x][0];
        }        
        sort(need.begin(), need.end(), [&](pair<ll,ll> &x, pair<ll,ll> &y){
            return x.second - x.first > y.second - y.first;
        });
        int m = p % siz(son[now]);
        rep(i, 0, m - 1) dp[now][0] += need[i].second - need[i].first;
        //多一点偏爱
        rep(i, 0, m) dp[now][1] += need[i].second - need[i].first;
    };
    dfs(1, k);
    cout << dp[1][0] << endl;
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