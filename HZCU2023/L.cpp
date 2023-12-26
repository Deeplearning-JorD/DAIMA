/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 19:00:21
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
const double pi = acos(-1);
struct Point{
    ll x, y;
    ll w;
};
ll operator ^ (Point x, Point y){
    return x.x * y.y - x.y * y.x;
}
ll operator * (Point x, Point y){
    return x.x * y.x + x.y * y.y;
}
ll dist(Point x){
    return x.x * x.x + x.y * x.y;
}
Point z0 = {1, 1, 0}, z1 = {1, 0, 0};
bool check(Point a, Point b){
    ll L1 = (a ^ b) * (a ^ b);
    ll R1 = dist(a) * dist(b);
    ll now = (a * b) * (a * b);
    if((a * b) < 0 || (a ^ b) < 0) return false;
    a = z0, b = z1;
    ll L2 = (a ^ b) * (a ^ b);
    ll R2 = dist(a) * dist(b);
    ll l = L1 * R2, r = L2 * R1;
    long double l1 = 1.0 * L1 / R1, r1 = 1.0 * L2 / R2;
    if(l > r) return false;
    return true; 
}
void Solve(){
    int n;
    cin >> n;
    vector<Point> p(n + 1);
    rep(i, 1, n){
        cin >> p[i].x >> p[i].y;
        if(p[i].y == 0){
            if(p[i].x == 0) p[i].w = 1;
            else if(p[i].x >= 0) p[i].w = 2;
        }else if(p[i].y < 0) p[i].w = 2;
    }
    sort(p.begin() + 1,p.end(),[](Point a, Point b){
        if(a.w != b.w) return a.w > b.w;
        return (a ^ b) > 0;
    });
    int i = 1, j = 1;
    int T = 10 * n;
    auto calc = [&](int x, int y){
        if(x <= y) return y - x + 1;
        return n - x + 1 + y;
    };
    int res = 0;
    while(T --){
        if(i > n) i = 1;
        if(j > n) j = 1;
        if(check(p[i], p[j])){
            res = max(calc(i, j), res);
        }else{
            i ++;
            continue;
        }
        j ++;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}