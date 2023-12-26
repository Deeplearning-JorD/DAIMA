/*
 * @Author: JorD
 * @LastEditTime: 2023-02-01 14:41:09
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
    ll x, y, k, n, T;
    cin >> x >> y >> k >> n >> T;
    ll mai = 0, money = 0;
    rep(i, 1, n){
        ll now = x + y * (mai / k);
        money += (n - i + 1) * now;
        mai += (n - i + 1);
        if(money >= T){
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}