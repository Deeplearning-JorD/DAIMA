/*
 * @Author: JorD
 * @LastEditTime: 2022-12-04 15:32:36
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
    ll n, m;
    cin >> n >> m;
    ll res = 0;
    n --; m --;
    rep(x, 0, n){
        ll l = 0, r = 1e6;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(x * x + mid * mid <= n * n + 1) l = mid;
            else r = mid - 1;
        }
        if(x * x + l * l == n * n&&(m * l % n == 0)&&(m * x % n == 0)){
            if(n == m) res ++;
            else res += 2;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}