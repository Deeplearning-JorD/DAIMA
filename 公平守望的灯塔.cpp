/*
 * @Author: JorD
 * @LastEditTime: 2023-01-20 13:45:58
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
    ll x, y, sx, sy;
    cin >> x >> y >> sx >> sy;
    ll nx = sx - x, ny = sy - y;
    ll X = ny, Y = - nx;
    ll l = x + X, r = y + Y;
    if((sx + l) % 2 == 0 && (sy + r) % 2 == 0){
        cout << (sx + l) / 2 << ' ' << (sy + r) / 2 << endl;
        return;
    }
    X = -ny;Y = nx;
    l = x + X, r = y + Y;
    if((sx + l) % 2 == 0 && (sy + r) % 2 == 0){
        cout << (sx + l) / 2 << ' ' << (sy + r) / 2 << endl;
        return;
    }
    cout << "No Answer!";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}