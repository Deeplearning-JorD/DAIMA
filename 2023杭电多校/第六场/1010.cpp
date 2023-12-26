#pragma GCC optimize(2)
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
const int mod = 1e9 + 7;
void Solve(){
    int n, m; cin >> n >> m;
    vector<ll> k(n + 1), b(n + 1);
    vector<vector<int>> ne(n + 1, vector<int> (33));
    vector<vector<pair<ll,ll>>> dp(n + 1, vector<pair<ll,ll>> (33));
    rep(i, 1, n) cin >> k[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) cin >> ne[i][0];
    for(int i = 1;i <= n;i ++){
        dp[i][0] = {k[ne[i][0]], b[ne[i][0]]};
    }
    for(int i = 1;i <= 30;i ++){
        for(int j = 1;j <= n;j ++){
            ne[j][i] = ne[ne[j][i - 1]][i - 1];
            auto [a, b] = dp[j][i - 1];
            auto [x, y] = dp[ne[j][i - 1]][i - 1]; 
            dp[j][i] = {x * a % mod, (x * b % mod + y % mod) % mod};
        }
    }
    while(m --){
        ll x, l, y;
        cin >> x >> l >> y;
        for(int i = 30;i >= 0;i --){
            if((1 << i) > l) continue;
            l -= 1 << i;
            auto [a, b] = dp[x][i];
            y = a * y % mod + b % mod;
            y %= mod;
            x = ne[x][i];
        }
        cout << y << endl;
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}