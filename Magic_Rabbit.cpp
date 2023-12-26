/*
 * @Author: JorD
 * @LastEditTime: 2022-08-18 11:08:19
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
}a[3];
Point operator - (Point a, Point b){
    return {a.x-b.x, a.y - b.y};
}
ll operator ^ (Point a, Point b){ 
    return a.x*b.y - a.y*b.x;
}
ll operator * (Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
bool operator == (Point a, Point b){
    return a.x == b.x && a.y == b.y;
}
int toleft(Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(temp == 0) return 0;
    else if(temp > 0) return 1;
    else return -1;
}
bool cont(Point a, Point b, Point c){
    ll t1 = toleft(a, b, c);
    ll t2 = (c-a) * (c-b); 
    return !t1 && t2 <= 0;
}
void Solve(){
    Point u;
    cin >> u.x >> u.y;
    int l = 0, r = 0;
    bool st = false;
    rep(i, 0, 2){
        Point t1 = a[i], t2 = a[(i+1)%3];
        if(cont(t1, t2, u)){
            cout << "YES" << endl;
            return;
        }
        int now = toleft(t1, t2, u);
        if(now == 1) l ++;
        if(now == -1) r ++;
    }
    if(l == 3||r == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 0, 2)
        cin >> a[i].x >> a[i].y;
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}