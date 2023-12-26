#pragma GCC optimize(2)
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
const int N = 2e5 + 10;
int a[N], b[N];
int B[210][210][210];
int dp[2][210];
int c[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i] >> b[i];
    rep(i, 1, m) cin >> c[i];
    for(int i = 1;i <= n;i ++){
        vector<vector<int>> d(2, vector<int> (210));
        for(int k = i;k <= n;k ++){
            int mx = 0;
            for(int j = 0;j <= 200;j ++){
                d[k&1][j] = d[(k+1)&1][j];
                if(a[k]<=j) d[k&1][j]=max(d[k&1][j],d[(k+1)&1][j-a[k]] + b[k]);
                mx = max(mx, d[k&1][j]);
                B[i][k][j] = mx;
            }
        }
    }
    for(int i = max(1, m - 200 + 1);i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            dp[i&1][j] = dp[(i+1)&1][j];
            for(int k = 0;k < j;k ++){
                dp[i&1][j] = max(dp[i&1][j], dp[(i+1)&1][k] + B[k + 1][j][c[i]]);
            }
        }
    }
    cout << dp[m&1][n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}