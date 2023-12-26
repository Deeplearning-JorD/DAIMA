/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 16:55:46
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
// #define endl '\n'
#define double long double
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
void Solve(){
    int n; cin >> n;
    cout << "? " << 0 << ' ' << 1 << ' ' << 0 << endl;cout.flush();
    vector<double> X(n), Y(n);
    rep(i, 0, n - 1){
        double x, y; cin >> x >> y;
        X[i] = x;
    }
    cout << "? " << 1 << ' ' << 0 << ' ' << 0 << endl;cout.flush();
    rep(i, 0, n - 1){
        double x, y; cin >> x >> y;
        Y[i] = y;
    }
    cout << "? " << 0.1 << ' ' << 20.2 << ' ' << 0 << endl;
    cout.flush();
    vector<Point> res;
    int cnt= 0;
    vector<Point> ls(n);
    for(auto &[x, y]:ls) cin >> x >> y;
    for(auto [x, y]:ls){
        double resx, resy, last = 1000;
        double b = y - 202 * x;
        for(auto sx:X){
            for(auto sy:Y){
                if(fabs(sy - (202 * sx + b)) < last){
                    resx = sx;
                    resy = sy;
                    last = fabs(sy - (202 * sx + b));
                }
            }
        }
        res.push_back({resx, resy});
    }
    cout << "! ";
    for(auto [x, y]:res) 
    cout << x << ' ' << y << ' ';
    cout << endl;cout.flush();
    return; 
}
int main(){
    cout << SPO(5);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}