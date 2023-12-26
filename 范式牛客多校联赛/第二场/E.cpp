/*
 * @Author: JorD
 * @LastEditTime: 2023-07-21 12:41:33
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
    ll x; cin >> x;
    ll sum = 1;
    ll inf = 1e18;
    for(ll i = 0;i <= 18;i ++){
        if((inf + sum - 1) / sum < x) break;
        ll now = x * sum;
        ll l = 0, r = 1e9;
        while(l < r){
            ll mid = l + r >> 1;
            if(mid * mid >= now) r = mid;
            else l = mid + 1;
        }
        if(x == r * r / sum){
            cout << r << endl;
            return;
        }
        sum *= 10;
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}