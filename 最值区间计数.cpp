/*
 * @Author: JorD
 * @LastEditTime: 2022-12-16 20:38:58
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
const int N = 1e6 + 10, mod = 998244353;
int dp[N];
void Solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    dp[1] = 1;
    dp[2] = 2;
    ll idx = 5;
    rep(i, 3, N - 5){
        dp[i] = (dp[i - 1] * idx) % mod;
        idx ++;
    }
    Solve();
    return 0;
}