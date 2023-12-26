/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 01:20:04
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
    ll n, m;
    cin >> n >> m;
    ll l = 1, r = 1e9;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(mid * mid <= m) l = mid;
        else r = mid - 1;
    }
    ll Lx, Ly, Rx, Ry = 0; 
    Rx = l;
    rep(i, 0, 2){
        if(l * l + (i * l) <= m) Ry ++;
    }
    l = 1, r = 1e9;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(mid * mid <= n) l = mid;
        else r = mid - 1;
    }
    int idx = 3;
    Lx = l;
    rep(i, 0, 2){
        if(l * l + (i * l) < n) idx --;
    }
    cout << Ry + idx + (Rx - Lx - 1) * 3 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    // rep(i, 1, 100){
    //     int x = sqrt(i);
    //     if(i % x == 0) cout << i << ' ' << x  << '\n';
    // }
    return 0;
}