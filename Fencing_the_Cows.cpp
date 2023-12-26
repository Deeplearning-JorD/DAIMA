/*
 * @Author: JorD
 * @LastEditTime: 2022-10-26 17:12:06
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
const int N = 2e5 + 10;
struct Point{
    double x, y;
};
vector<Point> p;
double operator ^ (Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y}; 
}
vector<Point> a, b;
bool check(Point x, Point y, Point z){
    return ((y - x) ^ (z - y)) <= 0.0;
}
double dist(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(){
    int n;
    cin >> n;
    rep(i, 1, n){
        double x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end(), [&](Point a, Point b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    int idx = 0;
    for(auto x:p){
        while(a.size() > 1&&check(*prev(a.end() - 1), a.back(), x)) a.pop_back();
        a.push_back(x);
    }
    p.pop_back();
    reverse(p.begin(), p.end());
    idx = a.size();
    for(auto x:p){
        while(a.size() > idx&&check(*prev(a.end() - 1), a.back(), x)) a.pop_back();
        a.push_back(x);
    }
    double res = 0;
    rep(i, 0, siz(a) - 1)
        res += dist(a[i], a[(i + 1)%(siz(a))]);
    printf("%.10lf", res);
}