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
const int N = 210, mod = 1e9 + 7;
int dp[2][N][N][N]; // dp[i][j][x]表示目前是 i 次店，j 次 花， 现在还X酒的方案数

void Solve(){
    int n, m; cin >> n >> m;
    dp[0][0][0][2] = 1;
    
    // for(int bit = 0;bit < n + m;bit ++){
    //     int r = bit&1, l = (bit+1)&1;
    //     // cout << bit << endl;
    //     for(int i = 0;i <= n;i ++)
    //         for(int j = 0;j <= m;j ++)if(i + j == bit){
    //         for(int x = m + 2;x >= 0;x --){
    //             if(x * 2 <= m + 2 && i + 1 <= n)
    //             dp[bit + 1][i + 1][j][x * 2] += dp[bit][i][j][x];
    //             if(x - 1 >= 0 && j + 1 <= m)
    //             dp[bit + 1][i][j + 1][x - 1] += dp[bit][i][j][x];
    //             dp[bit + 1][i][j + 1][x - 1] %= mod;
    //             dp[bit + 1][i + 1][j][x * 2] %= mod;
            
    //         }
    //     }

        
    // }
    for(int bit = 1;bit <= n + m;bit ++){
        //     for(int j = 0;j <= m;j ++){
        //         for(int  m;bit ++){
        int r = bit&1, l = (bit+1)&1;
        // cout << bit << endl;
        for(int i = 0;i <= min(bit, n);i ++){
            int j = bit - i;
            if(bit - i > m) continue;
            // cout << ((i + j) == bit) << endl;
            // cout << bit << ":" << i << ' ' << j << endl;
            for(int x = m + 2;x >= 0;x --){
                if(bit == n + m){
                // if(x % 2 == 0 && i >= 1)
                // dp[bit][i][j][x] += dp[bit - 1][i - 1][j][x / 2];
                if(j >= 1)
                    dp[r][i][j][x] += dp[l][i][j - 1][x + 1];
                    dp[r][i][j][x] %= mod;
                }else{
                    
                if(x % 2 == 0 && i >= 1)
                dp[r][i][j][x] += dp[l][i - 1][j][x / 2];
                if(j >= 1)
                dp[r][i][j][x] += dp[l][i][j - 1][x + 1];
                dp[r][i][j][x] %= mod;
                }
            }
        }
        for(int i = 0;i <= n;i ++){
            for(int j = 0;j <= m;j ++){
                for(int x = 0;x <= m + 2;x ++)
                    dp[l][i][j][x] = 0; 
            }
        }
    }
    cout << dp[(n + m) & 1][n][m][0] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}