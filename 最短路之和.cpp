/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 19:46:19
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
int g[N][N];
int dp[N][N];
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> g[i][j];
            if(i != j)
            dp[i][j] = 1e9;
        }
    }
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    vector<int> last;
    vector<ll> res;
    per(k, n, 1){
        int x = a[k];
        last.push_back(x);
        for(int i=1;i<=n;i++){
            dp[x][i] = min(dp[x][i], g[x][i]);
            dp[i][x] = min(dp[i][x], g[i][x]);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][j]);
        ll js = 0;
        for(auto u:last){
            for(auto v:last){
                js += dp[u][v];
            }
        }
        res.push_back(js);
    }
    reverse(res.begin(), res.end());
    for(auto x:res) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}