/*
 * @Author: JorD
 * @LastEditTime: 2022-09-26 00:00:50
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
    int n;
    cin >> n;
    vector<db> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    double l = 1e18, r = -1e18;
    rep(i, 1, n){
        double x; cin >> x;
        l = min(l, a[i] - x);
        r = max(r, a[i] + x);
    }
    cout << (l + r) / 2 << endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    cout<< SPO(6);
    while(t --)
    Solve();
    return 0;
}