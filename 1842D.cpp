/*
 * @Author: JorD
 * @LastEditTime: 2023-07-14 10:03:56
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, m){
        int x, y, c;
        cin >> x >> y >> c;
        son[y].push_back({x, c});
        son[x].push_back({y, c});
    }
    // dp[i] 表示的存活时间
    vector<ll> dp(n + 1, 2e18);
    vector<bool> st(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, n});
    dp[n] = 0;
    while(q.size()){
        auto [w, now] = q.top(); q.pop();
        if(st[now]) continue;
        st[now] = true;
        for(auto [x, y] : son[now]){
            if(dp[x] > dp[now] + y){
                dp[x] = dp[now] + y;
                q.push({dp[x], x});
            }
        }
    }
    if(dp[1] == 2e18){
        cout << "inf\n";
        return;
    }cout << dp[1] << ' ';
    vector<pair<string,int>> res;
    int last = 0;
    while(dp[1]!=0){
        ll mi = 2e18;
        string mb(n, '0');
        rep(j, 1, n)if(dp[j]>0){mi=min(mi,dp[j]),mb[j-1]='1';}
        res.push_back({mb, mi});
        rep(j, 1, n)dp[j]-=mi;
    }
    cout << res.size() << endl;
    for(auto [x, y] : res) cout << x << ' ' << y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}