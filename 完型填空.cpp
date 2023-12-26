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
const int N = 110;
int f[4][N];
int n;
int res;
int dp[N][26][26][26][26];
void Solve(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < 4;j ++)
            cin >> f[j][i];
    }
    for(int i = 1;i <= n;i ++){
        for(int a1 = 0;a1 <= 25;a1 ++){
            for(int a2 = 0;a2 <= 25;a2 ++){
                for(int a3 = 0;a3 <= 25;a3 ++){
                    for(int a4 = 0;a4 <= 25;a4 ++){
                        int &W = dp[i][a1][a2][a3][a4];
                        if(a1) W = max(W, dp[i - 1][a1 - 1][a2][a3][a4] + f[0][i]);
                        if(a2) W = max(W, dp[i - 1][a1][a2 - 1][a3][a4] + f[1][i]);
                        if(a3) W = max(W, dp[i - 1][a1][a2][a3 - 1][a4] + f[2][i]);
                        if(a4) W = max(W, dp[i - 1][a1][a2][a3][a4 - 1] + f[3][i]);

                    }
                }
            }
        }
    }
    cout << dp[n][n/4][n/4][n/4][n/4] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}