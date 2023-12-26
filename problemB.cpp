#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int Dx = 1e5, N = 2e6;
const pair<double, double> Z = {0, 0};
struct Point{
    double x, y;
};
struct down{
    int t;
    double x, y;
};
Point operator - (Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}
Point operator + (Point a, Point b){
    return {a.x + b.x, a.y + b.y};
}
double operator ^ (Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
Point operator * (double b,Point a){
    return {a.x * b, a.y * b};
}
Point corss(Point a, Point b){
    Point c = {0, 0}, d = {1, 0};
    Point v1 = b - a;
    Point v2 = d - c;
    double t1 = v2 ^ (a - c);
    double t2 = v1 ^ v2;
    return a + ((t1/t2) * v1);
}

int c[N];
void Solve(){
    Point u1, u2;
    cin >> u1.x >> u1.y >> u2.x >> u2.y;
    int n;
    cin >> n;
    double mL, mR;
    mL = mR = -1e9;
    if(u1.x - u1.y > u2.x - u2.y) swap(u1, u2);
    double L1 = u1.x - u1.y, L2 = u2.x - u2.y, R1 = u1.x + u1.y, R2 = u2.x + u2.y;
    // cout << L1 << ' ' << R1 << endl;
    // cout << L2 << ' ' << R2 << endl;
    if(L1 <= L2&&L2 <= R1){
        if(R2 >= R1){
            mL = L2;
            mR = R1;
        }else{
            mL = L2;
            mR = R2;
        }
    }
    // cout << mL << ' ' << mR << endl;
    vector<pair<double,double>> S;
    double L = -1e9, R = -1e9;
    auto calc = [&](Point u, Point left, Point right) -> pair<double,double>{
        Point need = {u.x - u.y, 0}, need1 = {u.x + u.y, 0};
        double H = left.y;
        if(((need - u) ^ (left - u)) <= 0&&((need - u) ^ (right - u)) <= 0){
            return Z;
        }
        if(((need1 - u) ^ (left - u)) >= 0&&((need1 - u) ^ (right - u)) >= 0){
            return Z;
        }
        double L, R;
        if(((left - u)^(need - u))*((left - u)^(need1 - u)) <= 0){
            L = left.x;
        }else{
            L = u.x - u.y + H;
        }
        if(((right - u)^(need - u))*((right - u)^(need1 - u)) <= 0){
            R = right.x;
        }else{
            R = u.x + u.y - H;
        }
        Point l = {L, H}, r = {R, H};
        return {corss(l, u).x, corss(r, u).x};
    };
    vector<pair<double, double>> v, vv;
    auto pp = [&](pair<double, double> now){
        auto [L, R] = now;
        if(mL >= R){
            v.push_back(now);
            return;
        }
        if(mR <= L){
            v.push_back(now);
            return;
        }
        if(mL <= L && L <= mR){
            // cout << "???\n";
            vv.push_back({L, mR});
            v.push_back({mR, R});
            return;
        }
        if(mL <= R && R <= mR){
            // cout << "???\n";
            vv.push_back({mL, R});
            v.push_back({L, mL});
            return;
        }
    };
    rep(i, 1, n){
        double x0, x1, y;
        cin >> x0 >> x1 >> y;
        Point left = {x0, y}, right = {x1, y};
        auto now = calc(u1, left, right);
        if(now.first != now.second) pp(now);
        now = calc(u2, left, right);
        if(now.first != now.second) pp(now);
    }
    double sum = 0;
    L = -1e9, R = -1e9;
    // 一次的合并
    S = v;
    sort(S.begin(), S.end(),[](pair<double,double> a, pair<double,double> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    for(auto [x, y]:S){
        if(x <= R){
            R = max(R, y);
        }else{
            sum += R - L;
            L = x, R = y;
        }
    }
    ////////////////
    sum += R - L;
    cout << SPO(10) << sum << endl;
    return;
}
int main(){
    Solve();
    return 0;
}