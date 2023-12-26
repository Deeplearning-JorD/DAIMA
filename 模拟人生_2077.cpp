/*
 * @Author: JorD
 * @LastEditTime: 2022-10-27 23:40:26
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
ll dist(Point a, Point b){
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Convex(){
    sort(p.begin(), p.end(), [&](Point a, Point b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    int idx = 0;
    for(auto x:p){
        while(a.size() > 1&&check(*prev(a.end() - 1), a.back(), x)) a.pop_back();
        a.push_back(x);
    }
    p.pop_back(); reverse(p.begin(), p.end());
    idx = a.size();
    for(auto x:p){
        while(a.size() > idx&&check(*prev(a.end() - 1), a.back(), x)) a.pop_back();
        a.push_back(x);
    }
}
void Solve(){
    int n;
    cin >> n;
    vector<int> w(n + 1);
    rep(i, 1, n){  
        cin >> w[i];
    }
    rep(i, 1, n){
        ll y;
        cin >> y;
        p.push_back({w[i], y});
    }
    Convex();
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}