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
    ll n, m;
    cin >> n >> m;
    ll a = 1, b = 1e7;
    while(a < b){
        ll mid = a + b >> 1;
        if(mid * mid >= m) b = mid;
        else a = mid + 1;
    }
    if(a > n){
        cout << -1 << endl;
        return;
    }
    ll res = 1e18;
    for(int i = 1;i <= a;i ++){
        ll l = 1, r = n;
        if(i * r < m) continue;
        while(l < r){
            ll mid = l + r >> 1;
            if(mid * i >= m) r = mid;
            else l = mid + 1;
        }
        res = min(res, l * i);
    }
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