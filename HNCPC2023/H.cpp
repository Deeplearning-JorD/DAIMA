/*
 * @Author: JorD
 * @LastEditTime: 2023-05-09 21:00:38
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
    double n, k;
    cin >> n >> k;
    ll l = max(n - 0.5 * (k - 1), 0.0) + 0.5;
    ll x = min(k - 1, 2 * n);
    ll y = (max(n - 0.5 * x, 0.0) + 0.5);
    ll r = x + (y) * (k - x);
    cout << l << ' ' << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}