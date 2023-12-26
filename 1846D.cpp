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
    int n;
    double d, h;
    cin >> n >> d >> h;
    double res = 0;
    double last = -1e9;
    double mb = 1.0 * d * h;
    mb /= 2.0;
    rep(i, 1, n){
        double hi; cin >> hi;
        if(hi < last + h) res -= ((last + h - hi) / h) * ((last + h - hi) / h) * mb;
        res += mb;
        last = hi;
    }
    cout << SPO(9) << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}