/*
 * @Author: JorD&&TCchen
 * @LastEditTime: 2022-10-05 21:26:59
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define double long double
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
const int N = 210;
const double eps = 1e-8;
bool vis[N][N];
double dist[N];
double w[N][N];
double zero = 0;
struct Point{
    double x, y;
};
int sgn(double x){
    if(fabs(x) < eps) return 0;
    if(x < 0)  return - 1;
    else return 1;
}
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
double operator * (Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
struct Culb{
    Point p1,p2,p3,p4;
};
int n, m;
double R;
double sx, sy, ex, ey;
vector<Culb> F;
vector<Point> yuan;
vector<Point> all;
int toleft(Point a, Point b, Point c){
    ll temp = (b-a) ^ (c-a);
    if(temp > 0) return 1; // 在左边
    else if(temp == 0) return 0; //在线上
    else return -1; //在右边
}
double get(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool inleft (Point a, Point b, Point c, Point d){
    ll t1 = toleft(a, b, c);
    ll t2 = toleft(a, b, d);
    if(t1 < 0 && t2 > 0) return true;
    if(t1 > 0 && t2 < 0) return true;
    return false;
}
bool xdxiangjiao(Point a, Point b, Point c, Point d){
    if(!inleft(a, b, c, d)) return false;
    ll t1 = toleft(a, c, d), t2 = toleft(b, c, d);
    ll t3 = toleft(b, d, c), t4 = toleft(a, d, c);
    if(t1 < 0 && t2 > 0){
        if(t3 < 0&& t4 > 0) return true;
        if(t3 > 0&& t4 < 0) return true;
    }
    if(t1 > 0 && t2 < 0){
        if(t3 < 0&& t4 > 0) return true;
        if(t3 > 0&& t4 < 0) return true;
    }
    return false;
}
bool check(Culb a, Point b, Point c){
    return xdxiangjiao(a.p1, a.p4, b, c)||xdxiangjiao(a.p2, a.p3, b, c);
}
bool jiji(Culb a, double x){
    return (a.p1.x <= x)&&(x <= a.p2.x);
}
bool beibei(Culb a, double y){
    return (a.p1.y >= y)&&(y >= a.p3.y);
}
void judge(int be, int ed){
    Point a = all[be], b = all[ed];
    if(be > (n << 2)&&be != n * 4 + m + 1){
        if((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y) <= R * R){
            vis[be][ed] = true;
            w[be][ed] = 0;
            return;
        }
        vis[be][ed] = true;
        double k = R / get(a, b);
        double x = a.x + (b.x - a.x) * k;
        double y = a.y + (b.y - a.y) * k;
        for(auto u:F){
            if(u.p1.x < x && u.p2.x > x && u.p1.y > y && u.p3.y < y){
                vis[be][ed] = false;
                break;
            }
        }
        if(vis[be][ed]){
            for(auto u:F){
                if(check(u, {x, y}, b)){
                    vis[be][ed] = false;
                    break;   
                }
            }
            if(vis[be][ed]){
                w[be][ed] = get({x, y}, b);
            }
        }
        if(!vis[be][ed]){
            w[be][ed] = 1e18;
            for(auto u:F){
                double ry = u.p1.y, ly = u.p3.y;
                double dy, dx;
                double lx = u.p1.x, rx = u.p2.x;
                // cout << lx << " ??  " << rx << endl;
                vector<Point> now;
                if(ry <= a.y + R&&ly >= a.y - R){
                    dy = fabs(a.y - ry);
                    dx = sqrt(R * R - dy * dy);
                    double rlx = a.x - dx, rrx = a.x + dx;
                    dy = fabs(a.y - ly);
                    dx = sqrt(R * R - dy * dy);
                    double llx = a.x - dx, lrx = a.x + dx;
                    if(jiji(u, rlx))
                    now.push_back({rlx, ry});
                    if(jiji(u, rrx))
                    now.push_back({rrx, ry});
                    if(jiji(u, llx))
                    now.push_back({llx, ly});
                    if(jiji(u, lrx))
                    now.push_back({lrx, ly});
                }else if(ry <= a.y + R){
                    dy = fabs(a.y - ry);
                    dx = sqrt(R * R - dy * dy);
                    double rlx = a.x - dx, rrx = a.x + dx;
                    if(jiji(u, rlx))
                    now.push_back({rlx, ry});
                    if(jiji(u, rrx))
                    now.push_back({rrx, ry});
                }else if(ly >= a.y - R){
                    dy = fabs(a.y - ly);
                    dx = sqrt(R * R - dy * dy);
                    double llx = a.x - dx, lrx = a.x + dx;
                    if(jiji(u, llx))
                    now.push_back({llx, ly});
                    if(jiji(u, lrx))
                    now.push_back({lrx, ly});
                }
                if(rx <= a.x + R&&lx >= a.x - R){ 
                    dx = fabs(a.x - rx);
                    dy = sqrt(R * R - dx * dx);
                    double rly = a.y - dy, rry = a.y + dy;
                    dx = fabs(a.x - lx);
                    dy = sqrt(R * R - dx * dx);
                    double lly = a.y - dy, lry = a.y + dy;
                    if(beibei(u, rly))
                    now.push_back({rx, rly});
                    if(beibei(u, rry))
                    now.push_back({rx, rry});
                    if(beibei(u, lly))
                    now.push_back({lx, lly});
                    if(beibei(u, lry))
                    now.push_back({lx, lry});
                }else if(rx <= a.x + R){
                    dx = fabs(a.x - rx);
                    // cout << "???\n";
                    // cout << a.x << ' ' << rx << endl;
                    dy = sqrt(R * R - dx * dx);
                    double rly = a.y - dy, rry = a.y + dy;
                    // cout << rx << ' ' << rly << endl;
                    
                    if(beibei(u, rly))
                    now.push_back({rx, rly});
                    if(beibei(u, rry))
                    now.push_back({rx, rry});
                }else if(lx >= a.x - R){
                    dx = fabs(a.x - lx);
                    dy = sqrt(R * R - dx * dx);
                    double lly = a.y - dy, lry = a.y + dy;
                    if(beibei(u, lly))
                    now.push_back({lx, lly});
                    if(beibei(u, lry))
                    now.push_back({lx, lry});
                }
                for(auto o:now){
                    // cout << o.x << ' ' << o.y << ' ' << be << "- >" << ed << endl;
                    vis[be][ed] = true;
                    for(auto u:F){
                        if(check(u, o, b)){
                            vis[be][ed] = false;
                            break;   
                        }
                    }
                    if(vis[be][ed]){
                        w[be][ed] = min(w[be][ed], get(o, b));
                    }
                }
            }
            vis[be][ed] = w[be][ed] != 1e18; 
            if(w[be][ed] == 1e18) w[be][ed] = 0;
        }
    }else{
        vis[be][ed] = true;
        for(auto u:F){
            if(check(u, a, b)){
                vis[be][ed] = false;
                break;
            }
        }
        if(vis[be][ed]){
            w[be][ed] = get(a, b);
        }
    }
}
bool st[N];
void dijkstra(){
    rep(i, 0, N - 4) dist[i] = 1e18; 
	dist[0]=0;
	priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
	q.push({0,0});
	while(q.size()){
		auto t=q.top();q.pop();
		double distance=t.first;
        int now=t.second;
		if(st[now]) continue;
		st[now]=true;
        rep(i, 0, siz(all) - 1){
            if(!vis[now][i]) continue;
            if(distance+w[now][i]<dist[i]){
				dist[i]=distance+w[now][i];
				q.push({distance+w[now][i],i});
			} 
        }
	}
	cout << dist[siz(all) - 1];
}
void Solve(){
    cin >> n >> m >> R;
    rep(i, 1, n){
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        F.push_back({{x1,y2},{x2,y2},{x1,y1},{x2,y1}});
    }
    rep(i, 1, m){
        double x, y;
        cin >> x >> y;
        yuan.push_back({x, y});
    }
    cin >> sx >> sy >> ex >> ey;
    all.push_back({sx,sy});
    for(auto x:F){
        all.push_back(x.p1);
        all.push_back(x.p2);
        all.push_back(x.p3);
        all.push_back(x.p4);
    }
    for(auto x:yuan){
        all.push_back(x);
    }
    all.push_back({ex,ey});
    for(int i = 0;i < all.size();i ++){
        for(int j = i + 1; j < all.size();j ++){
            judge(i, j);
            judge(j, i);
        }
    }
    dijkstra();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    cout << SPO(9);
    
    Solve();
    return 0;
}