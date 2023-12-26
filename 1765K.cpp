/*
 * @Author: JorD
 * @LastEditTime: 2022-11-30 00:38:52
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
void Solve(){
    int n;
    cin >> n;
    ll sum = 0;
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1));
    rep(i, 1, n) rep(j, 1, n){cin >> f[i][j]; sum += f[i][j];}
    ll res = 0;
    rep(i, 1, n){
        res = max(res, sum - f[i][n + 1 - i]);
        res = max(res, sum - f[n + 1 - i][i]);
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