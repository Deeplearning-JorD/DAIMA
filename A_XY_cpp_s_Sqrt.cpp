/*
 * @Author: JorD
 * @LastEditTime: 2022-12-25 13:38:36
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
const int N = 1e4 + 10;
ll dp[N];
void Solve(){
    ll n;
    cin >> n;
    ll res = 0;
    int idx = 3;
    for(ll i = 0;i <= n;i = dp[idx ++]){
        ll r = min(n, dp[idx]);
        res += (idx - 1) * (r - i);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 3, N - 10){
        dp[i] = i * i * 114 - 515;
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}