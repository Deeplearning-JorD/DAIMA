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
int dp[N][N][2];
int num[N][N][2];
void dfs(int i, int j, int k){
    if(i == 1 && j == 1) return;
    if(i - 1 >= 1){
        if(dp[i][j][k] - num[i][j][k] == dp[i - 1][j][k]){
            dfs(i - 1, j, k);
            cout << 'D';
            return;
        }
    }
    if(j - 1 >= 1){
        if(dp[i][j][k] - num[i][j][k] == dp[i][j - 1][k]){
            dfs(i, j - 1, k);
            cout << 'R';
            return;
        }
    }
}
void Solve(){
    int n;
    cin >> n;
    bool zero = false;
    int sx = 0, sy = 0;
    rep(i, 1, n){
        rep(j, 1, n){
            int x; cin >> x;
            if(x == 0){
                zero = true;
                sx = i, sy = j;
                num[i][j][0] = num[i][j][1] = 1;
                continue;
            }
            int sum = 0;
            while(x % 2 == 0) x /= 2, sum ++;
            num[i][j][0] = sum;
            sum = 0;
            while(x % 5 == 0) x /= 5, sum ++;
            num[i][j][1] = sum;
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][1][0] = num[1][1][0];
    dp[1][1][1] = num[1][1][1];
    rep(i, 1, n)rep(j, 1, n){
        if(i - 1 >= 1)
        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + num[i][j][0]);
        if(j - 1 >= 1)
        dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + num[i][j][0]); 
    }
    rep(i, 1, n)rep(j, 1, n){
        if(i - 1 >= 1)
        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1] + num[i][j][1]);
        if(j - 1 >= 1)
        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + num[i][j][1]); 
    }
    int res = min(dp[n][n][0], dp[n][n][1]);
    if(zero && res > 1){
        cout << 1 << endl;
        if(sx == 1) rep(i, 2, n) cout << 'R';
        rep(i, 2, n){
            cout << 'D';
            if(i == sx)rep(j, 2, n)cout << 'R';
        }
        return;
    }
    cout << res << endl;
    if(dp[n][n][0] > dp[n][n][1]) dfs(n, n, 1);
    else dfs(n, n, 0);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}