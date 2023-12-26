/*
 * @Author: JorD
 * @LastEditTime: 2022-10-23 13:32:28
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
double dist(double x, double y, double sx, double sy){
    return sqrt((x - sx)*(x - sx) + (y - sy)*(y - sy));
}
double len(int x){
    int js = 0;
    while(x){
        js += x & 1;
        x >>= 1;
    }
    return js;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<double> x(n + m + 1), y(n + m + 1);
    rep(i, 0, n + m - 1) cin >> x[i] >> y[i];
    vector<vector<double>> dp(n + m + 1, vector<double>((1 << (n + m)) + 1, 1e18));
    rep(i, 0, n + m - 1) dp[i][1 << i] = sqrt(x[i]*x[i] + y[i]*y[i]);
    for(int st = 0;st < (1 << (n + m));st ++){
        double k = pow(0.5, len(st >> n));
        for(int j = 0;j < n + m;j ++) if((st >> j) & 1){
            for(int i = 0;i < n + m;i ++){
                if((st >> i) & 1) continue;
                dp[i][st ^ (1 << i)] = fmin(dp[i][st ^ (1 << i)], dp[j][st] + dist(x[i],y[i],x[j],y[j]) * k);
            }
        } 
    }
    double res = 1e18;
    for(int i = 0;i < n + m;i ++){
        for(int j = (1 << n) - 1;j < (1 << n + m);j += 1 << n){
            res = fmin(res, dp[i][j] +  sqrt(x[i]*x[i] + y[i]*y[i]) * pow(0.5, len(j >> n)));
        }
    }
    cout << SPO(10) << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    Solve();
    return 0;
}