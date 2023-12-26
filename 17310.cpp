/*
 * @Author: JorD
 * @LastEditTime: 2022-12-27 22:39:02
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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(all1(a));
    for(int i = 2;i <= n;i ++){
        ll now = a[i] * a[i - 1];
        a[i] = now;
        a[i - 1] = 1;
    }
    ll res = accumulate(a.begin(), a.end(), 0ll);
    cout << res * 2022 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}