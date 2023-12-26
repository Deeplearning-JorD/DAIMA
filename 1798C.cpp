/*
 * @Author: JorD
 * @LastEditTime: 2023-03-27 20:22:34
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
ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}
void Solve(){
    int n;
    cin >> n;
    ll res = 0, ji = 1;
    int ans = 1;
    ll mx = 0;
    rep(i, 1, n){
        ll a, b;
        cin >> a >> b;
        ll now = a * b;
        res = __gcd(res, now);
        ji = lcm(ji, b);
        if(res % ji){
            ans ++;
            res = now;
            ji = b;
            continue;
        }
    }
    cout << ans << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}