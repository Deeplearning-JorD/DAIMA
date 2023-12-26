/*
 * @Author: JorD
 * @Date: 2023-11-20 21:41:56
 * @LastEditTime: 2023-11-21 12:34:27
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
struct Point{
    int x, y;
};
int operator ^(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
Point operator -(Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
Point operator +(Point a, Point b){
    return {a.x + b.x, a.y + b.y};
}
void Solve(){
    int n; cin >> n;
    vector<pair<Point,int>> vv(n + 1), v;
    vector<int> l(n + 1), r(n + 1);
    rep(i, 1, n){
        int x, y; cin >> x >> y;
        vv[i] = {{x, y}, i};
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[n] = 1;
    l[1] = n;
    for(int i = 1;i <= n;i ++)if(vv[i].second != -1)v.push_back(vv[i]);
    reverse(v.begin(), v.end());
    int m = v.size(), res = 0;
    int ff = 0, con = 0, mi = 1e9, id = 0;
    for(int i = 0;i < m;i ++)if(v[i].first.y < v[id].first.y){
        id = i;
    }
    for(int j = 0, i = id;j < m || con;j ++, i ++){
        int l = ((i - 1) + m) % m, r = (i + 1) % m;
        int ii = i; i %= m;
        Point a = v[l].first, mid = v[i].first, b = v[r].first;
        if(mid.y < a.y && b.y > mid.y && ((mid - a) ^ (b - mid)) < 0){ 
            res ++;
        }
        if(mid.y < a.y && ((mid - a) ^ (b - mid)) < 0){
            if(b.y == mid.y){
                ff = 1;
            }
        }
        if(b.y > mid.y && ff) res ++;
        if(b.y != mid.y) ff = 0;
        if(b.y == mid.y){
            con = 1;
        }else con = 0;
        i = ii;
    }
    Point a = {0, 0}, b = {0, -2}, c = {4, 0};
    // cout << ((c-a)^(b-a));
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}