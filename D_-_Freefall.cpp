/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 21:45:02
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define double long double
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    double A, B;
    cin >> A >> B;
    ll l = 1, r = 2e18;
    auto calc = [&](ll now){
        double res = A / sqrt(now) + B * (now - 1);
        return res;
    };
    while(l < r){
        ll mid = l + r >> 1;
        if(2 * B * mid * sqrt(mid) >= A) r = mid;
        else l = mid + 1;
    }
    cout << SPO(10) << calc(r) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}