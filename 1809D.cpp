/*
 * @Author: JorD
 * @LastEditTime: 2023-03-24 01:16:17
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
const ll a = 1e12, b = (ll)(1e12) + 1;
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = '0' + s;
    vector<vector<ll>> dp(n + 1, vector<ll> (2, 4e18));
    // dp[i][0/1]表示前i个且当前为0/1结尾上升的最小代价
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1;i <= n;i ++){
        if(s[i] == '0'){
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + b);
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            if(i > 1) dp[i][1] = min(dp[i][1], dp[i - 2][0] + a);
        }else{
            dp[i][1] = min({dp[i][1], dp[i - 1][0], dp[i - 1][1]});
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + b);
        }
    }
    cout << min({dp[n][0], dp[n][1], n * b}) << endl;
    cout << n * b << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}