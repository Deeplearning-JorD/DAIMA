/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 13:12:03
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
struct Point{
    double x, y;
};
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
double operator * (Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
int toleft(Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(temp > 0) return 1; // 在左边
    else if(temp == 0) return 0; //在线上
    else return -1; //在右边
}
double dist(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Solve(){
    vector<Point> a(6);
    for(auto &[x, y]:a) cin >> x >> y;
    if(dist(a[1], a[0]) == dist(a[1], a[2])){
        cout << "NO\n";
        return;
    }
    if(dist(a[1], a[0]) == dist(a[3], a[4])){
        if(toleft(a[1], a[0], a[2]) == toleft(a[4], a[3], a[5])){
            cout << "NO\n";
        }else cout << "YES\n";
    }else{
        if(toleft(a[1], a[0], a[2]) == toleft(a[4], a[5], a[3])){
            cout << "NO\n";
        }else cout << "YES\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}