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
const int N = 2e5 + 10;
ll a[N], w[N];
void Solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) w[i] = w[i - 1] + a[i];
    ll mx = 0, now = 0;
    ll res = n;
    for(int i = 1;i <= n;i ++){
        now += w[i];
        mx = max(mx, w[i]);
        if(now < 0){
            if(mx == 0){
                cout << -1 << endl;
                return;
            }
            res += (- now + mx - 1) / mx;
            now += (- now + mx - 1) / mx * mx;
        }
    }
    if(w[n] < 0) res = -1; 
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}