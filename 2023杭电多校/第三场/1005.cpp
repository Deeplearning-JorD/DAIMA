/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 01:33:00
 * how to Get
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
const int mod = 1e9 + 7;
void Solve(){   
    int n; cin >> n;
    vector<int> a(n + 1), c(n + 1), d(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(all1(a));
    auto b = a;
    int idx = 0;
    rep(i, 1, n) if(a[i] != a[i - 1])b[++ idx] = a[i];
    rep(i, 1, n){
        int c = lower_bound(b.begin() + 1, b.begin() + 1 + idx, a[i]) - b.begin();
        d[c] = upper_bound(a.begin() + 1, a.end(), a[i]) - a.begin();
    }
    cout << idx << endl;
    vector<ll> dp(idx + 1, 1);
    // dp[i]表示以第i小的数字结尾的方案数
    // dp[i] = (dp[1]+...+dp[i]);
    int last = 1;
    rep(i, 2, n){
        ll ans = 0;
        ll sum = 0;
        for(int j = last;j <= idx;j ++){
            sum = (sum + dp[j]) % mod;
            if(d[j] <= i){
                dp[j] = 0;
                last = j + 1;
            }else{
                dp[j] = sum;
                ans = (ans + sum) % mod;
            }
        }
        cout << ans << endl;
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