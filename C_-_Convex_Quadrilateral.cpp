/*
 * @Author: JorD
 * @LastEditTime: 2022-08-27 20:42:18
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
struct Point{
    double x, y;
}a[10];
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
Point operator + (Point a, Point b){
    return {a.x + b.x, a.y + b.y};
}
double operator * (Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
Point operator * (double b,Point a){
    return {a.x * b, a.y * b};
}
int toleft (Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(temp == 0) return 0;
    else if(temp > 0) return 1;
    else return -1;
}
bool inleft (Point a, Point b, Point c, Point d){
    ll t1 = toleft(a, b, c);
    ll t2 = toleft(a, b, d);
    if(t1 <= 0 && t2 >= 0) return true;
    if(t1 >= 0 && t2 <= 0) return true;
    return false;
}
Point corsspoint(Point a, Point b, Point c, Point d){
    Point v1 = b - a;
    Point v2 = d - c;
    double t1 = v2 ^ (a - c);
    double t2 = v1 ^ v2;
    return a + ((t1/t2) * v1);
}
double dist(Point a, Point b){
    Point c = a - b;
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Solve(){
    rep(i, 0, 3) cin >> a[i].x >> a[i].y;
    rep(i, 0, 3){
        Point x = a[(i+2)%4] - a[(i+1)%4];
        Point y = a[i] - a[(i+1)%4];
        if((x^y)<0){
            cout << "No" << endl;
            return;
        }
        
    }
    cout << "Yes";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}