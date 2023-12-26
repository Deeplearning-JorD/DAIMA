/*
 * @Author: JorD
 * @LastEditTime: 2023-07-08 19:21:06
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
set<ll> s;
void Solve(){
    ll x; cin >> x;
    if(s.count(x)) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 2, 1e6){
        ll sum = 1;
        ll now = 1;
        int idx = 1;
        while(sum < 1e7 && idx < 3){
            now *= i;
            sum += now;
            idx ++;
        }
        while(sum < 1e7 && idx >= 3){
            s.insert(sum);
            now *= i;
            sum += now;
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}