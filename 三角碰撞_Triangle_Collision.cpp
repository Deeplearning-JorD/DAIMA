/*
 * @Author: JorD
 * @LastEditTime: 2022-09-02 16:06:35
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const double sq3 = sqrt(3);
const double eps = 1e-6;
double L, k, vx, vy;
struct Point{
    double x, y;
};
ll getl(Point a, Point b){
    double c = b.y / (-sq3) + b.x;
    if(c >= 0 ){
        c += L / 2.0;
        return c / L;
    }else{
        c = fabs(c);
        c += L / 2.0;
        return c / L;
    }
}
ll getr(Point a, Point b){
    double c = b.y / sq3 + b.x;
    if(c >= 0){
        c += L / 2.0;
        return c / L;
    }else{
        c = fabs(c);
        c += L / 2.0;
        return c / L;
    }
} 
ll get(Point a, Point b){
    int w = 0;
    double now = b.y;
    if(now <= 1e-6){
        // cout << now << endl;
        now = fabs(now) + (sq3 / 2.0 * L);
        w = 1;
        // cout << (now / (sq3 / 2.0 * L) + w) << endl;
    }  
    return (ll)(now / (sq3 / 2.0 * L)) + w;
}
void Solve(){
    Point star;
    cin >> L >> star.x >> star.y >> vx >> vy >> k;
    double l = 0, r = 1e10;
    int idx = 0;
    while(r - l > 1e-8 && idx < 100000){
        idx ++;
        double mid = (l + r) / 2;
        Point last = {star.x + mid * vx, star.y + mid * vy};
        if((getl(star, last) + getr(star, last) + get(star, last) - k) < 1e-6) l = mid;
        else r = mid; 
        // cout << get(star, last) << endl;
    }   
    cout << l << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << SPO(10);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}