/*
 * @Author: JorD
 * @LastEditTime: 2022-09-12 23:28:09
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
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n + 1);
    rep(i, 1, n) cin >> a[i].first;
    rep(i, 1, n) cin >> a[i].second;
    vector<ll> c(n);
    rep(i, 0, n - 1) c[i] = a[i + 1].second - a[i + 1].first;
    sort(c.begin(), c.end());
    ll l = 0, r = n - 1;
    ll idx = n - 1;
    ll res = 0;
    while(r > l){
        if(c[l] + c[r] >= 0)
            r --, l ++, res ++;
        else l ++;
    }
    cout << res << endl;
    // rep(i, 0, n - 1) cout << c[i] << ' ';
    // cout << endl;
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