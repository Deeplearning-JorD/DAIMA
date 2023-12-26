/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 21:18:44
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
const int N = 510;
char f[N][N];
int dp[2][N][1010];
void Solve(){
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i, 1, n) scanf("%s",(f[i]+1));
    int x = 1, y = 1;
    int st = 0;
    int T = n + m - 1;
    rep(i, 0, n) rep(j, 0, k) dp[0][i][j] = dp[1][i][j] = 0;
    while(T --){
        int lastx = x, lasty = y;
        while(x && y <= m){
            for(int i = k;i >= 0;i --){
                auto &r = dp[(st+1)&1][x][i];
                auto &l = dp[(st+1)&1][x+1][i];
                auto &now = dp[st][x][i];
                if(f[x][y] == '1'){
                    l = max(l, now + 1);
                    r = max(r, now + 1);
                }else if(f[x][y] == '?'){
                    l = max(l, now);
                    r = max(r, now);
                    if(i){
                        r = max(r, dp[st][x][i - 1] + 1);
                        l = max(l, dp[st][x][i - 1] + 1);
                    }
                }else{
                    l = max(l, now);
                    r = max(r, now);
                }
                now = 0;
            }
            x--, y++;
        }
        if(lastx == n) lasty ++;
        else lastx ++;
        x = lastx, y = lasty;
        st ^= 1;
    }
    int res = 0;
    for(int i = 0;i <= k;i ++)
    res = max(res, dp[st][n][i]);
    printf("%d\n",res);
    return;
}
int main(){
    int t; scanf("%d",&t); while(t --)
    Solve();
    return 0;
}