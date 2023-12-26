/*
 * @Author: JorD
 * @LastEditTime: 2022-08-17 20:04:31
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
const int N = 30;
const double eps = 1e-2;
struct Point{
    double x, y;
}a[N];
bool check(double a, double b){
    return fabs(a-b) <= eps;
}
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
int toleft(Point a, Point b, Point c){
    double temp = (b-a)^(c-a);
    if(check(temp, 0)) return 0;
    else if(temp > 0) return 1;
    else return -1;
}
double getlen(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
void Solve(){
    double maxn = 0;
    int n = 20;
    string res;
    rep(i, 0, n-1){
        cin >> a[i].x >> a[i].y;
    }
    rep(i, 0, n-1){
        Point t1 = a[i], t2  = a[(i+1)%n], t3 = a[(i+2)%n], t4 = a[(i+3)%n];
        if(getlen(t2, t3) > maxn){
            maxn = getlen(t2, t3);
            if(getlen(t1, t2) > getlen(t3, t4)){
                if(toleft(t1, t2, t3) > 0) res = "left";
                else res = "right";
            }else{
                if(toleft(t2, t3, t4) < 0) res = "left";
                else res = "right";
            }
        }
    }
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}