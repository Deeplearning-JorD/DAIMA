/*
 * @Author: JorD
 * @Date: 2023-11-17 15:35:35
 * @LastEditTime: 2023-11-17 15:35:37
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
void Solve(){
    int n; cin >> n;
    double d1 = 0, d2 = 0, d3 = 0;
    rep(i, 1, n){
        string s; cin >> s;
        double p = stod(s);
        d3 = (d3 + 3 * d2 + 3 * d1 + 1) * p + d3 * (1 - p);
        d2 = (d2 + 2 * d1 + 1) * p;
        d1 = (d1 + 1) * p;
    }
    cout << SPO(1) << d3;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}