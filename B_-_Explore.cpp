/*
 * @Author: JorD
 * @LastEditTime: 2022-08-21 20:22:37
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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n + 1);
    vector<ll> b(n + 2);
    rep(i, 1, n - 1) cin >> a[i];
    rep(i, 1, m){
        ll x, y;
        cin >> x >> y;
        b[x] += y;
    }
    rep(i, 1, n - 1){
        if(t - a[i] <= 0){
            cout << "No" << endl;
            return;
        }
        t -= a[i];
        t += b[i + 1];
    }
    cout << "Yes" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}