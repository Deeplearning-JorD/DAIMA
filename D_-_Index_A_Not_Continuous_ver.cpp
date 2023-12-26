/*
 * @Author: JorD
 * @LastEditTime: 2022-09-04 11:49:34
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
    vector<vector<ll>> f(n + 1, vector<ll> (m + 1, -1e18));
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, n) f[i][0] = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            if(j > i) break;
            f[i][j] = max(f[i - 1][j - 1]+ j * a[i], f[i - 1][j]);
        }
    }
    cout << f[n][m];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}