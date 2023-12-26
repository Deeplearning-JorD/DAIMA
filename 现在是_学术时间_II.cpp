/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 16:06:38
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
    double x, y, xp, yp;
    cin >> x >> y >> xp >> yp;
    double res = 0;
    if(xp <= x && yp <= y){
        res = max(res, 1.0 * (y - yp) * xp / (x * y));
        res = max(res, 1.0 * (yp * xp) / (x * y));
        res = max(res, 1.0 * (y - yp) * (x - xp) / (x * y));
        res = max(res, 1.0 * (x - xp) * yp / (x * y));
    }else if(x <= xp && y <= yp){
        res = x * y / (xp * yp);
    }else if(xp <= x){
        res = max(xp * y / (xp * yp + x * y - xp * y),(x - xp) * y / ((x - xp) * yp + x * y - (x - xp) * y));
    }else{
        res = max((x * (y - yp)) / (xp * (y - yp) + x * y - x * (y - yp)),(x * yp) / (xp * yp + x * y - x * yp));
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << SPO(9);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}