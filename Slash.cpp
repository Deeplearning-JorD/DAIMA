/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 14:45:04
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 110;
char f[N][N];
int dp[N][N];
void Solve(){
    int n, m;
    cin >> n >> m;
    memset(f, ' ', sizeof f);
    string s;
    cin >> s;
    s = ' ' + s;
    rep(i, 1, n)
    rep(j, 1, m) 
    cin >> f[i][j];
    int len = siz(s)-1;
    rep(i, 1, n){
        rep(j, 1, m){
            int w = f[i][j] == s[1];
            if(dp[i][j-1] % len== 0){
                dp[i][j] = max(dp[i][j], w + dp[i][j-1]);
            }else if(f[i][j] == s[dp[i][j - 1]%len+1]){
                dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
            }else dp[i][j] = max(dp[i][j], w + dp[i][j-1]/len*len);
            if(dp[i-1][j] % len== 0){
                dp[i][j] = max(dp[i][j], w + dp[i-1][j]);
            }else if(f[i][j] == s[dp[i-1][j]%len+1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
            }else dp[i][j] = max(dp[i][j], w + dp[i-1][j]/len*len);
        }
    }
    cout<<(dp[n][m])/len<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}