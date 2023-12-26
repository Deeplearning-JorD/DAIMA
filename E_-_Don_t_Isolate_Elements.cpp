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
const int N = 1010;
int dp[N][8];
char f[N][N];
int n, m;
bool check(int i, int j, int a, int b, int c){
    if(i - 1 >= 1 && (f[i - 1][j] ^ a) == (f[i][j] ^ b))
        return false;
    if(i + 1 <= n && (f[i + 1][j] ^ c) == (f[i][j] ^ b))
        return false;
    if(j + 1 <= m && (f[i][j + 1] ^ b) == (f[i][j] ^ b))
        return false;
    if(j - 1 >= 1 && (f[i][j - 1] ^ b) == (f[i][j] ^ b))
        return false;
    return true;
}
bool judge(int i, int a, int b, int c){
    for(int j = 1;j <= m;j ++){
        if(check(i, j, a, b, c))
            return false;
    }
    return true;
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    dp[1][1] = 1;
    rep(i, 1, n){
        for(int j = 0;j < 8;j ++){
            if(!judge(i - 1, (j >> 2) & 1, (j >> 1) & 1, j & 1)) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][j >> 1] + (j & 1));
            dp[i][j] = min(dp[i][j], dp[i - 1][4 | (j >> 1)] + (j & 1));
        }
    }
    int res = 1e9;
    for(int i = 0;i < 8;i ++){
        if(judge(n, (i >> 1) & 1, i & 1, 0))
            res = min(res, dp[n][i]);
    }
    if(res == 1e9) cout << -1 << endl;
    else cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}