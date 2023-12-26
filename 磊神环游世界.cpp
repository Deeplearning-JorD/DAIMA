/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 18:32:23
 */
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double, double> PDD;
const int maxn = 510;
const double eps = 1e-8;
PDD operator - (PDD a, PDD b){
    return {a.x - b.x, a.y - b.y};
}
typedef struct node{
    PDD st, ed;
}Line;
Line lines[maxn];
int n, m, cnt;
PDD pg[maxn], ans[maxn];
int q[maxn];
int sign(double x){
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}
int dcmp(double x, double y){
    if(fabs(x - y) < eps) return 0;
    if(x < y) return -1;
    return 1;
}
double cross(PDD a, PDD b){
    return a.x * b.y - a.y * b.x;
}
double area(PDD a, PDD b, PDD c){
    return cross(b - a, c - a);
}
double get_angle(Line a){
    return atan2(a.ed.y - a.st.y, a.ed.x - a.st.x);
}
bool cmp(const Line &a, const Line &b){
    double thetaA = get_angle(a), thetaB = get_angle(b);
    if(!sign(thetaA - thetaB)) 
    return area(a.st, a.ed, b.ed) < 0;
    return thetaA < thetaB;
}
PDD getPoint(PDD p, PDD v, PDD q, PDD w){
    auto u = p - q;
    double t = cross(w, u) / cross(v, w);
    return {p.x + t * v.x, p.y + t * v.y};
}
PDD getPoint(Line a, Line b){
    return getPoint(a.st, a.ed - a.st, b.st, b.ed - b.st);
}
bool on_right(Line a, Line b, Line c){
    auto o = getPoint(b, c);
    return sign(area(a.st, a.ed, o)) <= 0;
}
double get(PDD now){
    double dist = 1e9;
    for(int i = 1;i < n;i ++){
        if(now.x >= pg[i - 1].x&&now.x <= pg[i].x){
            // if(pg[i].x == pg[i - 1].x){
            //     continue;
            // }
            cout << "??????\n";
            cout << now.x << ' ' << now.y << ' ' << endl;
            cout << pg[i - 1].x << ' ' << pg[i - 1].y << endl;
            cout << pg[i].x << ' ' << pg[i].y << endl;
            double k = (pg[i].y - pg[i - 1].y) / (pg[i].x - pg[i - 1].x);
            double b = pg[i - 1].y - k * pg[i - 1].x;
            dist = min(dist, now.y - k * now.x - b);
            cout <<dist << endl;
        }
    }
    return dist;
}
double gett(PDD now, int k){
    double dist = 1e9;
    for(int i = 1;i < k;i ++){
        if(now.x >= ans[i - 1].x&&now.x <= ans[i].x){
            // if(ans[i].x == ans[i - 1].x){
            //     continue;
            // }
            double k = (ans[i].y - ans[i - 1].y) / (ans[i].x - ans[i - 1].x);
            double b = ans[i - 1].y - k * ans[i - 1].x;
            dist = min(dist, k * now.x + b - now.y);
        }
    }
    // cout << dist << endl;
    return dist;
}

void half_plane_intersection(){
    sort(lines, lines + cnt, cmp);
    int hh = 0, tt = -1;
    for(int i = 0; i < cnt; i ++){
        if(i && !dcmp(get_angle(lines[i]), get_angle(lines[i - 1]))) continue;
        while(hh + 1 <= tt && on_right(lines[i], lines[q[tt - 1]], lines[q[tt]])) tt --;
        while(hh + 1 <= tt && on_right(lines[i], lines[q[hh]], lines[q[hh + 1]])) hh ++;
        q[++ tt] = i;
    }
    while(hh + 1 <= tt && on_right(lines[q[hh]], lines[q[tt - 1]], lines[q[tt]])) tt --;
    while(hh + 1 <= tt && on_right(lines[q[tt]], lines[q[hh]], lines[q[hh + 1]])) hh ++;
    q[++ tt] = q[hh];
    int k = 0;
    for(int i = hh; i < tt; i ++){
        ans[k ++] = getPoint(lines[q[i]], lines[q[i + 1]]);
    }
    double res = 1e18;
    // for(int i = 0; i < k; i ++){
    //     res = min(res, get(ans[i]));
    // }
    for(int i = 0; i < n; i ++){
        res = min(res, gett(pg[i], k));
    }
    printf("%.8lf",res);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> pg[i].x;
    for(int i = 0; i < n; i ++) cin >> pg[i].y;
    for(int i = 0; i < n - 1; i ++) lines[cnt ++] = {pg[i], pg[i + 1]};
    half_plane_intersection();
    return 0;
}