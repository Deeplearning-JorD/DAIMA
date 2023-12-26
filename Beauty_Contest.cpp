/*
 * @Author: JorD
 * @LastEditTime: 2022-10-27 18:06:21
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
int main(){
    int n;
    cin >> n;
    while(n --){
        ll x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    Convex();
    ll res = 0;
    int m = a.size();
    a.push_back(a[0]);
    for(int i = 0, j = 1;i < m;i ++){
        res = max(res, max(dist(a[i], a[j]), dist(a[i + 1], a[j])));
        while(((a[j] - a[i + 1]) ^ (a[i] - a[i + 1])) < ((a[j + 1] - a[i + 1]) ^ (a[i] - a[i + 1]))){
            j = (j + 1) % m;
            res = max(res, max(dist(a[i], a[j]), dist(a[i + 1], a[j])));
        }
    }
    cout << res << endl;
}