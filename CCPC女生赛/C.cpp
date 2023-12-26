/*
 * @Author: JorD
 * @LastEditTime: 2022-11-30 14:51:19
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
#define Pi acos(-1)
void Solve(){
    int n;
    cin >> n;
    double R, se;
    cin >> R >> se;
    se = min(2 * Pi - se, se);
    vector<double> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    double res = R * se;
    rep(i, 1, n){
        res = min(res, 2 * (R - a[i]) + se * a[i]);
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    cout << SPO(10);
    Solve();
    return 0;
}