/*
 * @Author: JorD
 * @LastEditTime: 2022-11-12 01:15:55
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
    ll x, y;
};
Point operator -(Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
ll operator ^ (Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
ll operator *(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}
bool operator == (Point a, Point b){
    return a.x == b.x && b.y == a.y;
}
bool F(Point a, Point b, Point c){
    Point A = b - a;
    Point B = c - a;
    return (A ^ B) == 0;
}
void Solve(){
    int n;
    cin >> n;
    vector<Point> p(n);
    for(auto &[x, y]:p) cin >> x >> y;
    if(n < 5){
        cout << "NO\n";
        return;
    }
    vector<Point> res;
    rep(i,0,3) res.push_back(p[i]);
    auto check = [&](Point u){
        for(int i = 0;i < 4;i ++){
            for(int j =i + 1;j < 4;j ++){
                if(F(p[i],p[j],u)) continue;
                res.push_back(u);
                return true;
            }
        }
        return false;
    };
    rep(i, 4, n - 1){
        if(check(p[i])) break;
    }
    if(res.size() < 5){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<Point> C;
    auto jiji = [&](Point now){
        auto [sx, sy] = now;
        bool ST = true;
        for(auto u:C){
            for(auto U:C){
                if(u == U) continue;
                if(F(now, u, U)&&(u - now) * (U - now) > 0) ST = false;
            }
        }
        return ST;
    };
    for(int i = 0;i < 5;i ++){
        C.clear();
        for(auto x:res){
            if(x == res[i]) continue;
            C.push_back(x);
        }
        if(jiji(res[i])){
            cout << res[i].x << ' ' << res[i].y << '\n';
            for(auto [x, y]:C){
                cout << x << ' ' << y << '\n';
            }
            break;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}