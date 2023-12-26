/*
 * @Author: JorD
 * @LastEditTime: 2022-09-27 23:46:24
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
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<vector<ll>>> f(n + 1,vector<vector<ll>> (m + 1, vector<ll> (2,0)));
    vector<vector<ll>> a(n + 1, vector<ll> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    f[1][1][1] = f[1][1][0] = a[1][1];
    rep(i, 1, n){
        rep(j, 1, m){
            if(i == 1&&j == 1) continue;
            if(i == 1) f[i][j][0] = f[i][j - 1][0] + a[i][j];
            else if(j == 1) f[i][j][0] = f[i - 1][j][0] + a[i][j];
            else f[i][j][0] = min(f[i][j - 1][0] + a[i][j], f[i - 1][j][0] + a[i][j]);
            if(i == 1) f[i][j][1] = f[i][j - 1][1] + a[i][j];
            else if(j == 1) f[i][j][1] = f[i - 1][j][1] + a[i][j];
            else f[i][j][1] = max(f[i][j - 1][1] + a[i][j], f[i - 1][j][1] + a[i][j]);
        }
    }
    if(f[n][m][0] <= 0&&f[n][m][1] >= 0&&(f[n][m][0]%2==0||f[n][m][1]%2==0)) cout << "YES" << endl;
    else cout << "NO" << endl; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}