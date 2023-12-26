/*
 * @Author: JorD
 * @LastEditTime: 2023-01-15 20:11:05
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
    ll w, d, h;
    cin >> w >> d >> h;
    ll a, b, f, g;
    cin >> a >> b >> f >> g;
    ll res = h + abs(a - f) + min(b + g, 2 * d - (b + g));
    ll ans = h + abs(b - g) + min(a + f, 2 * w - (a + f));
    cout << min(res, ans) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}