#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define rep(i, l, r) for (auto(i) = (l); (i) <= (r); ++(i))
const int N = 5e3+10;
struct Point{
    ll x, y;
}a[N];
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
ll operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
// to-left测试 判断点在直线的哪一边
int toleft(Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(temp > 0) return 1; // 在左边
    else if(temp == 0) return 0; //在线上
    else return -1; //在右边
}
// 判断点c是不是在 线段ab 上
bool cont(Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(!temp&&max(a.x,b.x)>=c.x&&min(a.x,b.x)<=c.x) return true;
    return false;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 0, n-1) cin >> a[i].x >> a[i].y;
    int m;
    cin >> m;
    rep(i, 1, m){
        Point c;
        cin >> c.x >> c.y;
        Point d = c;
        d.x ++;
        int res = 0;
        // 回转数 判断点是否在多边形内
        rep(j, 0, n-1){
            if(cont(a[j],a[(j+1)%n],c)){
                cout << "EDGE" << endl;
                break;
            }
            int t1 = toleft(c, d, a[j]);
            int t2 = toleft(c, d, a[(j+1)%n]);
            int t3 = toleft(a[j], a[(j+1)%n], c);
            if(t1 >= 0 && t2 < 0 && t3 < 0) res --;
            else if(t1 < 0 && t2 >= 0 && t3 > 0) res ++;
            if(j == n-1) cout << res << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}