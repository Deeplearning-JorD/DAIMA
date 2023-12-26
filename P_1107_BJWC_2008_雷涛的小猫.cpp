/*
 * @Author: JorD
 * @LastEditTime: 2023-04-18 10:56:30
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
const int N = 4010;
int a[N][N];
int dp[N][N];
void Solve(){
    int n, m, down;
    cin >> n >> m >> down;
    rep(i, 1, n){
        int t; cin >> t;
        while(t --){
            int x; cin >> x;
            a[i][x] ++;
        }
    }
    int now = 0;
    for(int i = m;i >= 0;i --){
        int last = 0;
        for(int j = 1;j <= n;j ++){
            dp[j][i] = max(now, dp[j][i + 1]) + a[j][i];
            last = max(last, dp[j][i + down - 1]);
        }
        now = last;
    }
    int res = 0;
    rep(i, 1, n){
        res = max(res, dp[i][0]);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}