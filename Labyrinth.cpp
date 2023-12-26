/*
 * @Author: JorD
 * @Date: 2023-10-15 15:48:10
 * @LastEditTime: 2023-10-15 17:13:23
 * 当一个子树内的边集确定时，
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
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m; cin >> n >> m;
    vector<ll> c(n << 1|1);
    rep(i, 1, n){
        cin >> c[i];
    }
    vector<ll> dp(n << 1|1, 1e18);
    rep(i, 1, n << 1|1){
        f[i] = i;
    }
    vector<array<int,3>> e(m);
    for(auto &[x, y, c]:e) cin >> y >> c >> x;
    sort(e.begin(), e.end(), greater<>());
    int idx = n;
    for(auto [w, x, y]:e){
        x = find(x), y = find(y);
        if(x == y) continue;
        f[x] = f[y] = ++ idx;
        dp[idx] = max({
            min(w - c[x], dp[y] - c[x]),
            min(w - c[y], dp[x] - c[y])
        });
        c[idx] = c[x] + c[y];
    }
    if(dp[idx] <= 0) cout << -1 << endl;
    else cout << dp[idx] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}