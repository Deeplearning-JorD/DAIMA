/*
 * @Author: JorD
 * @LastEditTime: 2023-07-23 23:16:33
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
    ll n, k;
    cin >> n >> k;
    ll mx = 0, mi = n;
    ll l0 = 1, r0 = 1, l1 = 0, r1 = 1;
    rep(i, 3, k){
        ll nowl = l1 + l0, nowr = r1 + r0;
        if(i & 1){
            mi = min(mi, n * nowl / nowr);
        }else{
            mx = max(mx, (n * nowl + nowr - 1) / nowr);
        }
        l0 = l1;
        r0 = r1;
        l1 = nowl;
        r1 = nowr;
        if(mi < mx) break;
    }
    cout << max(0ll, mi - mx + 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}