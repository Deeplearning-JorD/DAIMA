/*
 * @Author: JorD
 * @LastEditTime: 2022-10-17 13:10:45
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll L = 2, R = 2;
    // for(ll i = 2;;i ++){
    //     if(i * a * b <= c * d){
    //         R = i;
    //     }else break;
    // } 
    if(ceil(a * b / c) > d){
        cout << -1 << ' ' << -1 << endl;
        return;
    }
    for(ll x = c;x > a; x --){
        // if((a * b) % x) continue;
        double k = (double)a * b * 1.0 / x;
        if(ceil(2 * k) > d) break;
        cout << x << ' ' << ceil(2 * k) << endl;
        cout << (ll)(x * ceil(2 * k)) % (a * b) << endl;
        // return;
    }
    // cout << -1 << ' ' << -1 << endl;
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