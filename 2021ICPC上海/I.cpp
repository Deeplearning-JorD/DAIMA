/*
 * @Author: JorD
 * @Date: 2023-11-23 00:07:56
 * @LastEditTime: 2023-11-23 00:36:23
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
const int M = 2700;
#define int long long
int dp[2][7010][110];
void Solve(){
    int n, k; cin >> n >> k;
    auto update = [&](int i, int j, int ii, int m, int w, int c){
        if(j + m <= i * 26 && j + m >= -i * 26 && ii + c <= k) 
        dp[i&1][j + m+M][ii + c] = max(dp[i&1][j + m+M][ii + c], dp[(i+1)&1][j+M][ii] + w);
    };
    memset(dp, -0x3f, sizeof dp);
    dp[0][M][0] = 0;
    for(int i = 1;i <= n;i ++){
        int m, w; cin >> w >> m;
        for(int j = - i * 26;j <= i * 26;j ++){
            for(int ii = 0;ii <= k;ii ++){
                update(i,j,ii,0,0,0);
                update(i,j,ii,m,w,0);
                update(i,j,ii,2*m,w,1);
                update(i,j,ii,-m,w,0);
                update(i,j,ii,-2*m,w,1);
            }
        }
    }
    int res = 0;
    for(int j = 0;j <= k;j ++)
        res = max(res, dp[n&1][M][j]);
    cout << res;
    return; 
}
#undef int
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}