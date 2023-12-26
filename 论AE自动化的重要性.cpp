/*
 * @Author: JorD
 * @LastEditTime: 2023-03-26 17:37:02
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
const int N = 2e5 + 10, mod = 1e9 + 7;
int cd[N];
ll need[N];
int rd[N];
vector<pair<int,int>> son[N];
int use[N];
ll res = 0;
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, k){
        int a, b; cin >> a >> b;
        use[a] = b;
    }
    while(m --){
        int x, y, c;
        cin >> x >> y >> c;
        cd[x] ++;
        rd[y] ++;
        son[x].push_back({y, c});
    }
    vector<int> root;
    vector<ll> dp(n + 1, -1);
    rep(i, 1, n) if(!rd[i]) root.push_back(i);
    auto dfs = [&](auto dfs, int now){
        if(dp[now] != -1) return dp[now];
        dp[now] = use[now];
        for(auto [x, y]:son[now]){
            dp[now] += dfs(dfs, x) * y;
        }
        if(rd[now]) res += dp[now];
        return dp[now];
    };
    for(auto x:root) res = (res + dfs(dfs, x)) % mod;
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}