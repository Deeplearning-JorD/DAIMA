/*
 * @Author: JorD
 * @LastEditTime: 2022-09-06 20:12:00
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
const double eps = 1e-8;
struct Point{
    double x, y;
};
int sign(double x) {
    return x < -eps ? -1 : x > eps ? 1 : 0;
}
Point operator - (Point x, Point y){
    return {x.x - y.x, x.y - y.y};
}
Point operator + (Point x, Point y){
    return {x.x + y.x, x.y + y.y};
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
double operator * (Point x, Point y){
    return x.x * y.x + x.y * y.y;
}
double dist(Point x, Point y){
    return sqrt((x.x-y.x)*(x.x-y.x) + (y.y-x.y)*(y.y-x.y));
};
void Solve(){
    int n;
    cin >> n;
    vector<Point> p(n + 1);
    rep(i, 1, n) cin >> p[i].x >> p[i].y;
    auto left = [&](Point now, double s, double c) -> Point{
        Point res;
        double x = now.x, y = now.y;
        res.x = x*c - y*s;
        res.y = x*s + y*c;
        return res;
    };
    auto right = [&](Point now, double s, double c) -> Point{
        Point res;
        double x = now.x, y = now.y;
        res.x = x*c + y*s;
        res.y = -x*s + y*c;
        return res;
    };
    auto onleft = [&](Point a, Point b){
        return sign(a^b);
    };
    auto ok = [&](int i, int j, Point last, double d,Point w){
        set<double> q;
        double len = sqrt(last*last);
        double maxn = - 1e9, minn = 1e9;
        rep(k, 1, n){
            if(k == i||k == j) continue;
            if(onleft(p[k]-p[i],last)*onleft(p[k]-p[j],last) <= 0) continue;
            double now = ((p[k] - w) * last) / len;
            maxn = max(maxn, now);
            minn = min(minn, now);
        }
        if(maxn == -1e9 && minn == 1e9) return true;
        return maxn - minn < d + 1e-9;
    };
    auto check = [&](double d) -> bool{
        int js = 0;
        rep(i, 1, n){
            rep(j, i + 1, n){
                double dd = dist(p[i], p[j]);
                if(dd < d - 1e-8) continue;
                double s = d / dd;
                double c = sqrt(1 - s*s);
                if(dd < d + 1e-8) s = 1,c = 0;
                js++;
                Point now = p[j] - p[i],last;
                last = left(now, s, c);
                if(ok(i, j, last, d,p[i])) return true;
                last = right(now, s, c);
                if(ok(i, j, last, d,p[i])) return true;
            }
        }
        return !js;
    };
    int idx = 0;
    double l = 0, r = 20000;
    while(r - l > 1e-19){
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
        idx ++;
    }
    cout << SPO(10) << l << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}