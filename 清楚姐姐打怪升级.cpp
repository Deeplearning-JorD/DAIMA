/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 13:47:32
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
const int N = 1e5 + 10;
ll hp[N], v[N];
void Solve(){
    ll n, t, a; cin >> n >> t >> a;
    rep(i, 1, n){
        cin >> hp[i] >> v[i];
        if(a < hp[i]&&t*v[i]>=a){
            cout << -1 << endl;
            return;
        }
    }
    ll res = 0;
    rep(i, 1, n){
        if(a >= hp[i]){
            res ++;
            continue;
        }
        ll use = a - t * v[i];
        ll up = hp[i] - a;
        ll l = 1, r = 1e6;
        while(l < r){
            ll mid = l + r >> 1;
            if(mid * use >= up) r = mid;
            else l = mid + 1;
        }
        res += r + 1;
    }
    res = (res - 1) * t + 1;
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}