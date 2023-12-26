/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 12:58:14
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
const double l = 1, r = 2;
void Solve(){
    double n; cin >> n;
    if(n == 2){
        cout << SPO(9) << l << ' ' << l << endl;
        return;
    }
    double u = 2.0-2.0/n;
    cout << SPO(9) << u << ' ' << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t --)
    Solve();
    return 0;
}