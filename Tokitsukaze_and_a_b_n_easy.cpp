/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 13:23:18
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
    ll n;
    cin >> n;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(n < l1 || n < l2){
        cout << 0 << endl;
        return;
    }
    r1 = min(r1, n);
    l2 = max(l2, n - r1);
    r2 = min(r2, n - l1);
    cout << max(0ll, r2 - l2 + 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}