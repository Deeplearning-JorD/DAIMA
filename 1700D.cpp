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
const int N = 2e6 + 10;
ll v[N];

void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> v[i];
    vector<ll> pre(n + 1);
    ll maxn = 0;
    rep(i, 1, n){
        pre[i] = pre[i - 1] + v[i];
        ll now = min(v[i], (pre[i] + i - 1) / i);
        maxn = max(maxn, now);
    }
    int t;
    cin >> t;
    //考虑整体，一个黑盒往里注水。不去考虑细节
    while(t --){
        ll x;
        cin >> x;
        if(x < maxn){
            cout << -1 << endl;
        }else{
            ll l = 1, r = n;
            while(l < r){
                ll mid = l + r >> 1;
                if(mid * x >= pre[n]) r = mid;
                else l = mid + 1;
            }
            cout << l << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}