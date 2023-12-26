/*
 * @Author: JorD
 * @LastEditTime: 2023-10-09 23:09:55
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
ll px, py, ax, ay, bx, by;
ll dist(ll x, ll y, ll sx, ll sy){
    return (x - sx) * (x - sx) + (y - sy) * (y - sy);
}
void Solve(){
    cin >> px >> py >> ax >> ay >> bx >> by;
    double res = 1e18;
    res = min(res, sqrt(max(dist(0, 0, ax, ay), dist(px, py, ax, ay))));
    res = min(res, sqrt(max(dist(0, 0, bx, by), dist(px, py, bx, by))));
    double mi = sqrt(dist(ax, ay, bx, by)) / 2;
    bool A = 0, B = 0;
    if(sqrt(dist(0, 0, ax, ay)) <= mi) A = 1;
    if(sqrt(dist(px, py, ax, ay)) <= mi) B = 1;
    if(sqrt(dist(0, 0, bx, by)) <= mi) A = 1;
    if(sqrt(dist(px, py, bx, by)) <= mi) B = 1;
    if(A && B){
        cout << SPO(10) << min(res, mi) << endl;
        return;
    }
    double c1, c2;
    c1 = max(sqrt(dist(0, 0, ax, ay)), sqrt(dist(px, py, bx, by)));
    c2 = max(sqrt(dist(0, 0, bx, by)), sqrt(dist(px, py, ax, ay)));
    res = min({res, c1, c2});
    cout << SPO(10) << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}