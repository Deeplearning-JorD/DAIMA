/*
 * @Author: JorD
 * @LastEditTime: 2023-04-26 12:17:32
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
const int N = 2010;
int dp[N][N];
// dp[i][j] 表示第一个字符串匹配前i个第二个字符串匹配了前j个的最小距离
void Solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int k;
    cin >> k;
    int n = s1.size(), m = s2.size();
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1;i <= n;i ++) dp[i][0] = dp[i - 1][0] + k;
    for(int i = 1;i <= m;i ++) dp[0][i] = dp[0][i - 1] + k;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            dp[i][j] = min({dp[i][j], dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + abs(s1[i] - s2[j])});
        }
    }
    cout << dp[n][m] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}