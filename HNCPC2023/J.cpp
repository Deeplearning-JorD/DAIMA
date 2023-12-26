/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 21:19:22
 */
/*
 * @Author: JorD
 * @LastEditTime: 2023-05-17 01:00:19
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define double long double
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
const double Pi = acos(-1);
double dist(double x, double y, double sx, double sy){
    return sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy));
}
void Solve(){
    double px, py; cin >> px >> py;
    double sx, sy; cin >> sx >> sy;
    double ex, ey; cin >> ex >> ey;
    double v, t; cin >> v >> t;
    double r = v * t;
    double mx = (ex + sx) / 2, my = (ey + sy) / 2;
    double res = Pi * r * r;
    double ml = dist(mx, my, px, py);
    double len = dist(sx, sy, px, py);
    if(len <= r){
        cout << SPO(10) << res << endl;
        return;
    }
    res += (r*sqrt(len*len-r*r)) - (acos(r/len)*r*r);
    if(ml <= r){
        res += (r*sqrt(len*len-r*r)) - (acos(r/len)*r*r);
    }else res += (ml*sqrt(len*len-ml*ml)) - (acos(ml/len)*r*r); 
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