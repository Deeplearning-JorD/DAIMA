/*
 * @Author: JorD
 * @LastEditTime: 2023-02-01 15:02:07
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
const int N = 1e5 + 10;
ll dp[N];
int a[510], b[510];
void Solve(){
    ll n, m;
    cin >> n >> m;
    rep(i, 1, m) cin >> a[i] >> b[i];
    memset(dp, 0x3f, sizeof dp);
    dp[n] = 0;
    // dp[i] 表示人数为i时的最小代价
    for(int j = n;j >= 1;j --){
        for(int i = 1;i <= m;i ++){
            if(j < b[i]) continue;
            ll now = j - j % b[i];
            // cout << now << ' ' << dp[j] << ' ' << a[i] << ' ' << j << endl;
            dp[now] = min(dp[now], dp[j] + a[i]);
        }
    }
    rep(i, 1, n){
        if(dp[i] < 1e18){
            cout << dp[i] << endl;
            return;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}