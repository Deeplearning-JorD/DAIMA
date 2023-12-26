/*
 * @Author: JorD
 * @LastEditTime: 2022-09-06 20:52:39
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
const double pi = acos(-1);
struct Point{
    ll x, y;
    ll w;
};
ll operator ^ (Point x, Point y){
    return x.x * y.y - x.y * y.x;
}
void Solve(){
    int n;
    cin >> n;
    vector<Point> p(n + 1);
    rep(i, 1, n){
        cin >> p[i].x >> p[i].y;
        //把正半轴和下面当成一部分，00当成一部分，然后剩下的当成一部分。
        if(p[i].y == 0){
            if(p[i].x == 0) p[i].w = 1;
            else if(p[i].x >= 0) p[i].w = 2;
        }else if(p[i].y < 0) p[i].w = 2;
    }
    sort(p.begin() + 1,p.end(),[](Point a, Point b){
        if(a.w != b.w) return a.w > b.w;
        return (a ^ b) > 0;
    });
    rep(i, 1, n) cout << p[i].x << ' ' << p[i].y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}