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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll last = -1e10;
    rep(i, 1, n){
        ll l = a[i] - k, r = a[i] + k;
        if(last <= l) last = l;
        else if(last > r){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}