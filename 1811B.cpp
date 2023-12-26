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
void Solve(){
    ll n, x, y, sx, sy;
    cin >> n >> x >> y >> sx >> sy;
    auto f = [](ll x, ll y, ll n){
        ll l = 1, r = n / 2;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(y <= n + 1 - mid && y >= mid) l = mid;
            else r = mid - 1;
        }
        ll last = r;
        l = 0, r = n / 2;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(x <= n + 1 - mid && x >= mid) l = mid;
            else r = mid - 1;
        }
        return min(last, r);
    };
    cout << abs(f(x, y, n) - f(sx, sy, n)) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}