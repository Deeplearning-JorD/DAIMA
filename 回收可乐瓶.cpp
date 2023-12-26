/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 21:07:09
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
double get(int x,int y,int sx,int sy){
    return sqrt((x-sx)*(x-sx)+(y-sy)*(y-sy));
}
void Solve(){
    int ax, bx, ay, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int t; cin >> t;
    vector<pair<int,int>> a(t+1);
    rep(i,1,t) cin >> a[i].first >> a[i].second;
    int x = a[1].first, y = a[1].second;
    double res;
    rep(i,1,t) res += 2 * get(tx, ty, a[i].first, a[i].second);
    double now = res - 2 * get(tx, ty, x, y) + get(ax,ay,x,y) + get(tx,ty,x,y);
    double last = now;
    rep(i,2,t){
        x = a[i].first , y = a[i].second;
        now = min(now, last + get(bx,by,x,y) - get(x,y,tx,ty));
    }
    double ans = now;
    x = a[1].first, y = a[1].second;
    now = res - 2 * get(tx, ty, x, y) + get(bx,by,x,y) + get(tx,ty,x,y);
    last = now;
    rep(i,2,t){
        x = a[i].first , y = a[i].second;
        now = min(now, last  + get(ax,ay,x,y) - get(x,y,tx,ty));
    }
    cout << SPO(2) << min(ans, now);
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}