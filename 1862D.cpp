/*
 * @Author: JorD
 * @LastEditTime: 2023-08-24 23:20:02
 * how to Get
 */
#pragma GCC optimize(2)
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
const int N = 1e6 + 10;
ll ans[N];
void Solve(){
    ll n;
    cin >> n;
    ll l = 2, r = 2e9;
    while(l < r){
        ll mid = l + r >> 1;
        if((__int128)(mid * (mid - 1) / 2) >= n) r = mid;
        else l = mid + 1;
    }
    if((__int128)(r * (r - 1) / 2) == n){
        cout << r << endl;
        return;
    }
    r --;
    n -= (__int128)(r * (r - 1) / 2);
    cout << r + n << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}