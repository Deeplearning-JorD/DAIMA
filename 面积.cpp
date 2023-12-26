/*
 * @Author: JorD
 * @LastEditTime: 2022-10-26 13:53:13
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
    int x, y;
}p[10];
int operator ^ (Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
int calc(Point a, Point b, Point c){
    return abs((b - a) ^ (c - a));
}
void Solve(){
    double res = 0;
    rep(i, 0, 4) cin >> p[i].x >> p[i].y;
    res += calc(p[0], p[1], p[2]);
    res += calc(p[0], p[2], p[3]);
    res += calc(p[0], p[3], p[4]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}