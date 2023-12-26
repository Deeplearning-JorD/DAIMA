#pragma GCC optimize(2)
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
const int N = 1e4 + 10;
double res[N];
struct Point{
    ll x, y;
};
Point u[N], v[N], ls[N];
double operator ^ (Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
ll operator *(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y}; 
}
double dist(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double dist(ll x, ll y, ll sx, ll sy){
    return sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy));
}
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n){
        cin >> u[i].x >> u[i].y;
    }
    rep(i, 1, m){
        cin >> v[i].x >> v[i].y;
    }
    rep(i, 1, n){
        res[i] = dist(u[1],v[i]);
    }
    for(int i = 2;i <= n;i ++){
        if(u[i].x == u[i - 1].x && u[i].y == u[i - 1].y) continue;
        for(int j = 1;j <= m;j ++){
            double d = ((v[j]-u[i])^(u[i-1]-u[i]))/dist(u[i], u[i-1]);  
            d = fabs(d);
            if((((v[j]-u[i])*(u[i-1]-u[i]))<0)||(((v[j]-u[i-1])*(u[i]-u[i-1]))<0)){
                double a = dist(u[i-1], v[j]);
                double b = dist(u[i], v[j]);    
                d = min(a, b);
            }
            if(i == 2) res[j] = d;
            else res[j] = min(res[j], d);
        }
    }
    rep(i, 1, m) cout << SPO(4) << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}