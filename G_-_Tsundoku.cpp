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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> prea(n + 1), preb(m + 1);
    vector<ll> a(n + 1), b(m + 1);
    rep(i, 1, n){
        cin >> a[i];
        prea[i] = prea[i - 1] + a[i];
    }
    rep(i, 1, m){
        cin >> b[i];
        preb[i] = preb[i - 1] + b[i];
    }
    ll res = 0;
    rep(i, 1, m){
        if(preb[i] <= k) res ++;
    }
    rep(i, 1, n){
        ll l = 0, r = m;
        if(prea[i] > k) break;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(prea[i] + preb[mid] <= k) l = mid;
            else r = mid - 1;
        }
        res = max(res, l + i);
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