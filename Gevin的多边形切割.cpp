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
void Solve(){
    int n; cin >> n;
    vector<pair<int,double>> a(n + 1);
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    double up = 1e18;
    rep(i, 1, n) up = min(up, a[i].second);
    auto check = [&](double h){
        double sum = 0;
        for(int i = 1;i <= n;i ++){
            auto l = a[i].second;
            if(a[i].first == 1){
                if(h <= l) sum += (l - h) * (l - h) / sqrt(3);
                if(h <= l) sum -= (2 * l - h) * h / sqrt(3);
                else sum -= l * l / sqrt(3);
            }else if(a[i].first == 2){
                if(h <= l) sum += (3 * l - h) * (l - h) / 2;
                if(h <= l) sum -= (4 * l - h) * h / 2;
                else sum -= 3 * l * l / 2;
            }else{
                if(h <= l) sum += (l - h) * l;
                if(h <= l) sum -= h * l;
                else sum -= l * l;
            }
        }
        return sum <= 0;
    };
    double l = 0, r = 1000;
    while(fabs(r - l) > 1e-7){
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << SPO(6) << r;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}