/*
 * @Author: JorD
 * @LastEditTime: 2023-07-20 15:09:43
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
    ll x, y;
}P[N];
ll operator ^ (Point a, Point b){
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
bool cmp(Point a, Point b){
    ll ans = (a - P[1]) ^ (b - P[1]);
    if(ans > 0) return true;
    if(ans == 0.0 && dist(P[1], a) < dist(P[1], b)) return true;
    return false;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    a.clear();
    rep(i, 1, n){
        ll x, y;
        cin >> P[i].x >> P[i].y;
        if(P[i].x < P[1].x || (P[i].x == P[1].x&&P[i].y < P[1].y)) 
            swap(P[i], P[1]);
    }
    vector<Point> ls(m);
    for(auto &[x, y] : ls) cin >> x >> y;
    sort(P + 2, P + 1 + n, cmp);
    int idx = 0;
    rep(i, 1, n){
        while(a.size() > 1&&check(*prev(a.end() - 1), a.back(), P[i])) a.pop_back();
        a.push_back(P[i]);
    }
    vector<int> l(siz(a)), r(siz(a));
    int last = siz(a) - 1;
    rep(i, 0, siz(a) - 1){
        l[i] = last;
        r[i] = (i + 1)%(siz(a));
        last = i;
    }
    rep(i, 0, siz(a) - 1){
        auto [x, y] = a[i];
        for(auto u:ls){
            if(((u - a[i])^(a[(i + 1)%(siz(a))] - a[i]))<0) continue;    
            cout << -1 << endl;
            return;
        }
    }
    int now = 0, res = siz(a);
    vector<bool> st(siz(a));
    while(!st[now]){
        Point X = a[now], Y = a[r[now]], Z = a[r[r[now]]];
        bool ff = true;
        for(auto u:ls){
            if(((u - X)^(Y - X))<=0 && ((u - Y)^(Z - Y))<=0 && ((u - Z)^(X - Z))<=0){
                ff = false;
                break;
            }
        }
        
        // cout << X.x << ' ' << X.y << ' ';
        // cout << Y.x << ' ' << Y.y << ' ';
        // cout << Z.x << ' ' << Z.y << endl;
        if(!ff){
            st[now] = 1;
            now = r[now];
            continue;
        }
        // cout << "del\n";
        l[r[r[now]]] = now;
        r[now] = r[r[now]];
        res --;
    }
    cout << res << endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}